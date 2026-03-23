// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <string>
#include <vector>
#include <boost/asio.hpp>

// Client configuration
struct ClientSettings{
	std::string Username;
	boost::asio::ip::address_v4 MasterServerAddr;
	bool DarkTheme;
};

// Server configuration
struct ServerSettings{
	std::string Title;
	std::string LogFileName = "MatrixShuffleLog.txt";
	int Port=5000;
	bool UseCustomVideos;
	bool ChatFilter;
	bool IsPrivate;
	std::string Password;
	std::vector<std::string> BannedWords;
	std::string CustomVideosDirectory;
	std::string GoogleAPIKey;
};