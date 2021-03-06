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
//  dlg_settings.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "../kiwied.h"
#include "dlg_settings.h"

namespace Kiwi
{

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
    wxTreeCtrl* treeCtrl = new wxTreeCtrl(panel, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(250, 350)));

    wxTreeItemId rootId = treeCtrl->AddRoot("Root");
    treeCtrl->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = treeCtrl->AppendItem(rootId, "Node 2");
    treeCtrl->AppendItem(child2Id, "Child of node 2");
    treeCtrl->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    treeCtrl->ExpandAll();


	innerHSizer->Add(panel, 0, wxALL, borderSize);


	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(380, 350)));


	innerHSizer->Add(panel2, 0, wxALL, borderSize);



	outerVSizer->Add(innerHSizer);

	wxBoxSizer* sizerButtons = new wxBoxSizer(wxHORIZONTAL);

	sizerButtons->Add(new wxButton(this, wxID_ANY, "Ok", wxDefaultPosition, FromDIP(wxSize(105,28))), 0, wxLEFT, borderSize);
	sizerButtons->Add(new wxButton(this, wxID_ANY, "Cancel", wxDefaultPosition, FromDIP(wxSize(105,28))), 0, wxLEFT, borderSize);

	outerVSizer->Add(sizerButtons, 0, wxBOTTOM | wxRIGHT | wxALIGN_RIGHT, borderSize);

	SetSizerAndFit(outerVSizer);
}

}