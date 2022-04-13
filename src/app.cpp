////////////////////////////////////////////////////////////////////////////////
//   _____             _____    __ 
//  |  |  |__ _ _ _ __|   __|__|  |  2D map editor
//  |    -,  | | | |  |   __|  _  |  version 0.0.2
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
//
////////////////////////////////////////////////////////////////////////////////

#include "app.h"

wxIMPLEMENT_APP(KiwiApp); // implement wx application

bool KiwiApp::OnInit()
{
	// <TODO> fetch config

	// display main window
	FrmKiwi* window = new FrmKiwi();
	window->SetSize(window->FromDIP(wxSize(800, 600)));
	window->CenterOnScreen();
	window->Show(true);
	return true;
}
