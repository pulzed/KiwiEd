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
//  hardcoded.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "hardcoded.h"

// hardcoded configuration file (spawns on first-run)
// this MUST exist on line 23 because it auto-updates with the "inject_config" util
const char* const KIWIED_CFG_INIDATA = ";/===>-----------------<==\\;\n;|                        |;\n;|  KiwiEd configuration  |;\n;|                        |;\n;\\===>----------------<===/;\n\n; Main application window configuration.\n[window]\n; Controls whether to center the window on launch or not. Set to \"on\" to always\n; center, \"off\" to never center, and \"first\" to only center on first run.\n; Ignored when maximized.\ncenter = on\n; Window position on launch.\nx = 0\ny = 0\n; Window size on launch.\nwidth = 640\nheight = 640\n; Maximized state on launch.\nmaximized = off\n; TODO screen to spawn on\n; TODO high dpi setting\n\n\n; Default mapfile.\n[default_map]\n; Default grid width and height in pixels.\ngrid_w = 32\ngrid_h = 32\n; Default grid size in cell units.\nsize_w = 50\nsize_h = 50\n";

const char* const SVG_ICON_NEW = "<svg id=\"Layer_1\" data-name=\"Layer 1\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 98.63 122.88\"><title>blank-file</title><path d=\"M98.63,35.57A3.58,3.58,0,0,0,96,32.12L64.39,1.32A3.53,3.53,0,0,0,61.63,0H6.43A6.42,6.42,0,0,0,0,6.43v110a6.42,6.42,0,0,0,6.43,6.43H92.21a6.42,6.42,0,0,0,6.4-6.43q0-40.45,0-80.88Zm-33.43-23L86.68,32.69H65.2V12.57ZM7.18,115.7V7.15H58V36.26a3.61,3.61,0,0,0,3.61,3.61H91.45q0,37.92,0,75.83Z\"/></svg>";
const char* const SVG_ICON_OPEN = "<?xml version=\"1.0\" encoding=\"utf-8\"?><svg version=\"1.1\" id=\"Layer_1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\" viewBox=\"0 0 133.97 122.88\" style=\"enable-background:new 0 0 133.97 122.88\" xml:space=\"preserve\"><g><path d=\"M87.13,0l-26.3,28.11l14.77,0v12.89l-62.58,0.67v-8.02l0,0h4.81c1.49,0,2.71-1.21,2.71-2.71V24.5h23.02v6.45 c0,1.49,1.21,2.71,2.71,2.71h10.06v-5.41h-7.35v-6.45c0-1.49-1.21-2.71-2.71-2.71H17.82c-1.5,0-2.71,1.21-2.71,2.71v6.45h-4.81 c-1.49,0-2.71,1.21-2.71,2.71V41.7c-0.99,0-4.95-0.33-6.19,0.33c-0.93,0.5-1.52,1.53-1.4,2.65l7.33,69.78 c0.24,2.3,1.23,4.42,2.77,5.96c1.53,1.52,3.56,2.47,5.92,2.47h99.76c2.34,0,4.34-0.94,5.84-2.44c1.52-1.52,2.51-3.63,2.82-5.89 l9.46-69.57c0.04-0.18,0.06-0.38,0.06-0.57c0-1.5-1.21-2.71-2.71-2.71h-4.94V30.95c0-1.49-1.21-2.71-2.71-2.71h-7.97v5.41h5.26 v6.88l-22.25,0.24V28.12h14.77L87.13,0L87.13,0L87.13,0z M75.6,47.11v0.04l23.07,0v-0.04h29.51l-9.08,66.72 c-0.15,1.11-0.6,2.11-1.28,2.78c-0.53,0.53-1.22,0.86-2.04,0.86H16.02c-0.84,0-1.57-0.34-2.11-0.88c-0.66-0.66-1.09-1.61-1.2-2.68 L5.7,47.11H75.6L75.6,47.11z\"/></g></svg>";