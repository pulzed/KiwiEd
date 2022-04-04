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
//  const.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"

// current KiwiEd version
// this MUST exist on line 22 because it auto-updates with the "update_versions" util
const std::string KIWIED_VERSION = "0.0.2";

// hardcoded configuration file
// this MUST exist on line 26 because it auto-updates with the "inject_config" util
const std::string KIWIED_CFG_INIDATA = "";

// KiwiEd configuration file
#ifdef __linux__
const std::string KIWIED_CFG_FILENAME = "~/.kiwied";
#else
const std::string KIWIED_CFG_FILENAME = "KiwiEd.ini";
#endif