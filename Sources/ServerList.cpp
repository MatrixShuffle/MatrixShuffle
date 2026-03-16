// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerList.hpp"

ServerList *SL = nullptr;

void ServerList::Update(){
	Servers.clear(); // For first we cleanup array
	// Servers for debug
	for (int i = 0; i < 10; i++){
		MSServerData Object;
		Object.Ping = 1;
		Object.Name = "This is simple server to debug";
		Object.Online = 10;
		Servers.push_back(Object);
	}
}

MSServerData ServerList::GetServerByID(int ID){
	return Servers[ID];
}