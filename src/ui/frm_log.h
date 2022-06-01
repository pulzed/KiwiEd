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
//  frm_log.h
//  Debug log window.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_FRM_LOG_H_
#define KIWI_FRM_LOG_H_

#include "../kiwied.h"

class FrmLog : public wxFrame
{
private:
	// top level menubar
	wxMenuBar* menuBar;

	// top level menubar menus
	wxMenu* menuLog;
	wxMenu* menuView;

	// component initialization functions
	void InitializeGlobalMenu();

public:
	FrmLog();
};

#endif // KIWI_FRM_LOG_H_