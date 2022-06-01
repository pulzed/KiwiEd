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
//  dlg_about.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "../kiwied.h"
#include "dlg_about.h"

// -- xpm resources --
#include "../res/KiwiEd.xpm"

DlgAbout::DlgAbout(wxWindow *parent)
: wxDialog(parent, wxID_ANY, "About", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	const int borderSize = FromDIP(10);

	wxStaticBitmap* bmpLogo = new wxStaticBitmap(this, wxID_ANY, KiwiUtil::XPMToBitmapBundle(KiwiEd_xpm, 64, 64));

	innerHSizer->Add(bmpLogo, 0, wxALL, borderSize);

	// text info
	innerHSizer->Add(
		CreateTextSizer(
			"KiwiEd\n"
			"2D map editor\n\n"
			"v" + KIWIED_VERSION + " "
#if defined(KIWI_SYSTEM_WINDOWS)
			"Windows"
#elif defined(KIWI_SYSTEM_LINUX)
			"Linux"
#elif defined(KIWI_SYSTEM_MACOS)
			"MacOS"
#endif
			" build"
#if defined(KIWI_DEBUG_BUILD)
			" (debug)" +
#endif
			"\n\n"
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