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
#include "frm_kiwi.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"
#include "../res/icons/actions/new.xpm"
#include "../res/icons/actions/open.xpm"

void FrmKiwi::OnMenuOpen(wxCommandEvent& e)
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

void FrmKiwi::OnMenuSave(wxCommandEvent& e)
{
}

void FrmKiwi::OnMenuSaveAs(wxCommandEvent& e)
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

void FrmKiwi::OnMenuExit(wxCommandEvent& e)
{
	// close window and exit application
	Close(true);
}

void FrmKiwi::OnMenuSettings(wxCommandEvent& e)
{
	DlgSettings* settingsDialog = new DlgSettings(this);
	settingsDialog->CenterOnParent();
	settingsDialog->ShowModal();
}

void FrmKiwi::OnMenuAbout(wxCommandEvent& e)
{
	DlgAbout* aboutDialog = new DlgAbout(this);
	aboutDialog->CenterOnParent();
	aboutDialog->ShowModal();
}

inline void FrmKiwi :: InitializeGlobalMenu()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the menubar
	//
	////////////////////////////////////////////////////////////////////////////

	menuBar = new wxMenuBar();
	SetMenuBar(menuBar);

	// file menu
	menuBar->Append((menuFile = new wxMenu()), "&File");
	//menuFile->Append(menuFileNew = new wxMenuItem(menuFile, wxID_ANY, "&New...\tCtrl+N", "Create new map"));



	//test/////////
	const wxSize iconSize = FromDIP(wxSize(16, 16));
	wxImage iconNew(new_xpm);

	wxBitmap bmptTestIcon(iconNew.Scale(iconSize.GetWidth(), iconSize.GetHeight(), wxIMAGE_QUALITY_HIGH));


	menuFileNew = new wxMenuItem(menuFile, wxID_ANY, "&New...\tCtrl+N", "Create new map");
	menuFileNew->SetBitmap(bmptTestIcon);
	menuFile->Append(menuFileNew);

	//test/////////

	menuFile->AppendSeparator();

	/////menuFile->Append(menuFileOpen = new wxMenuItem(menuFile, wxID_ANY, "&Open...\tCtrl+O", "Open map from a file"));
	/////Bind(wxEVT_MENU, &FrmKiwi::OnMenuOpen, this, menuFileOpen->GetId());

	//test/////////

	wxImage iconOpen(open_xpm);

	wxBitmap bmptTestIcon2(iconOpen.Scale(iconSize.GetWidth(), iconSize.GetHeight(), wxIMAGE_QUALITY_HIGH));


	menuFileOpen = new wxMenuItem(menuFile, wxID_ANY, "&Open...\tCtrl+O", "Open map from a file");
	menuFileOpen->SetBitmap(bmptTestIcon2);
	menuFile->Append(menuFileOpen);

	//test/////////

	menuFile->AppendSubMenu((menuFileOpenRecent = new wxMenu()), "Open &Recent");

	menuFile->AppendSeparator();

	menuFile->Append(menuFileSave = new wxMenuItem(menuFile, wxID_ANY, "&Save\tCtrl+S", "Save current map"));
	Bind(wxEVT_MENU, &FrmKiwi::OnMenuSave, this, menuFileSave->GetId());

	menuFile->Append(menuFileSaveAs = new wxMenuItem(menuFile, wxID_ANY, "Save &As...\tCtrl+Shift+S", "Save current map as"));
	Bind(wxEVT_MENU, &FrmKiwi::OnMenuSaveAs, this, menuFileSaveAs->GetId());

	menuFile->AppendSeparator();

	menuFile->Append(menuFileSaveTemplate = new wxMenuItem(menuFile, wxID_ANY, "Save &Template...", "Save current map as a template"));

	menuFile->AppendSeparator();

	menuFile->Append(menuFileExport = new wxMenuItem(menuFile, wxID_ANY, "&Export\tCtrl+E", "Export current map"));
	menuFile->Append(menuFileExportAs = new wxMenuItem(menuFile, wxID_ANY, "Ex&port As...\tCtrl+Shift+E", "Export current map as"));

	menuFile->AppendSeparator();

	menuFile->Append(menuFileClose = new wxMenuItem(menuFile, wxID_ANY, "&Close\tCtrl+F4", "Close current map"));
	menuFile->Append(menuFileCloseAll = new wxMenuItem(menuFile, wxID_ANY, "&Close All\tCtrl+Shift+F4", "Close all open"));

	menuFile->AppendSeparator();

	menuFile->Append(menuFileExit = new wxMenuItem(menuFile, wxID_ANY, "E&xit\tAlt+F4", "Exit program"));
	Bind(wxEVT_MENU, &FrmKiwi::OnMenuExit, this, menuFileExit->GetId());

	// (submenu) open recent file submenu
	menuFileOpenRecent->Append(menuFileOpenRecentNoRecentItems = new wxMenuItem(menuFile, wxID_ANY, "(no recent items)"));
	menuFileOpenRecentNoRecentItems->Enable(false);

	// edit menu
	menuEdit = new wxMenu();
	menuBar->Append(menuEdit, "&Edit");

	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "&Undo\tCtrl+Z", "Undo last action"));
	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "&Redo\tCtrl+Y", "Redo last action"));

	menuEdit->AppendSeparator();

	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "Cu&t\tCtrl+X", "Cut selection"));
	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "&Copy\tCtrl+C", "Copy selection"));
	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "&Paste\tCtrl+V", "Paste from clipboard"));
	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "&Delete\tDel", "Delete selection"));

	menuEdit->AppendSeparator();

	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "Select &All\tCtrl+A", "Select everything in view"));
	menuEdit->Append(new wxMenuItem(menuEdit, wxID_ANY, "Select &None\tEsc", "Cancel selection"));

	// view menu
	menuView = new wxMenu();
	menuBar->Append(menuView, "&View");

	// map menu
	menuMap = new wxMenu();
	menuBar->Append(menuMap, "&Map");

	// layer menu
	menuLayer = new wxMenu();
	menuBar->Append(menuLayer, "&Layer");

	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Create New...\tCtrl+Shift+N", "Create a new layer"));
	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Duplicate\tCtrl+Shift+D", "Duplicate current layer"));
	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Merge...\tCtrl+Shift+M", "Merge this layer with another"));
	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "Dele&te", "Delete current layer"));

	menuLayer->AppendSeparator();

	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Raise\tCtrl+PgUp", "Raises layer to one level above current"));
	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Lower\tCtrl+PgDn", "Lowers layer to one level below current"));

	menuLayer->AppendSeparator();

	menuLayer->Append(new wxMenuItem(menuLayer, wxID_ANY, "&Properties...\tF7", "Display layer properties"));

	// tools menu
	menuBar->Append((menuTools = new wxMenu()), "&Tools");
	menuTools->Append(menuToolsSettings = new wxMenuItem(menuTools, wxID_ANY, "&Settings\tF8", "Show settings dialog"));
	Bind(wxEVT_MENU, &FrmKiwi::OnMenuSettings, this, menuToolsSettings->GetId());

	// help menu
	menuBar->Append((menuHelp = new wxMenu()), "&Help");
	menuHelp->Append(menuHelpContents = new wxMenuItem(menuHelp, wxID_ANY, "&Contents\tF1", "Show help contents"));
	menuHelp->Append(menuHelpCheckForUpdates = new wxMenuItem(menuHelp, wxID_ANY, "Check for &Updates", "Check online repository for updates"));

	menuHelp->AppendSeparator();

	menuHelp->Append(menuHelpAbout = new wxMenuItem(menuHelp, wxID_ANY, "&About", "Show about dialog"));
	Bind(wxEVT_MENU, &FrmKiwi::OnMenuAbout, this, menuHelpAbout->GetId());

#ifdef KIWI_DEBUG_FEATURES
	// debug menu
	menuBar->Append((menuDebug = new wxMenu()), "&DEBUG");
	menuDebug->Append(menuDebugShowLogWindow = new wxMenuItem(menuDebug, wxID_ANY, "Show &Log Window...", "Show the log window"));
#endif
}

inline void FrmKiwi::InitializeStatusBar()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the statusbar
	//
	////////////////////////////////////////////////////////////////////////////	

	// (TODO custom status bar with embedded controls)
	this->CreateStatusBar(2);
}

FrmKiwi::FrmKiwi()
: wxFrame(NULL, wxID_ANY, "KiwiEd")
{
	// frame setup
	SetMinSize(FromDIP(wxSize(300, 200))); // set minimum frame size
	SetIcon(wxIcon(KiwiEd_xpm)); // set window icon
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	// initialize components
	InitializeGlobalMenu();
	InitializeStatusBar();
}