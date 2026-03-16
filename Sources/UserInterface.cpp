// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"
#include "ServerList.hpp"
#include <string>

UserInterface *UI = nullptr; // Initialization of object

UserInterface::UserInterface()  : wxFrame(nullptr, wxID_ANY, "MatrixViewer", wxDefaultPosition, wxSize(800, 600)){
	// Creating UI Elemets
    m_Toolbar = CreateToolBar();
    m_ServerList = new wxListCtrl(this, ServerListID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    // Configuration of elements
    m_Toolbar->SetWindowStyle(wxTB_TEXT);
    m_ServerList->InsertColumn(0, "Users");
    m_ServerList->InsertColumn(1, "Name");
    m_ServerList->InsertColumn(2, "Ping");

    for (int i = 0; i < SL->ServersSize(); i++){
    	int Row = m_ServerList->InsertItem(i, std::to_string(SL->GetServerByID(i).Online));
    	m_ServerList->SetItem(Row, 1, SL->GetServerByID(i).Name);
		m_ServerList->SetItem(Row, 2, std::to_string(SL->GetServerByID(i).Ping));
    }

    // Loading icons
    wxBitmap JoinIcon(wxT("Assets/JoinIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap RefreshIcon(wxT("Assets/RefreshIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap AboutIcon(wxT("Assets/AboutIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap SettingsIcon(wxT("Assets/SettingsIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap LogoWhite(wxT("Assets/LogoWhite.png"), wxBITMAP_TYPE_PNG);
    wxStaticBitmap* BitmapWhiteLogo = new wxStaticBitmap(m_Toolbar, wxID_ANY, LogoWhite);

    // Adding m_Toolbar buttons
    m_Toolbar->AddTool(BJoinServerID, "Join", JoinIcon);
    m_Toolbar->AddTool(BRefreshID, "Refresh", RefreshIcon);
    m_Toolbar->AddTool(BAboutID, "About", AboutIcon);
    m_Toolbar->AddTool(BSettingsID, "Settings", SettingsIcon);
	m_Toolbar->AddStretchableSpace(); // Adding space between buttons and icons

    m_Toolbar->AddControl(BitmapWhiteLogo);

    m_Toolbar->Realize();

    Show(true);
}