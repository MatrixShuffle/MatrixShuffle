// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.
#include "UserInterface.hpp"

class MatrixViewer : public wxApp {
public:
    virtual bool OnInit() override {
        UI = new UserInterface(); // Creating window
        return true;              
    }
};

// Generate startpoint
wxIMPLEMENT_APP(MatrixViewer);