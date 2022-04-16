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
//  frm_kiwi.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "frm_log.h"

inline void FrmLog::InitializeGlobalMenu()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the menubar
	//
	////////////////////////////////////////////////////////////////////////////

	menuBar = new wxMenuBar();
	SetMenuBar(menuBar);

	// log menu
	menuBar->Append((menuLog = new wxMenu()), "&Log");
	
	menuLog->Append(new wxMenuItem(menuLog, wxID_ANY, "&Clear", "Clear log."));
	menuLog->Append(new wxMenuItem(menuLog, wxID_ANY, "&Save\tCtrl+S", "Save log to a file."));

	// view menu
	menuBar->Append((menuView = new wxMenu()), "&View");

	menuView->Append(new wxMenuItem(menuView, wxID_ANY, "Always on &Top\tCtrl+T", "Makes this window always on top."));

}

FrmLog::FrmLog()
: wxFrame(NULL, wxID_ANY, "Debug log")
{
	// frame setup
	SetMinSize(FromDIP(wxSize(100, 100))); // set minimum frame size
	//SetIcon(wxIcon(KiwiEd_xpm)); // set window icon
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));

	// initialize components
	InitializeGlobalMenu();
}