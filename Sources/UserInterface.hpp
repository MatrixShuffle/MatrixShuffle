// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/file.h>
#include <string>

enum InterfaceStates{ // Ui interface state now
	SServerList=0,
	SNameSelect,
	SPlayer
};

enum InterfaceControls{ // Interface controls ID's
	MainWindowID=100,
	ServerConstructorID,
	BJoinServerID=1000,
	BRefreshID,
	BAboutID,
	BSettingsID,
	BCreateServerID,
	ServerListID=2000
};

// Window with interface
class UserInterface : wxFrame{
public:
	UserInterface(); // Initialization of widgets and UI
	virtual void OnToolClicked(wxCommandEvent& Event); // Event handler
	void LoadServers(); // Load servers from master server
private:
	InterfaceStates State; // State of interface now
    // UI Elements
    wxToolBar *m_Toolbar;
    wxStatusBar *m_Statusbar;
    wxListCtrl *m_ServerList;
};

extern UserInterface *UI; // Global pointer