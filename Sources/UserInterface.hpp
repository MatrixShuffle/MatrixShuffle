// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>

enum InterfaceStates{ // Ui interface state now
	ServerList=0,
	NameSelect,
	Player
};

enum InterfaceControls{ // Interface controls ID's
	BJoinServerID=1000,
	BRefreshID,
	BAboutID,
	BSettingsID,
	ServerListID=2000
};

// Window with interface
class UserInterface : wxFrame{
public:
	UserInterface(); // Initialization of OpenGL and widgets
private:
	InterfaceStates State; // State of interface now
    // UI Elements
    wxToolBar *Toolbar;
    wxListCtrl *ServerList;
};

extern UserInterface *UI; // Global pointer