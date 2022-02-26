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
//  dlg_settings.cpp
//  The settings dialog.
//
////////////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "wx/treectrl.h"

#include "dlg_settings.h"

DlgSettings::DlgSettings(wxWindow *parent)
: wxDialog(parent, wxID_ANY, "Settings", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	const int borderSize = FromDIP(10);

	//wxBoxSizer* elmSizerOuterPadding = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	////innerHSizer->Add(CreateTextSizer("Test"), 0, wxALL, borderSize);



    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxTreeCtrl control and add a few nodes to it
    wxTreeCtrl* treeCtrl = new wxTreeCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(250, 350));

    wxTreeItemId rootId = treeCtrl->AddRoot("Root");
    treeCtrl->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = treeCtrl->AppendItem(rootId, "Node 2");
    treeCtrl->AppendItem(child2Id, "Child of node 2");
    treeCtrl->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    treeCtrl->ExpandAll();


	innerHSizer->Add(panel, 0, wxALL, borderSize);


	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(380, 350));


	innerHSizer->Add(panel2, 0, wxALL, borderSize);



	outerVSizer->Add(innerHSizer);

	wxBoxSizer* sizerButtons = new wxBoxSizer(wxHORIZONTAL);

	//wxSizer* sizerButtons = CreateButtonSizer(wxOK | wxCANCEL);

	sizerButtons->Add(new wxButton(this, wxID_OK, "Ok", wxDefaultPosition, FromDIP(wxSize(110,30))), 0, wxLEFT, borderSize);
	sizerButtons->Add(new wxButton(this, wxID_CANCEL, "Cancel", wxDefaultPosition, FromDIP(wxSize(110,30))), 0, wxLEFT, borderSize);

	outerVSizer->Add(sizerButtons, 0, wxBOTTOM | wxRIGHT | wxALIGN_RIGHT, borderSize);

	//outerVSizer->Add(sizerBtns, wxSizerFlags().Expand().Border(wxLEFT, borderSize));
	//outerVSizer->Add(sizerBtns, 0);

	//outerVSizer->Add(new wxButton(this, wxID_OK, "Ok", wxDefaultPosition, FromDIP(wxSize(110,30))), 0, wxTOP | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, borderSize);
	//outerVSizer->Add(new wxButton(this, wxID_CANCEL, "Cancel", wxDefaultPosition, FromDIP(wxSize(110,30))), 0, wxTOP | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, borderSize);

	SetSizerAndFit(outerVSizer);

	//elmSizerOuterPadding->Add(outerVSizer, 0, wxALL, borderSize);

	//SetSizerAndFit(elmSizerOuterPadding);
}