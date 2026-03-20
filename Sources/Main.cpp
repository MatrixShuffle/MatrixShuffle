// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include <wx/cmdline.h>

#include "UserInterface.hpp"
#include "ServerList.hpp"
#include "MasterServer.hpp"
#include "ServerContructor.hpp"

class MatrixShuffle : public wxApp {
public:
    virtual bool OnInit() override {
    	wxCmdLineParser parser(argc, argv);

    	parser.AddSwitch("m", "master-server", "Open master server");

    	parser.Parse(); // Parsing window arguments

    	long MasterServerPort = 5000;
    	if (parser.Found("master-server")){ // Buggy
			MS = new MasterServer();
			MS->Run(MasterServerPort);
		}
		else{
			SL = new ServerList(); // Creating and updating server list
        	SL->Update();
        	UI = new UserInterface(); // Creating User Interface
            SC = new ServerConstructor();
		}
        return true;              
    }
};

// Generate startpoint
wxIMPLEMENT_APP(MatrixShuffle);