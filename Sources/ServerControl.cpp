// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerControl.hpp"
#include "UserInterface.hpp"
#include "Server.hpp"
#include <fstream> 

ServerControl::ServerControl()  : wxFrame(wxWindow::FindWindowById(MainWindowID), ServerControlWindowID, "Server control", wxDefaultPosition, wxSize(400, 600)){
	LogCounter = 0; // Reseting log counter
    S = new Server();
	// Creating UI Elemets
    m_Toolbar = CreateToolBar();
    m_Log = new wxListCtrl(this, ServerListID, wxDefaultPosition, wxDefaultSize, wxLC_LIST);

    // Configuration for toolbar
    m_Toolbar->SetWindowStyle(wxTB_TEXT);

    int IconSize = 32;

    // Loading icons
    wxBitmap WriteLogIcon(wxBitmap("Assets/Icons/Text-x-generic.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));
    wxBitmap CloseServerIcon(wxBitmap("Assets/Icons/Dialog-error.png", wxBITMAP_TYPE_PNG).ConvertToImage().Scale(IconSize, IconSize, wxIMAGE_QUALITY_HIGH));

    // Adding m_Toolbar buttons
    m_Toolbar->AddTool(BWriteLogID, "Write log", WriteLogIcon);
    m_Toolbar->AddTool(BCloseServerID, "Close server", CloseServerIcon);

    S->Run(*this);

    // Binding buttons
    Bind(wxEVT_MENU, &ServerControl::OnToolClicked, this, BWriteLogID);
    Bind(wxEVT_MENU, &ServerControl::OnToolClicked, this, BCloseServerID);

    Show(true);
}

void ServerControl::OnToolClicked(wxCommandEvent& Event){
    switch (Event.GetId()){
        case BCloseServerID:
            S->Stop();
            Close(true);
            break;
        case BWriteLogID:
            WriteLN("Log have been writen in file " + S->Options.LogFileName);
            WriteLog();
    }
}

void ServerControl::WriteLog(){
    std::ofstream LogFile(S->Options.LogFileName);
    LogFile << LogString;
}

void ServerControl::WriteLN(std::string Message){
	m_Log->InsertItem(LogCounter, Message); // Writing
    LogString += Message + "\n"; // Writing to string 
	LogCounter++;
}