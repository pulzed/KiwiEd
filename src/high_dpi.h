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
//  high_dpi.h
//  High DPI-related helper features.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWIED_HIGH_DPI_H_
#define KIWIED_HIGH_DPI_H_

namespace KiwiHighDPI
{
	// create a bitmap bundle which represents various sizes of input image
	wxBitmapBundle xpmToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality = wxIMAGE_QUALITY_HIGH);
}

#endif // KIWIED_HIGH_DPI_H_