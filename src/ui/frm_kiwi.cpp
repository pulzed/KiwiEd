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
#include "frm_kiwi.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

namespace Kiwi
{

void FrmKiwi::OnMenuFileNew(wxCommandEvent& e)
{
	DlgNewMap* dlgNewMap = new DlgNewMap(this);
	dlgNewMap->CenterOnParent();
	dlgNewMap->ShowModal();
}

void FrmKiwi::OnMenuFileExit(wxCommandEvent& e)
{
	Close(true);
}

void FrmKiwi::OnMenuToolsSettings(wxCommandEvent& e)
{
	DlgSettings* dlgSettings = new DlgSettings(this);
	dlgSettings->CenterOnParent();
	dlgSettings->ShowModal();
}

void FrmKiwi::OnMenuHelpAbout(wxCommandEvent& e)
{
	DlgAbout* dlgAbout = new DlgAbout(this);
	dlgAbout->CenterOnParent();
	dlgAbout->ShowModal();
}

inline void FrmKiwi::InitializeGlobalMenu()
{
	// check for dark mode
	bool darkMode = wxSystemSettings::GetAppearance().IsDark();

	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the menubar
	//
	////////////////////////////////////////////////////////////////////////////

	menuBar.root = new wxMenuBar();
	SetMenuBar(menuBar.root);

	//
	// File menu
	//
	auto& menuFile = menuBar.menuFile;
	menuBar.root->Append((menuFile.root = new wxMenu()), "&File");
	{
		auto& menuNew = menuFile.members.menuNew;
		menuNew = new wxMenuItem(menuFile.root, wxID_ANY, "&New...\tCtrl+N", "Create a new map");
		///menuNew->SetBitmap(wxBitmapBundle::FromSVG(Util::GetThemeAgnosticSVG(SVG_ICON_NEW, darkMode).c_str(), wxSize(16, 16)));
		menuNew->SetBitmap(wxBitmapBundle::FromSVG(SVG_ICON_NEW, wxSize(16, 16)));
		menuFile.root->Append(menuNew);
		Bind(wxEVT_MENU, &FrmKiwi::OnMenuFileNew, this, menuNew->GetId());

		menuFile.root->AppendSeparator();

		auto& menuOpen = menuFile.members.menuOpen;
		menuOpen = new wxMenuItem(menuFile.root, wxID_ANY, "&Open...\tCtrl+O", "Open an existing map");
		menuFile.root->Append(menuOpen);

		auto& menuOpenRecent = menuFile.members.menuOpenRecent;
		menuFile.root->AppendSubMenu((menuOpenRecent.root = new wxMenu()), "Open &Recent");
		{
			auto& menuNoRecentItems = menuOpenRecent.members.menuNoRecentItems;
			menuNoRecentItems = new wxMenuItem(menuOpenRecent.root, wxID_ANY, "(no recent items)");
			menuOpenRecent.root->Append(menuNoRecentItems);
			menuNoRecentItems->Enable(false);

		}

		menuFile.root->AppendSeparator();

		auto& menuSave = menuFile.members.menuSave;
		menuSave = new wxMenuItem(menuFile.root, wxID_ANY, "&Save\tCtrl+S", "Save map");
		menuFile.root->Append(menuSave);

		auto& menuSaveAs = menuFile.members.menuSaveAs;
		menuSaveAs = new wxMenuItem(menuFile.root, wxID_ANY, "Save &As...\tCtrl+Shift+S", "Save map as");
		menuFile.root->Append(menuSaveAs);

		menuFile.root->AppendSeparator();

		auto& menuSaveTemplate = menuFile.members.menuSaveTemplate;
		menuSaveTemplate = new wxMenuItem(menuFile.root, wxID_ANY, "Save &Template", "Save map as template");
		menuFile.root->Append(menuSaveTemplate);

		menuFile.root->AppendSeparator();

		auto& menuExport = menuFile.members.menuExport;
		menuExport = new wxMenuItem(menuFile.root, wxID_ANY, "&Export\tCtrl+E", "Export map");
		menuFile.root->Append(menuExport);

		auto& menuExportAs = menuFile.members.menuExportAs;
		menuExportAs = new wxMenuItem(menuFile.root, wxID_ANY, "Ex&port As...\tCtrl+Shift+E", "Export map as");
		menuFile.root->Append(menuExportAs);

		menuFile.root->AppendSeparator();

		auto& menuClose = menuFile.members.menuClose;
		menuClose = new wxMenuItem(menuFile.root, wxID_ANY, "&Close\tCtrl+F4", "Close map");
		menuFile.root->Append(menuClose);

		auto& menuCloseAll = menuFile.members.menuCloseAll;
		menuCloseAll = new wxMenuItem(menuFile.root, wxID_ANY, "Close A&ll\tCtrl+Shift+F4", "Close all open");
		menuFile.root->Append(menuCloseAll);

		menuFile.root->AppendSeparator();

		auto& menuExit = menuFile.members.menuExit;
		menuExit = new wxMenuItem(menuFile.root, wxID_ANY, "E&xit\tAlt+F4", "Exit editor");
		menuFile.root->Append(menuExit);
		Bind(wxEVT_MENU, &FrmKiwi::OnMenuFileExit, this, menuExit->GetId());
	}

	//
	// Edit menu
	//
	auto& menuEdit = menuBar.menuEdit;
	menuBar.root->Append((menuEdit.root = new wxMenu()), "&Edit");
	{
		auto& menuUndo = menuEdit.members.menuUndo;
		menuUndo = new wxMenuItem(menuEdit.root, wxID_ANY, "&Undo\tCtrl+Z", "Undo last action");
		menuEdit.root->Append(menuUndo);

		auto& menuRedo = menuEdit.members.menuRedo;
		menuRedo = new wxMenuItem(menuEdit.root, wxID_ANY, "&Redo\tCtrl+Y", "Redo previous undo");
		menuEdit.root->Append(menuRedo);

		menuEdit.root->AppendSeparator();

		auto& menuCut = menuEdit.members.menuCut;
		menuCut = new wxMenuItem(menuEdit.root, wxID_ANY, "Cu&t\tCtrl+X", "Cut selection");
		menuEdit.root->Append(menuCut);

		auto& menuCopy = menuEdit.members.menuCopy;
		menuCopy = new wxMenuItem(menuEdit.root, wxID_ANY, "&Copy\tCtrl+C", "Copy selection");
		menuEdit.root->Append(menuCopy);

		auto& menuPaste = menuEdit.members.menuPaste;
		menuPaste = new wxMenuItem(menuEdit.root, wxID_ANY, "&Paste\tCtrl+V", "Paste from clipboard");
		menuEdit.root->Append(menuPaste);

		auto& menuDelete = menuEdit.members.menuDelete;
		menuDelete = new wxMenuItem(menuEdit.root, wxID_ANY, "&Delete\tDel", "Delete selection");
		menuEdit.root->Append(menuDelete);

		menuEdit.root->AppendSeparator();

		auto& menuSelectView = menuEdit.members.menuSelectView;
		menuSelectView = new wxMenuItem(menuEdit.root, wxID_ANY, "Select &View\tCtrl+A", "Select everything in view");
		menuEdit.root->Append(menuSelectView);

		auto& menuSelectAll = menuEdit.members.menuSelectAll;
		menuSelectAll = new wxMenuItem(menuEdit.root, wxID_ANY, "Select &All\tCtrl+Shift+A", "Select everything on map");
		menuEdit.root->Append(menuSelectAll);

		auto& menuSelectNone = menuEdit.members.menuSelectNone;
		menuSelectNone = new wxMenuItem(menuEdit.root, wxID_ANY, "Select &None\tEsc", "Cancel selection");
		menuEdit.root->Append(menuSelectNone);
	}

	//
	// View menu
	//
	auto& menuView = menuBar.menuView;
	menuBar.root->Append((menuView.root = new wxMenu()), "&View");

	//
	// Map menu
	//
	auto& menuMap = menuBar.menuMap;
	menuBar.root->Append((menuMap.root = new wxMenu()), "&Map");
	{
		auto& menuMapProperties = menuMap.members.menuMapProperties;
		menuMapProperties = new wxMenuItem(menuMap.root, wxID_ANY, "Map &Properties\tF6", "Show map properties");
		menuMap.root->Append(menuMapProperties);
	}

	//
	// Layer menu
	//
	auto& menuLayer = menuBar.menuLayer;
	menuBar.root->Append((menuLayer.root = new wxMenu()), "&Layer");
	{
		auto& menuCreateNew = menuLayer.members.menuCreateNew;
		menuCreateNew = new wxMenuItem(menuLayer.root, wxID_ANY, "&Create New...\tCtrl+Shift+N", "Create a new layer");
		menuLayer.root->Append(menuCreateNew);

		auto& menuDuplicate = menuLayer.members.menuDuplicate;
		menuDuplicate = new wxMenuItem(menuLayer.root, wxID_ANY, "&Duplicate\tCtrl+Shift+D", "Duplicate this layer");
		menuLayer.root->Append(menuDuplicate);

		auto& menuMerge = menuLayer.members.menuMerge;
		menuMerge = new wxMenuItem(menuLayer.root, wxID_ANY, "&Merge...\tCtrl+Shift+M", "Merge this layer with another");
		menuLayer.root->Append(menuMerge);

		auto& menuDelete = menuLayer.members.menuDelete;
		menuDelete = new wxMenuItem(menuLayer.root, wxID_ANY, "Dele&te", "Delete this layer");
		menuLayer.root->Append(menuDelete);

		menuLayer.root->AppendSeparator();

		auto& menuRaise = menuLayer.members.menuRaise;
		menuRaise = new wxMenuItem(menuLayer.root, wxID_ANY, "&Raise\tCtrl+PgUp", "Raise this layer to one level above current");
		menuLayer.root->Append(menuRaise);

		auto& menuLower = menuLayer.members.menuLower;
		menuLower = new wxMenuItem(menuLayer.root, wxID_ANY, "&Lower\tCtrl+PgDn", "Raise this layer to one level below current");
		menuLayer.root->Append(menuLower);

		menuLayer.root->AppendSeparator();

		auto& menuLayerProperties = menuLayer.members.menuLayerProperties;
		menuLayerProperties = new wxMenuItem(menuLayer.root, wxID_ANY, "Layer &Properties\tF7", "Show layer properties");
		menuLayer.root->Append(menuLayerProperties);
	}

	//
	// Tools menu
	//
	auto& menuTools = menuBar.menuTools;
	menuBar.root->Append((menuTools.root = new wxMenu()), "&Tools");
	{
		auto& menuSettings = menuTools.members.menuSettings;
		menuSettings = new wxMenuItem(menuTools.root, wxID_ANY, "&Settings\tF8", "Show the settings dialog");
		menuTools.root->Append(menuSettings);
		Bind(wxEVT_MENU, &FrmKiwi::OnMenuToolsSettings, this, menuSettings->GetId());
	}

	//
	// Help menu
	//
	auto& menuHelp = menuBar.menuHelp;
	menuBar.root->Append((menuHelp.root = new wxMenu()), "&Help");
	{
		auto& menuUserManual = menuHelp.members.menuUserManual;
		menuUserManual = new wxMenuItem(menuHelp.root, wxID_ANY, "User &Manual\tF1", "Open online help");
		menuHelp.root->Append(menuUserManual);

		auto& menuCheckForUpdates = menuHelp.members.menuCheckForUpdates;
		menuCheckForUpdates = new wxMenuItem(menuHelp.root, wxID_ANY, "Check for &Updates", "Check online repository for updates");
		menuHelp.root->Append(menuCheckForUpdates);

		menuHelp.root->AppendSeparator();

		auto& menuAbout = menuHelp.members.menuAbout;
		menuAbout = new wxMenuItem(menuHelp.root, wxID_ANY, "&About", "Show the about dialog");
		menuHelp.root->Append(menuAbout);
		Bind(wxEVT_MENU, &FrmKiwi::OnMenuHelpAbout, this, menuAbout->GetId());
	}

#ifdef KIWI_DEBUG_BUILD
	//
	// Debug menu
	//
	auto& menuDebug = menuBar.menuDebug;
	menuBar.root->Append((menuDebug.root = new wxMenu()), "&Debug");
	{
		auto& menuLogWindow = menuDebug.members.menuLogWindow;
		menuLogWindow = new wxMenuItem(menuDebug.root, wxID_ANY, "&Log Window\tCtrl+Shift+L", "Open log window");
		menuDebug.root->Append(menuLogWindow);
	}
#endif
}

inline void FrmKiwi::InitializeToolBar()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the toolbar
	//
	////////////////////////////////////////////////////////////////////////////	

