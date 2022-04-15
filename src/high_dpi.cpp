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
//  high_dpi.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "high_dpi.h"

namespace KiwiHighDPI
{
	wxBitmapBundle xpmToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality)
	{
		wxImage image(data);
		wxVector<wxBitmap> bitmaps;
		bitmaps.push_back(wxBitmap(image.Scale(baseWidth, baseHeight, quality))); // 100%
		bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.25, baseHeight * 1.25, quality))); // 125%
		bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.5, baseHeight * 1.5, quality))); // 150%
		bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.75, baseHeight * 1.75, quality))); // 175%
		bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 2, baseHeight * 2, quality))); // 200%
		return wxBitmapBundle::FromBitmaps(bitmaps);
	}
}