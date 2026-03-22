// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerControl.hpp"
#include "UserInterface.hpp"

ServerControl::ServerControl()  : wxFrame(wxWindow::FindWindowById(MainWindowID), ServerControlWindowID, "Server control", wxDefaultPosition, wxSize(400, 600)){
	LogCounter = 0; // Reseting log counter
	// Creating UI Elemets
    m_Toolbar = CreateToolBar();
    m_Log = new wxListCtrl(this, ServerListID, wxDefaultPosition, wxDefaultSize, wxLC_LIST);

    // Configuration for toolbar
    m_Toolbar->SetWindowStyle(wxTB_TEXT);

    int IconSize = 32;

    // Loading icons
    wxBitmap CloseServerIcon(wxBitmap("Assets/Icons/Dialog-error.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));

    // Adding m_Toolbar buttons
    m_Toolbar->AddTool(BCloseServerID, "Close server", CloseServerIcon);
    Show(true);
}

void ServerControl::WriteLN(std::string Message){
	m_Log->InsertItem(LogCounter, Message); // Writing
	LogCounter++;
}