// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/glcanvas.h>

enum InterfaceStates{
	ServerList=0,
	NameSelect,
	Player
};

// Window with interface
class UserInterface : wxFrame{
public:
	UserInterface(); // Initialization of OpenGL and widgets
private:
	void OnRender(wxPaintEvent& event); // Rendering window
	void OnTimer(wxTimerEvent& event); // Calling render function
	InterfaceStates State; // State of interface now
    wxGLCanvas *canvas;
    wxGLContext *glContext;
    wxTimer *timer;
};

extern UserInterface *UI; // Global pointer