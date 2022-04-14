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

KiwiConfig::KiwiConfig()
{
}

void KiwiConfig::Load()
{
	// if there is no config file, create one
	if (!KiwiUtil::FileExists(KIWIED_CFG_FILENAME)) {
		KiwiUtil::WriteDefaultConfigFile();
	}
	// read INI file into structure
	mINI::INIFile iniFile(KIWIED_CFG_FILENAME);
	iniFile.read(iniCfg);
}

bool KiwiConfig::Write()
{
	return false;
}