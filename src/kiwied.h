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

#ifndef KIWI_KIWIED_H_
#define KIWI_KIWIED_H_

#if defined(DEBUG) || defined(_DEBUG)
	#define KIWI_DEBUG_BUILD
	#define KIWI_DEBUG_FEATURES // implement debug features when building debug
#endif

// if debug features are required in this build, simply uncomment the following line
//#define KIWI_DEBUG_FEATURES

// ignore some annoying warnings on VS
#pragma warning(disable: 4996)
#pragma warning(disable: 26812)
#pragma warning(disable: 6011)

// wxWidgets includes
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif
#include <wx/settings.h>
#include "wx/treectrl.h"
#include "wx/gdicmn.h"

// STL includes
#include <string>
#include <fstream>
#include <vector>

#ifdef __linux__
	// linux-specific includes
	#include <unistd.h>
	#include <sys/types.h>
	#include <pwd.h>
#endif

// thirdparty includes
#include "../thirdparty/mINI/ini.h"

// classes  and implementations
#include "const.h"
#include "hardcoded.h"
#include "util.h"
#include "config.h"
#include "high_dpi.h"

// dialogs and windows
#include "dlg_about.h"
#include "dlg_settings.h"
#include "dlg_newlayer.h"
#include "dlg_newmap.h"

#ifdef KIWI_DEBUG_FEATURES
	// debug features includes
	#include "frm_log.h"
#endif

// main frame components and window
#include "frm_kiwi.h"

// application entry point
#include "app.h"

#endif // KIWI_KIWIED_H_
