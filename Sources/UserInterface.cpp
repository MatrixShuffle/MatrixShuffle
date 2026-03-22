// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"
#include "ServerContructor.hpp"
#include "ServerList.hpp"
#include <string>

UserInterface *UI = nullptr; // Initialization of object

UserInterface::UserInterface()  : wxFrame(nullptr, MainWindowID, "MatrixShuffle", wxDefaultPosition, wxSize(800, 600)){
	// Creating UI Elemets
    m_Toolbar = CreateToolBar();
    m_ServerList = new wxListCtrl(this, ServerListID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    m_Statusbar = CreateStatusBar();

    // Configuration of elements
    m_Toolbar->SetWindowStyle(wxTB_TEXT);
    m_ServerList->InsertColumn(0, "Online");
    m_ServerList->InsertColumn(1, "Name");
    m_ServerList->InsertColumn(2, "Ping");

    int TotalOnline=0;

    for (int i = 0; i < SL->ServersSize(); i++){
    	int Row = m_ServerList->InsertItem(i, std::to_string(SL->GetServerByID(i).Online));
    	m_ServerList->SetItem(Row, 1, SL->GetServerByID(i).Name);
		m_ServerList->SetItem(Row, 2, std::to_string(SL->GetServerByID(i).Ping));
		TotalOnline+=SL->GetServerByID(i).Online;
    }

    // Setting status bar text
    m_Statusbar->SetStatusText("Loaded " + std::to_string(SL->ServersSize()) + " servers with " + std::to_string(TotalOnline) + " online");

    int IconSize = 32;

    // Loading icons
    wxBitmap JoinIcon(wxBitmap("Assets/Icons/Go-jump.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap RefreshIcon(wxBitmap("Assets/Icons/View-refresh.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap AboutIcon(wxBitmap("Assets/Icons/Help-browser.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap SettingsIcon(wxBitmap("Assets/Icons/Emblem-system.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap CreateServerIcon(wxBitmap("Assets/Icons/Network-idle.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap LogoWhite(wxT("Assets/LogoWhite.png"), wxBITMAP_TYPE_PNG);
    wxStaticBitmap* BitmapWhiteLogo = new wxStaticBitmap(m_Toolbar, wxID_ANY, LogoWhite);

    // Adding m_Toolbar buttons
    m_Toolbar->AddTool(BJoinServerID, "Join", JoinIcon);
    m_Toolbar->AddTool(BRefreshID, "Refresh", RefreshIcon);
    m_Toolbar->AddTool(BAboutID, "About", AboutIcon);
    m_Toolbar->AddTool(BSettingsID, "Settings", SettingsIcon);
    m_Toolbar->AddTool(BCreateServerID, "Create server", CreateServerIcon);
	m_Toolbar->AddStretchableSpace(); // Adding space between buttons and icons

    m_Toolbar->AddControl(BitmapWhiteLogo);

    m_Toolbar->Realize();

    // Binding buttons
    Bind(wxEVT_MENU, &UserInterface::OnToolClicked, this, BCreateServerID);

    Show(true);
}

void UserInterface::OnToolClicked(wxCommandEvent& Event){
    switch (Event.GetId()){
        case BCreateServerID:
            ServerConstructor *SC; // Creating pointer
            SC = new ServerConstructor(); // Creating form 
            break;
    }
}