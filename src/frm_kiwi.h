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
//  frm_kiwi.h
//  Main application window.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_FRM_KIWI_H_
#define KIWI_FRM_KIWI_H_

#include "kiwied.h"

class FrmKiwi : public wxFrame
{
private:
	// menubar structure
	struct MENUBAR
	{
		wxMenuBar* root;
		struct MENU_FILE
		{
			wxMenu* root;
			struct MEMBERS
			{
				wxMenuItem* menuNew;
			} members;
		} menuFile;

		struct MENU_HELP
		{
			wxMenu* root;
			struct MEMBERS
			{
				wxMenuItem* menuAbout;
			} members;
		} menuHelp;
	} menuBar;

	// menubar events
	void OnMenuAbout(wxCommandEvent& e);

	// initialization
	void InitializeGlobalMenu();
/*
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
#ifdef KIWI_DEBUG_FEATURES
	wxMenu* menuDebug;
#endif

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

	// (submenu) open recent menu items
	wxMenuItem* menuFileOpenRecentNoRecentItems;

	// layer menu items
	wxMenuItem* menuLayerNew;

	// tools menu items
	wxMenuItem* menuToolsSettings;

	// help menu items
	wxMenuItem* menuHelpUserManual;
	wxMenuItem* menuHelpCheckForUpdates;
	wxMenuItem* menuHelpAbout;

#ifdef KIWI_DEBUG_FEATURES
	// debug menu items
	wxMenuItem* menuDebugShowLogWindow;
#endif

	// main window components
	

	// menu events
	void OnMenuNewMap(wxCommandEvent& e);

	void OnMenuOpen(wxCommandEvent& e);
	void OnMenuSave(wxCommandEvent& e);
	void OnMenuSaveAs(wxCommandEvent& e);

	void OnMenuExit(wxCommandEvent& e);

	void OnMenuNewLayer(wxCommandEvent& e);

	void OnMenuSettings(wxCommandEvent& e);

	void OnMenuAbout(wxCommandEvent& e);

#ifdef KIWI_DEBUG_FEATURES
	// debug menu events
	void OnMenuShowLogWindow(wxCommandEvent& e);
#endif

	// component initialization functions
	void InitializeGlobalMenu();
	void InitializeStatusBar();
	*/

public:
	FrmKiwi();
};

#endif // KIWI_FRM_KIWI_H_