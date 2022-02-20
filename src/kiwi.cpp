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
#include "wx/gtk/menu.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

void KiwiWindow::OnMenuExit(wxCommandEvent& e)
{
}

void KiwiWindow::OnMenuAbout(wxCommandEvent& e)
{
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

	menuFile->Append(menuFileOpen = new wxMenuItem(menuFile, wxID_ANY, "&Open...\tCtrl+O", "Open map from a file"));
	
	menuFile->Append(menuFileSave = new wxMenuItem(menuFile, wxID_ANY, "&Save\tCtrl+S", "Save current map"));
	
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
	menuHelp = new wxMenu();
	menuBar->Append(menuHelp, "&Help");
}