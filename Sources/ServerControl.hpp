// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <string>

class Server;

class ServerControl : wxFrame{
public:
	ServerControl();
	virtual void OnToolClicked(wxCommandEvent& Event); // Event handler
	void WriteLN(std::string Message); // Writing message into log
	void WriteLog(); // Writing log into file
	std::string LogPath;
private:
    // UI Elements
    Server *S;
    wxToolBar *m_Toolbar;
    wxListCtrl *m_Log;
    long LogCounter;
};