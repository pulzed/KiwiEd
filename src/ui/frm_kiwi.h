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

#include "../kiwied.h"

namespace Kiwi
{

class FrmKiwi : public wxFrame
{
private:
	// state variables
	wxApp* owner = nullptr;
#ifdef KIWI_DEBUG_FEATURES
	FrmLog* frmLog = nullptr;
#endif

	// menubar structure
	struct MenuBar
	{
		wxMenuBar* root;
		struct MenuFile
		{
			wxMenu* root;

			struct Members
			{
				wxMenuItem* menuNew;
				wxMenuItem* menuOpen;
				
				struct MenuOpenRecent
				{
					wxMenu* root;
					struct MEMBERS
					{
						wxMenuItem* menuNoRecentItems;
						wxMenuItem* menuRecent[10];
					} members;
				} menuOpenRecent;

				wxMenuItem* menuSave;
				wxMenuItem* menuSaveAs;
				wxMenuItem* menuSaveAll;
				wxMenuItem* menuSaveTemplate;
				wxMenuItem* menuExport;
				wxMenuItem* menuExportAs;
				wxMenuItem* menuClose;
				wxMenuItem* menuCloseAll;
				wxMenuItem* menuExit;

			} members;
		} menuFile;

		struct MenuEdit
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuUndo;
				wxMenuItem* menuRedo;
				wxMenuItem* menuCut;
				wxMenuItem* menuCopy;
				wxMenuItem* menuPaste;
				wxMenuItem* menuDelete;
				wxMenuItem* menuSelectView;
				wxMenuItem* menuSelectAll;
				wxMenuItem* menuSelectNone;
			} members;
		} menuEdit;

		struct MenuView
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuShowGrid;
			} members;
		} menuView;

		struct MenuMap
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuMapProperties;
			} members;
		} menuMap;

		struct MenuLayer
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuCreateNew;
				wxMenuItem* menuDuplicate;
				wxMenuItem* menuMerge;
				wxMenuItem* menuDelete;
				wxMenuItem* menuRaise;
				wxMenuItem* menuLower;
				wxMenuItem* menuLayerProperties;
			} members;
		} menuLayer;

		struct MenuTools
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuSettings;
			} members;
		} menuTools;

#ifdef KIWI_DEBUG_FEATURES
		struct MenuDebug
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuLogWindow;
			} members;
		} menuDebug;
#endif

		struct MenuHelp
		{
			wxMenu* root;
			struct Members
			{
				wxMenuItem* menuUserManual;
				wxMenuItem* menuCheckForUpdates;
				wxMenuItem* menuAbout;
			} members;
		} menuHelp;

	} menuBar;

	wxAuiManager auiManager;

	// menubar events
	void OnMenuFileNew(wxCommandEvent& e);
	void OnMenuFileExit(wxCommandEvent& e);
	void OnMenuLayerNewLayer(wxCommandEvent& e);
	void OnMenuToolsSettings(wxCommandEvent& e);
#ifdef KIWI_DEBUG_FEATURES
	void OnMenuDebugLogWindow(wxCommandEvent& e);
#endif
	void OnMenuHelpUserManual(wxCommandEvent& e);
	void OnMenuHelpCheckForUpdates(wxCommandEvent& e);
	void OnMenuHelpAbout(wxCommandEvent& e);

	// initialization
	void InitializeGlobalMenu();
	void InitializeToolBar();
	void InitializeStatusBar();
	void InitializeInterface();

public:
	FrmKiwi(wxApp* owner);
};

}

#endif // KIWI_FRM_KIWI_H_