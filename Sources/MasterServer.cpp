// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include <iostream>

#include "MasterServer.hpp"

MasterServer *MS;

MasterServer::MasterServer(){
    AsioContext.run();
}

void MasterServer::Run(int Port){
	boost::asio::ip::tcp::acceptor acceptor_(this->AsioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), Port));
	std::cout << "Masterserver listening on port " << Port << std::endl;
}