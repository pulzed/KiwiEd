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
//  dlg_newmap.h
//  New map dialog.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_DLG_NEWMAP_H_
#define KIWI_DLG_NEWMAP_H_

#include "../kiwied.h"

namespace Kiwi
{

class DlgNewMap : public wxDialog
{
public:
	DlgNewMap(wxWindow* parent);
};

}

#endif // KIWI_DLG_NEWMAP_H_