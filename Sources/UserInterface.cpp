// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"

#include "iostream"

UserInterface *UI; // Initialization of object

UserInterface::UserInterface()  : wxFrame(nullptr, wxID_ANY, "MatrixViewer", wxDefaultPosition, wxSize(800, 600)){
	Canvas = new wxGLCanvas(this, wxID_ANY);

	// Creating UI Elemets
    glContext = new wxGLContext(Canvas);
    Toolbar = CreateToolBar();
    Toolbar->SetWindowStyle(wxTB_TEXT);

    // Loading icons
    wxBitmap JoinIcon(wxT("Assets/JoinIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap RefreshIcon(wxT("Assets/RefreshIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap AboutIcon(wxT("Assets/AboutIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap SettingsIcon(wxT("Assets/SettingsIcon.png"), wxBITMAP_TYPE_PNG);

    Toolbar->AddTool(BJoinServerID, "Join", JoinIcon);
    Toolbar->AddTool(BRefreshID, "Refresh", RefreshIcon);
    Toolbar->AddTool(BAboutID, "About", AboutIcon);
    Toolbar->AddTool(BSettingsID, "Settings", SettingsIcon);

    Toolbar->Realize();

    wxBoxSizer* GLSizer = new wxBoxSizer(wxVERTICAL);
    GLSizer->Add(Canvas, 1, wxEXPAND);
    SetSizer(GLSizer);

    // Binding canvas
    Canvas->Bind(wxEVT_PAINT, &UserInterface::OnRender, this);

    Timer = new wxTimer(this);
	Bind(wxEVT_TIMER, &UserInterface::OnTimer, this);
	Timer->Start(16); // ~60 FPS
    Show(true);
}

void UserInterface::OnTimer(wxTimerEvent& event) {
    Canvas->Refresh();
}

void UserInterface::OnRender(wxPaintEvent& event){
	wxPaintDC dc(Canvas);
	Canvas->SetCurrent(*glContext); // Setting current context

	// OpenGL
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Swap buffers
    Canvas->SwapBuffers();
}