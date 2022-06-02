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

#include "../kiwied.h"
#include "frm_log.h"

// -- xpm resources --
#include "../res/xpm/KiwiEd.xpm"

namespace Kiwi
{

inline void FrmLog::InitializeGlobalMenu()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the menubar
	//
	////////////////////////////////////////////////////////////////////////////

	menuBar.root = new wxMenuBar();
	SetMenuBar(menuBar.root);

	//
	// Log menu
	//
	auto& menuLog = menuBar.menuLog;
	menuBar.root->Append((menuLog.root = new wxMenu()), "&Log");
	{
		auto& menuClear = menuLog.members.menuClear;
		menuClear = new wxMenuItem(menuLog.root, wxID_ANY, "C&lear\tCtrl+L", "Clear log");
		menuLog.root->Append(menuClear);

		auto& menuSaveAs = menuLog.members.menuSaveAs;
		menuSaveAs = new wxMenuItem(menuLog.root, wxID_ANY, "Save &As\tCtrl+Shift+S", "Save log to file");
		menuLog.root->Append(menuSaveAs);
	}
}

void FrmLog::InitializeStatusBar()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the statusbar
	//
	////////////////////////////////////////////////////////////////////////////

	this->CreateStatusBar(1, wxSTB_SIZEGRIP);
}

FrmLog::FrmLog(wxWindow* parent)
: wxFrame(parent, wxID_ANY, "Debug Log", wxDefaultPosition, wxDefaultSize, wxSYSTEM_MENU | wxRESIZE_BORDER | wxCLOSE_BOX | wxCAPTION | wxFRAME_NO_TASKBAR | wxCLIP_CHILDREN | wxFRAME_FLOAT_ON_PARENT)
{
	// frame setup
	SetMinSize(FromDIP(wxSize(100, 100))); // set minimum frame size
	SetIcon(wxIcon(KiwiEd_xpm)); // set window icon
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));

	// initialize components
	InitializeGlobalMenu();
}

}