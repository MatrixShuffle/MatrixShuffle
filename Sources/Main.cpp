// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "UserInterface.hpp"
#include "ServerList.hpp"

class MatrixShuffle : public wxApp {
public:
    virtual bool OnInit() override {
        SL = new ServerList(); // Creating and updating server list
        SL->Update();
        UI = new UserInterface(); // Creating User Interface
        return true;              
    }
};

// Generate startpoint
wxIMPLEMENT_APP(MatrixShuffle);