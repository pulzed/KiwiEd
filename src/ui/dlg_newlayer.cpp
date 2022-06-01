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

#include "../kiwied.h"
#include "dlg_newlayer.h"

DlgNewLayer::DlgNewLayer(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "New Layer", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
}