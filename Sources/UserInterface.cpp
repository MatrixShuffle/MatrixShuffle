// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"

#include "iostream"

UserInterface *UI; // Initialization of object

UserInterface::UserInterface()  : wxFrame(nullptr, wxID_ANY, "MatrixViewer", wxDefaultPosition, wxSize(800, 600)){
	// Creating UI Elemets
    Toolbar = CreateToolBar();
    ServerList = new wxListCtrl(this, ServerListID, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    // Configuration of elements
    Toolbar->SetWindowStyle(wxTB_TEXT);
    ServerList->InsertColumn(0, "Users");
    ServerList->InsertColumn(1, "Name");
    ServerList->InsertColumn(2, "Ping");

    long ItemIndex = ServerList->InsertItem(0, "11");
    ServerList->SetItem(ItemIndex, 1, "Debugging");
	ServerList->SetItem(ItemIndex, 2, "11");

    // Loading icons
    wxBitmap JoinIcon(wxT("Assets/JoinIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap RefreshIcon(wxT("Assets/RefreshIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap AboutIcon(wxT("Assets/AboutIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap SettingsIcon(wxT("Assets/SettingsIcon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap LogoWhite(wxT("Assets/LogoWhite.png"), wxBITMAP_TYPE_PNG);
    wxStaticBitmap* BitmapWhiteLogo = new wxStaticBitmap(Toolbar, wxID_ANY, LogoWhite);

    // Adding toolbar buttons
    Toolbar->AddTool(BJoinServerID, "Join", JoinIcon);
    Toolbar->AddTool(BRefreshID, "Refresh", RefreshIcon);
    Toolbar->AddTool(BAboutID, "About", AboutIcon);
    Toolbar->AddTool(BSettingsID, "Settings", SettingsIcon);
	Toolbar->AddStretchableSpace(); // Adding space between buttons and icons

    Toolbar->AddControl(BitmapWhiteLogo);

    Toolbar->Realize();

    Show(true);
}