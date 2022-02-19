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

#ifndef KIWI_APP_H_
#define KIWI_APP_H_

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "config.h"

class KiwiEdApp : public wxApp
{
private:
	KiwiConfig conf;

public:
	virtual bool OnInit();
};

class KiwiEdFrame : public wxFrame
{
private:
	// menu events
	void OnMenuExit(wxCommandEvent& e);
	void OnMenuAbout(wxCommandEvent& e);

public:
	KiwiEdFrame();
};

#endif // KIWI_APP_H

