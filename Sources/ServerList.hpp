// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <vector>

#include "Protocol.hpp"

class ServerList{
public:
	ServerList() = default; // Just clean serverlist
	void Update(); // Getting servers from master server
	MSServerData GetServerByID(int ID); // Get server data object using ID
	int ServersSize(){return Servers.size();};
private:
	std::vector<MSServerData> Servers;
};

extern ServerList *SL; // Server list global pointer