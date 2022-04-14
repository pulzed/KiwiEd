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
//  kiwied.h
//  Master header. Include this everywhere.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWIED_UTIL_H_
#define KIWIED_UTIL_H_

#include <string>

namespace KiwiUtil
{

	bool FileExists(const std::string& filename);
	void WriteDefaultConfigFile(const std::string& filename);

}

#endif // KIWIED_UTIL_H_

