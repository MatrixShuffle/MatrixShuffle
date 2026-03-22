// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerContructor.hpp"
#include "UserInterface.hpp"

ServerConstructor::ServerConstructor()  : wxDialog(wxWindow::FindWindowById(MainWindowID), ServerConstructorID, "Server constructor", wxDefaultPosition, wxSize(200, 400)){
	Show(true);
}