	wxAuiToolBar* toolbar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);

    toolbar->AddTool(1, "Test", wxBitmapBundle::FromSVG(SVG_ICON_NEW, wxSize(16, 16)));
    toolbar->AddSeparator();
    toolbar->AddTool(2, "Test", wxBitmapBundle::FromSVG(SVG_ICON_OPEN, wxSize(16, 16)));
    toolbar->AddTool(3, "Test", wxBitmapBundle::FromSVG(SVG_ICON_OPEN, wxSize(16, 16)));
    toolbar->AddTool(4, "Test", wxBitmapBundle::FromSVG(SVG_ICON_OPEN, wxSize(16, 16)));
    toolbar->AddTool(5, "Test", wxBitmapBundle::FromSVG(SVG_ICON_OPEN, wxSize(16, 16)));
    ///toolbar->SetCustomOverflowItems(prepend_items, append_items);
    toolbar->Realize();

	auiManager.AddPane(toolbar, wxAuiPaneInfo().
				Name("tb1").Caption("Big Toolbar").
				ToolbarPane().Top());

}

inline void FrmKiwi::InitializeStatusBar()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize the statusbar
	//
	////////////////////////////////////////////////////////////////////////////	

	this->CreateStatusBar(1, wxSTB_SIZEGRIP);
}

