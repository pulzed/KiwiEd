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
//
//  app.cpp
//  Main application window and program entry point.
//
////////////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "app.h"
#include "about.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

wxIMPLEMENT_APP(KiwiEdApp); // implement wx application

bool KiwiEdApp::OnInit()
{
	KiwiEdFrame* frame = new KiwiEdFrame();
	frame->SetSize(frame->FromDIP(wxSize(640, 480)));
	frame->CentreOnScreen();
	frame->Show(true);
	return true;
}

void KiwiEdFrame::OnMenuExit(wxCommandEvent& e)
{
	Close(true);
}

void KiwiEdFrame::OnMenuAbout(wxCommandEvent& e)
{
	AboutDialog* aboutDialog = new AboutDialog(this);
	aboutDialog->ShowModal();
}

KiwiEdFrame::KiwiEdFrame()
: wxFrame(NULL, wxID_ANY, "KiwiEd")
{
	SetIcon(wxIcon(KiwiEd_xpm));

	// open recent submenu
	wxMenu* menuOpenRecent = new wxMenu();
	menuOpenRecent->Append(100, "{recent1}");
	menuOpenRecent->Append(200, "{recent2}");
	menuOpenRecent->Append(300, "{recent3}");
	menuOpenRecent->Append(400, "{recent4}");
	menuOpenRecent->Append(500, "{recent5}");

	// file menu
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(0, "&New...\tCtrl+N", "Create new map");
	menuFile->AppendSeparator();
	menuFile->Append(1, "&Open...\tCtrl+O", "Open map");
	menuFile->AppendSubMenu(menuOpenRecent, "Open &Recent");
	menuFile->AppendSeparator();
	menuFile->Append(4, "&Save\tCtrl+S", "Save map");
	menuFile->Append(5, "Save &As...\tCtrl+Shift+S", "Save map as");
	menuFile->Append(6, "Save as &Template...", "Save a stripped file as template");
	menuFile->AppendSeparator();
	menuFile->Append(7, "&Export\tCtrl+E", "Export map");
	menuFile->Append(8, "Ex&port As...\tCtrl+Shift+E", "Export map as");
	menuFile->AppendSeparator();
	menuFile->Append(2, "&Close\tCtrl+F4", "Close map");
	menuFile->Append(3, "Close A&ll\tCtrl+Shift+F4", "Close map");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT, "E&xit\tAlt+F4");

	// edit menu
	wxMenu* menuEdit = new wxMenu();
	menuEdit->Append(30, "&Undo\tCtrl+Z");
	menuEdit->Append(31, "&Redo\tCtrl+Y");
	menuEdit->AppendSeparator();
	menuEdit->Append(31, "Cu&t\tCtrl+X");
	menuEdit->Append(32, "&Copy\tCtrl+C");
	menuEdit->Append(33, "&Paste\tCtrl+V");
	menuEdit->Append(34, "&Delete\tDel");
	menuEdit->AppendSeparator();
	menuEdit->Append(35, "Select &All\tCtrl+A");

	// layouts submenu
	wxMenu* menuLayout = new wxMenu();
	menuLayout->Append(50, "Standard &Layout", "Set up standard layout");
	menuLayout->Append(51, "Al&ternative &Layout", "Set up alternative layout");
	menuLayout->AppendSeparator();
	menuLayout->Append(52, "Re&member Current Layout", "Remember current layout", wxITEM_CHECK);

	// view menu
	wxMenu* menuView = new wxMenu();
	menuView->AppendSubMenu(menuLayout, "&Layout");

	// map menu
	wxMenu* menuMap = new wxMenu();

	// layer menu
	wxMenu* menuLayer = new wxMenu();

	// tools menu
	wxMenu* menuTools = new wxMenu();
	menuTools->Append(10, "&Settings...\tF8", "Show settings dialog");

	// help menu
	wxMenu* menuHelp = new wxMenu();
	menuHelp->Append(11, "&Contents...\tF1", "Show help");
	menuHelp->AppendSeparator();
	menuHelp->Append(12, "Check for &Updates", "Check online repository for updates");
	menuHelp->AppendSeparator();
	menuHelp->Append(wxID_ABOUT, "&About", "Show about window");

	/////////menuHelp->FindItem(12)->SetBitmap(wxBitmap(wxImage(KiwiEd_xpm))); /// test

	// menu bar
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuEdit, "&Edit");
	menuBar->Append(menuView, "&View");
	menuBar->Append(menuMap, "&Map");
	menuBar->Append(menuLayer, "&Layer");
	menuBar->Append(menuTools, "&Tools");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);

	// status bar
	CreateStatusBar();
	SetStatusText("Ready");

	// bind menu events
	Bind(wxEVT_MENU, &KiwiEdFrame::OnMenuExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &KiwiEdFrame::OnMenuAbout, this, wxID_ABOUT);
}

