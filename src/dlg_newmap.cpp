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
//  dlg_newmap.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "dlg_newmap.h"

DlgNewMap::DlgNewMap(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	/*
	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );

	// create text ctrl with minimal size 100x60
	topsizer->Add(
		new wxTextCtrl( this, -1, "My text.", wxDefaultPosition, wxSize(100,60), wxTE_MULTILINE),
		1,            // make vertically stretchable
		wxEXPAND |    // make horizontally stretchable
		wxALL,        //   and make border all around
		10 );         // set border width to 10
	wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
	button_sizer->Add(
		new wxButton( this, wxID_OK, "OK" ),
		0,           // make horizontally unstretchable
		wxALL,       // make border all around (implicit top alignment)
		10 );        // set border width to 10
	button_sizer->Add(
		new wxButton( this, wxID_CANCEL, "Cancel" ),
		0,           // make horizontally unstretchable
		wxALL,       // make border all around (implicit top alignment)
		10 );        // set border width to 10
	topsizer->Add(
		button_sizer,
		0,                // make vertically unstretchable
		wxALIGN_CENTER ); // no border and centre horizontally

	SetSizerAndFit(topsizer); // use the sizer for layout and size window
								// accordingly and prevent it from being resized
								// to smaller size
							*/

	wxBoxSizer* sizerTop = new wxBoxSizer(wxVERTICAL);

	wxPanel* test;

	sizerTop->Add(
		test = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(450, 250))),
		1,
		//wxEXPAND | wxTOP | wxLEFT | wxRIGHT,
		wxEXPAND | wxALL,
		10
	);

	test->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	wxBoxSizer* sizerButtons = new wxBoxSizer(wxHORIZONTAL);
	sizerButtons->Add(
		new wxButton(this, wxID_ANY, "OK", wxDefaultPosition, FromDIP(wxSize(110, 30))),
		0,
		wxEXPAND | wxRIGHT | wxBOTTOM,
		10
	);
	sizerButtons->Add(
		new wxButton(this, wxID_ANY, "Cancel", wxDefaultPosition, FromDIP(wxSize(110, 30))),
		0,
		wxEXPAND | wxRIGHT | wxBOTTOM,
		10
	);

	sizerTop->Add(
		sizerButtons,
		0,
		wxALIGN_RIGHT
	);



	SetSizerAndFit(sizerTop);
}