inline void FrmKiwi::InitializeInterface()
{
	////////////////////////////////////////////////////////////////////////////
	//
	//  Initialize editor interface
	//
	////////////////////////////////////////////////////////////////////////////

/*
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	//wxNotebook* ntbDocumentView = new wxNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxAuiNotebook* ntbDocumentView = new wxAuiNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS);
	//wxAuiNotebook* ntbDocumentView = new wxAuiNotebook(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_BOTTOM | wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ACTIVE_TAB);
	//ntbDocumentView->SetTabCtrlHeight(FromDIP(32));
	//ntbDocumentView->SetUniformBitmapSize(FromDIP(wxSize(32, 32)));

	wxTextCtrl* textCtrl1 = new wxTextCtrl(ntbDocumentView, wxID_ANY, "contents", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	wxPanel* panel1 = new wxPanel(ntbDocumentView, wxID_ANY);
	wxPanel* panel2 = new wxPanel(ntbDocumentView, wxID_ANY);

	ntbDocumentView->AddPage(panel1, "document1.ext");
	ntbDocumentView->AddPage(panel2, "document2.ext");
	ntbDocumentView->AddPage(textCtrl1, "document3.ext");

	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(ntbDocumentView, 1, wxEXPAND);
	panel->SetSizer(panelSizer);

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->SetMinSize(250, 200);
	topSizer->Add(panel, 1, wxEXPAND);

	SetSizerAndFit(topSizer);
	*/




/*
	wxAuiNotebook* ntbDocumentView = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS);

		

	wxTextCtrl* textCtrl1 = new wxTextCtrl(ntbDocumentView, wxID_ANY, "contents", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	wxPanel* panel1 = new wxPanel(ntbDocumentView, wxID_ANY);
	wxPanel* panel2 = new wxPanel(ntbDocumentView, wxID_ANY);

	ntbDocumentView->AddPage(panel1, "document1.ext");
	ntbDocumentView->AddPage(panel2, "document2.ext");
	ntbDocumentView->AddPage(textCtrl1, "document3.ext");

	auiManager.AddPane(ntbDocumentView, wxAuiPaneInfo().
		Name("sds").Caption("Big Todszolbar").Float()  //.Dockable(false)
		//.CenterPane().Top());
		.CenterPane()
		.Top());
	*/
	
}

FrmKiwi::FrmKiwi()
: wxFrame(NULL, wxID_ANY, "KiwiEd")
{
	// frame setup
	SetMinSize(FromDIP(wxSize(200, 200))); // set minimum frame size
	SetIcon(wxIcon(KiwiEd_xpm)); // set window icon
	//SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	// Make this an AUI managed window
	auiManager.SetManagedWindow(this);

	// initialize components
	InitializeGlobalMenu();
	InitializeToolBar();
	InitializeInterface();
	InitializeStatusBar();

	
	auiManager.Update();
}

}