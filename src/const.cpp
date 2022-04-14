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
#include "const.h"

// current KiwiEd version
// this MUST exist on line 22 because it auto-updates with the "update_versions" util
const std::string KIWIED_VERSION = "0.0.2";

// hardcoded configuration file (spawns on first-run)
// this MUST exist on line 26 because it auto-updates with the "inject_config" util
const std::string KIWIED_CFG_INIDATA = ";/===>-----------------<==\\;\n;|                        |;\n;|  KiwiEd configuration  |;\n;|                        |;\n;\\===>----------------<===/;\n\n; Main application window configuration.\n[window]\n; Controls whether to center the window on launch or not. Set to \"on\" to always\n; center, \"off\" to never center, and \"first\" to only center on first run.\n; Ignored when maximized.\ncenter = on\n; Window position on launch.\nx = 0\ny = 0\n; Window size on launch.\nwidth = 640\nheight = 640\n; Maximized state on launch.\nmaximized = off\n; TODO screen to spawn on\n; TODO high dpi setting\n\n\n; Default mapfile.\n[default_map]\n; Default grid width and height in pixels.\ngrid_w = 32\ngrid_h = 32\n; Default grid size in cell units.\nsize_w = 50\nsize_h = 50\n";