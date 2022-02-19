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
//  about.cpp
//  The about dialog.
//
////////////////////////////////////////////////////////////////////////////////

#include "wx/dialog.h"
#include "wx/gdicmn.h"
#include "wx/sizer.h"
#include "wx/textwrapper.h"
#include "wx/toplevel.h"
#include "wx/wxprec.h"
#include <string>
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "about.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

AboutDialog::AboutDialog(wxWindow *parent)
: wxDialog(parent, wxID_ANY, "About", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{

	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	wxImage icon(KiwiEd_xpm);

	const wxSize iconSize = FromDIP(wxSize(64, 64));

	wxStaticBitmap *bmpLogo = new wxStaticBitmap(this, wxID_ANY, wxBitmap(icon.Scale(iconSize.x, iconSize.y)));

	const int borderSize = FromDIP(wxSize(10, 10)).x;

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