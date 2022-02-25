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
//  dlg_about.cpp
//  The about dialog.
//
////////////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif
#include <string>

#include "dlg_about.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

DlgAbout::DlgAbout(wxWindow *parent)
: wxDialog(parent, wxID_ANY, "About", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	const wxSize iconSize = FromDIP(wxSize(64, 64));
	const int borderSize = FromDIP(wxSize(10, 10)).x;

	wxImage icon(KiwiEd_xpm);

	wxStaticBitmap *bmpLogo = new wxStaticBitmap(this, wxID_ANY, wxBitmap(icon.Scale(iconSize.x, iconSize.y)));


	innerHSizer->Add(bmpLogo, 0, wxALL, borderSize);

	// text info
	innerHSizer->Add(
		CreateTextSizer(
			"KiwiEd\n"
			"v0.0.1\n\n"
			"2D map editor\n\n"
			"Copyright (c) 2022 Danijel Durakovic\n"
			"Licensed under the terms of GPLv3"
		),
		0,
		wxALL,
		borderSize
	);

	outerVSizer->Add(innerHSizer);

	// ok button
	outerVSizer->Add(new wxButton(this, wxID_OK, "Okay", wxDefaultPosition, FromDIP(wxSize(110,30))), 0, wxTOP | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, borderSize);

	SetSizerAndFit(outerVSizer);
}