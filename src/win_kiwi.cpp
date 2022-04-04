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
//  win_kiwi.cpp
//  Main application window.
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

void WinKiwi::OnMenuOpen(wxCommandEvent& e)
{
	wxFileDialog* dlgOpenFile = new wxFileDialog(
		this,
		"Open file",
		wxEmptyString,
		wxEmptyString, 
		"Kiwi map files (*.kiw)|*.kiw|All files (*.*)|*.*",
		wxFD_OPEN,
		wxDefaultPosition
	);

	if (dlgOpenFile->ShowModal() == wxID_OK)
	{
		///dlgOpenFile->GetPath();
		///dlgOpenFile->GetFilename());
	}

	// Clean up after ourselves
	dlgOpenFile->Destroy();
}

void WinKiwi::OnMenuSave(wxCommandEvent& e)
{
}

void WinKiwi::OnMenuSaveAs(wxCommandEvent& e)
{
	wxFileDialog *dlgSaveFile = new wxFileDialog(
		this,
		"Save file",
		wxEmptyString,
		wxEmptyString,
		"Kiwi map files (*.kiw)|*.kiw|All files (*.*)|*.*",
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
		wxDefaultPosition
	);

	// Creates a Save Dialog with 4 file types
	if (dlgSaveFile->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
		///dlgSaveFile->GetPath();
		///dlgSaveFile->GetFilename());
	}

	// Clean up after ourselves
	dlgSaveFile->Destroy();
}

void WinKiwi::OnMenuExit(wxCommandEvent& e)
{
	// close window and exit application
	Close(true);
}

void WinKiwi::OnMenuSettings(wxCommandEvent& e)
{
	DlgSettings* settingsDialog = new DlgSettings(this);
	settingsDialog->CenterOnParent();
	settingsDialog->ShowModal();
}

void WinKiwi::OnMenuAbout(wxCommandEvent& e)
{
	DlgAbout* aboutDialog = new DlgAbout(this);
	aboutDialog->CenterOnParent();
	aboutDialog->ShowModal();
}

WinKiwi::WinKiwi()
: wxFrame(NULL, wxID_ANY, "KiwiEd")
{
	// set window icon
	SetIcon(wxIcon(KiwiEd_xpm));

	////////////////////////////////////////////////////////////////////////////
	//
	// create the menubar
	//
	////////////////////////////////////////////////////////////////////////////

	menuBar = new wxMenuBar();	
	SetMenuBar(menuBar);

	// file menu
	menuBar->Append((menuFile = new wxMenu()), "&File");
	menuFile->Append(menuFileNew = new wxMenuItem(menuFile, wxID_ANY, "&New...\tCtrl+N", "Create new map"));

	menuFile->AppendSeparator();

	menuFile->Append(menuFileOpen = new wxMenuItem(menuFile, wxID_ANY, "&Open...\tCtrl+O", "Open map from a file"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuOpen, this, menuFileOpen->GetId());
	
	menuFile->AppendSubMenu((menuFileOpenRecent = new wxMenu()), "Open &Recent");

	menuFile->AppendSeparator();

	menuFile->Append(menuFileSave = new wxMenuItem(menuFile, wxID_ANY, "&Save\tCtrl+S", "Save current map"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuSave, this, menuFileSave->GetId());

	menuFile->Append(menuFileSaveAs = new wxMenuItem(menuFile, wxID_ANY, "Save &As...\tCtrl+Shift+S", "Save current map as"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuSaveAs, this, menuFileSaveAs->GetId());

	menuFile->AppendSeparator();

	menuFile->Append(menuFileExport = new wxMenuItem(menuFile, wxID_ANY, "&Export\tCtrl+E", "Export current map"));
	menuFile->Append(menuFileExportAs = new wxMenuItem(menuFile, wxID_ANY, "Ex&port As...\tCtrl+Shift+E", "Export current map as"));

	menuFile->AppendSeparator();

	menuFile->Append(menuFileClose = new wxMenuItem(menuFile, wxID_ANY, "&Close\tCtrl+F4", "Close current map"));
	menuFile->Append(menuFileCloseAll = new wxMenuItem(menuFile, wxID_ANY, "&Close All\tCtrl+Shift+F4", "Close all open"));

	menuFile->AppendSeparator();
	
	menuFile->Append(menuFileExit = new wxMenuItem(menuFile, wxID_ANY, "E&xit\tAlt+F4", "Exit program"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuExit, this, menuFileExit->GetId());
	
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
	menuBar->Append((menuTools = new wxMenu()), "&Tools");
	menuTools->Append(menuToolsSettings = new wxMenuItem(menuTools, wxID_ANY, "&Settings\tF8", "Show settings dialog"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuSettings, this, menuToolsSettings->GetId());

	// help menu
	menuBar->Append((menuHelp = new wxMenu()), "&Help");
	menuHelp->Append(menuHelpContents = new wxMenuItem(menuHelp, wxID_ANY, "&Contents\tF1", "Show help contents"));
	menuHelp->Append(menuHelpCheckForUpdates = new wxMenuItem(menuHelp, wxID_ANY, "Check for &Updates", "Check online repository for updates"));

	menuHelp->AppendSeparator();

	menuHelp->Append(menuHelpAbout = new wxMenuItem(menuHelp, wxID_ANY, "&About", "Show about dialog"));
	Bind(wxEVT_MENU, &WinKiwi::OnMenuAbout, this, menuHelpAbout->GetId());

#ifdef KIWI_DEBUG_FEATURES
	// debug menu
	menuBar->Append((menuDebug = new wxMenu()), "&DEBUG");
	menuDebug->Append(menuDebugShowLog = new wxMenuItem(menuDebug, wxID_ANY, "Show &Log", "Show the log window"));
#endif
}