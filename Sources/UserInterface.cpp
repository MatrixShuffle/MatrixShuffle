// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"

#include "iostream"

UserInterface *UI; // Initialization of object

UserInterface::UserInterface()  : wxFrame(nullptr, wxID_ANY, "MatrixViewer", wxDefaultPosition, wxSize(800, 600)){
	canvas = new wxGLCanvas(this, wxID_ANY);

	// Making context
    glContext = new wxGLContext(canvas);

    canvas->Bind(wxEVT_PAINT, &UserInterface::OnRender, this);

    timer = new wxTimer(this);
	Bind(wxEVT_TIMER, &UserInterface::OnTimer, this);
	timer->Start(16); // ~60 FPS
    Show(true);
}

void UserInterface::OnTimer(wxTimerEvent& event) {
    canvas->Refresh();
}

void UserInterface::OnRender(wxPaintEvent& event){
	wxPaintDC dc(canvas);
	canvas->SetCurrent(*glContext);

	// OpenGL
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Swap buffers
    canvas->SwapBuffers();
}