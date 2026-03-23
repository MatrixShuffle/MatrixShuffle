// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <boost/asio.hpp>
#include "Settings.hpp"

class ServerControl;

class Server{
public:
	Server();
	void Run(ServerControl& ControlUI);
	void Stop();
	ServerSettings Options;
private:
	boost::asio::io_context AsioContext; // Boost.asio context
	boost::asio::ip::tcp::acceptor *AsioAcceptor; // Boost.asio acceptor
};