// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <boost/asio.hpp>
#include "ServerControl.hpp"
#include "Settings.hpp"

class Server{
public:
	Server();
	void Run();
	ServerSettings Options;
	ServerControl *ControlUI;
private:
	boost::asio::io_context AsioContext; // Boost.asio context
};