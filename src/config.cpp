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
//  config.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "config.h"

namespace Kiwi
{

// hardcoded configuration file (spawns on first-run)
// this MUST exist on line 23 because it auto-updates with the "inject_config" util
const char* const KIWIED_CFG_INIDATA = "; KiwiEd configuration\n\n; Startup settings\n[startup]\n; Controls whether to center the window on launch or not. Set to \"on\" to always\n; center, \"off\" to never center, and \"firstrun\" to only center on first run.\n; Ignored when maximized.\ncenter = firstrun\n; Window position on launch.\nposition = 0, 0\n; Window size on launch.\nsize = 640, 480\n; Maximized state on launch.\nmaximized = off\n\n; Default mapfile\n[default_map]\n; Default grid width and height in pixels.\ngrid_w = 32\ngrid_h = 32\n; Default grid size in cell units.\nsize_w = 50\nsize_h = 50\n\n; Recent files list\n[recent]\n\n";

std::string KiwiConfig::GetConfigurationFilename()
{
#ifdef __linux__
	const char* home;
	if ((home = getenv("HOME")) == NULL) {
		home = getpwuid(getuid())->pw_dir;
	}
	return std::string(home) + "/.kiwied";
#else
	return "KiwiEd.ini";
#endif
}

KiwiConfig::KiwiConfig()
{
}

void KiwiConfig::Load()
{
	std::string configFilename = GetConfigurationFilename();
	// if there is no config file, create one
	if (!Util::FileExists(configFilename)) {
		Util::WriteDefaultConfigFile(configFilename);
	}
	// read INI file into structure
	mINI::INIFile iniFile(configFilename);
	iniFile.read(iniCfg);
}

bool KiwiConfig::Write()
{
	return false;
}

}