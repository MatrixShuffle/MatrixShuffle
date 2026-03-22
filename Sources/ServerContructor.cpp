// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerContructor.hpp"
#include "ServerControl.hpp"
#include "UserInterface.hpp"
#include "Server.hpp"

ServerConstructor::ServerConstructor()  : wxDialog(wxWindow::FindWindowById(MainWindowID), ServerConstructorID, "Server constructor", wxDefaultPosition, wxSize(200, 400)){
	Show(true);

	ServerControl *m_SControl = new ServerControl();
	Server m_Server;
	m_Server.ControlUI = m_SControl;
	m_Server.Run();
}