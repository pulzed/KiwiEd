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

#if defined(_WIN32) || defined(__CYGWIN__)
	#define KIWI_SYSTEM_WINDOWS
#elif defined(__linux__)
	#define KIWI_SYSTEM_LINUX
#elif defined(__APPLE__)
	#define KIWI_SYSTEM_MACOS
#endif

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
#pragma warning(disable: 26812)
#pragma warning(disable: 26451)
#pragma warning(disable: 26495)
#pragma warning(disable: 26439)

// wxWidgets includes
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif
#include "wx/settings.h"
#include "wx/bmpbndl.h"
#include "wx/treectrl.h"
#include "wx/gdicmn.h"
#include "wx/textctrl.h"
#include "wx/aui/aui.h"

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
#include "res/svg_data.h"
#include "util.h"
#include "config.h"

// dialogs and windows
#include "ui/dlg_about.h"
#include "ui/dlg_settings.h"
#include "ui/dlg_newlayer.h"
#include "ui/dlg_newmap.h"

#ifdef KIWI_DEBUG_FEATURES
	// debug features includes
	#include "ui/frm_log.h"
#endif

// main frame components and window
#include "ui/frm_kiwi.h"

// application entry point
#include "app.h"

#endif // KIWI_KIWIED_H_
