// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "Server.hpp"

Server::Server(){
    AsioContext.run();
}

void Server::Run(){
	// Rendering cool banner into console
	ControlUI->WriteLN("|*----------------------------*|");
	ControlUI->WriteLN("|*       MATRIX SHUFFLE       *| ");
	ControlUI->WriteLN("|*           Server           *| ");
	ControlUI->WriteLN("|*----------------------------*|");
	// Creating TCP acceptor
	boost::asio::ip::tcp::acceptor acceptor_(this->AsioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), Options.Port));
	ControlUI->WriteLN("Server have been started on port " + std::to_string(Options.Port));
	ControlUI->WriteLN("--------------------------------");
	ControlUI->WriteLN("Title: " + Options.Title);
}