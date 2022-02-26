////////////////////////////////////////////////////////////////////////////////
//   _____             _____    __ 
//  |  |  |__ _ _ _ __|   __|__|  |  2D map editor
//  |    -,  | | | |  |   __|  _  |  version 0.0.1 dev
//  |__|__|__|_____|__|_____|_____|  https://github.com/pulzed/KiwiEd
//
//  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
//  Copyright (c) 2022 Danijel Durakovic
//
//  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_WIN_KIWI_H_
#define KIWI_WIN_KIWI_H_

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

class WinKiwi : public wxFrame
{
private:
	// top level menubar
	wxMenuBar* menuBar;

	// top level menubar menus
	wxMenu* menuFile;
	wxMenu* menuEdit;
	wxMenu* menuView;
	wxMenu* menuMap;
	wxMenu* menuLayer;
	wxMenu* menuTools;
	wxMenu* menuHelp;

	// file menu items
	wxMenuItem* menuFileNew;
	wxMenuItem* menuFileOpen;
	wxMenu* menuFileOpenRecent;
	wxMenuItem* menuFileSave;
	wxMenuItem* menuFileSaveAs;
	wxMenuItem* menuFileSaveTemplate;
	wxMenuItem* menuFileExport;
	wxMenuItem* menuFileExportAs;
	wxMenuItem* menuFileClose;
	wxMenuItem* menuFileCloseAll;
	wxMenuItem* menuFileExit;

	// tools menu items
	wxMenuItem* menuToolsSettings;

	// help menu items
	wxMenuItem* menuHelpContents;
	wxMenuItem* menuHelpCheckForUpdates;
	wxMenuItem* menuHelpAbout;

	// menu events
	void OnMenuExit(wxCommandEvent& e);
	void OnMenuAbout(wxCommandEvent& e);

	void OnMenuSettings(wxCommandEvent& e);

public:
	WinKiwi();
};

#endif // KIWI_WIN_KIWI_H_