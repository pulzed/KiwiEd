////////////////////////////////////////////////////////////////////////////////
//   _____             _____    __ 
//  |  |  |__ _ _ _ __|   __|__|  |  2D map editor
//  |    -,  | | | |  |   __|  _  |  version 0.0.1
//  |__|__|__|_____|__|_____|_____|  https://github.com/pulzed/KiwiEd
//
//  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
//  Copyright (c) 2022 Danijel Durakovic
//
//  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
//
////////////////////////////////////////////////////////////////////////////////
//
//  app.cpp
//  Main application window and program entry point.
//
////////////////////////////////////////////////////////////////////////////////

#include "app.h"
#include "kiwi.h"

wxIMPLEMENT_APP(KiwiEdApp); // implement wx application

bool KiwiEdApp::OnInit()
{
	// display main frame
	KiwiWindow* frame = new KiwiWindow();
	frame->SetSize(frame->FromDIP(wxSize(640, 480)));
	frame->CenterOnScreen();
	frame->Show(true);
	return true;
}
