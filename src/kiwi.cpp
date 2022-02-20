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
//  kiwi.cpp
//  Main application window.
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwi.h"
#include "about.h"
#include "wx/gtk/menu.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

void KiwiWindow::OnMenuExit(wxCommandEvent& e)
{
	Close(true);
}

void KiwiWindow::OnMenuAbout(wxCommandEvent& e)
{
	KiwiAboutDialog* aboutDialog = new KiwiAboutDialog(this);
	aboutDialog->CenterOnParent();
	aboutDialog->ShowModal();
}

KiwiWindow::KiwiWindow()
: wxFrame(NULL, wxID_ANY, "KiwiEd")
{
	// set window icon
	SetIcon(wxIcon(KiwiEd_xpm));

	////////////////////////////////////////////////////////////////////////////
	// create the menubar
	////////////////////////////////////////////////////////////////////////////

	menuBar = new wxMenuBar();	
	SetMenuBar(menuBar);

	// file menu
	menuBar->Append((menuFile = new wxMenu()), "&File");
	menuFile->Append(menuFileNew = new wxMenuItem(menuFile, wxID_ANY, "&New...\tCtrl+N", "Create new map"));
	menuFile->AppendSeparator();
	menuFile->Append(menuFileOpen = new wxMenuItem(menuFile, wxID_ANY, "&Open...\tCtrl+O", "Open map from a file"));
	menuFile->AppendSubMenu((menuFileOpenRecent = new wxMenu()), "Open &Recent");
	menuFile->AppendSeparator();
	menuFile->Append(menuFileSave = new wxMenuItem(menuFile, wxID_ANY, "&Save\tCtrl+S", "Save current map"));
	menuFile->Append(menuFileSaveAs = new wxMenuItem(menuFile, wxID_ANY, "Save &As...\tCtrl+Shift+S", "Save current map as"));
	menuFile->AppendSeparator();
	menuFile->Append(menuFileExport = new wxMenuItem(menuFile, wxID_ANY, "&Export\tCtrl+E", "Export current map"));
	menuFile->Append(menuFileExportAs = new wxMenuItem(menuFile, wxID_ANY, "Ex&port As...\tCtrl+E", "Export current map as"));
	menuFile->AppendSeparator();
	menuFile->Append(menuFileClose = new wxMenuItem(menuFile, wxID_ANY, "&Close\tCtrl+F4", "Close current map"));
	menuFile->Append(menuFileCloseAll = new wxMenuItem(menuFile, wxID_ANY, "&Close All\tShift+Ctrl+F4", "Close all open"));
	menuFile->AppendSeparator();
	menuFile->Append(menuFileExit = new wxMenuItem(menuFile, wxID_ANY, "E&xit\tAlt+F4", "Exit program"));
	
	// edit menu
	menuEdit = new wxMenu();
	menuBar->Append(menuEdit, "&Edit");

	// view menu
	menuView = new wxMenu();
	menuBar->Append(menuView, "&View");

	// map menu
	menuMap = new wxMenu();
	menuBar->Append(menuMap, "&Map");

	// layer menu
	menuLayer = new wxMenu();
	menuBar->Append(menuLayer, "&Layer");

	// tools menu
	menuTools = new wxMenu();
	menuBar->Append(menuTools, "&Tools");
	
	// help menu
	menuBar->Append((menuHelp = new wxMenu()), "&Help");
	menuHelp->Append(menuHelpContents = new wxMenuItem(menuHelp, wxID_ANY, "&Contents\tF1", "Show help contents"));
	menuHelp->Append(menuHelpCheckForUpdates = new wxMenuItem(menuHelp, wxID_ANY, "Check for &Updates", "Check online repository for updates"));
	menuHelp->AppendSeparator();
	menuHelp->Append(menuHelpAbout = new wxMenuItem(menuHelp, wxID_ANY, "&About", "Show about dialog"));
	//menuHelp->Bind(wxEVT_MENU, &KiwiWindow::OnMenuAbout);
	Bind(wxEVT_MENU, &KiwiWindow::OnMenuAbout, this, menuHelpAbout->GetId());
}