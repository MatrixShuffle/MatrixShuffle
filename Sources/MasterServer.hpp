// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <boost/asio.hpp>
#include <vector>

#include "Protocol.hpp"

class MasterServer{
public:
	MasterServer(); // Initialization of boost.asio
	void Run(int Port); // Starting server on port
private:
	std::vector<MSServerData> Servers; // Servers
	boost::asio::io_context AsioContext; // Boost.asio context
    //boost::asio::ip::tcp::socket Socket; // Boost.asio Socket
};

extern MasterServer *MS; // Global pointer