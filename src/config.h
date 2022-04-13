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
//  config.h
//  Application configuration manager.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_CONFIG_H_
#define KIWI_CONFIG_H_

class KiwiConfig
{
private:
	// Load default configuration.
	void LoadDefault();

public:
	KiwiConfig();

	// Load configuration. Load default if file not found.
	void Load();

	// Attempt to write configuration file. Returns write success.
	bool Write();
};

#endif // KIWI_CONFIG_H_