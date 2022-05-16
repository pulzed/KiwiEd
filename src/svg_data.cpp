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
//  svg_data.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "kiwied.h"
#include "svg_data.h"

const char* const SVG_ICON_NEW = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"256\" height=\"256\" version=\"1.1\" viewBox=\"0 0 67.732 67.732\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n <defs>\n  <linearGradient id=\"linearGradient2225\">\n   <stop stop-color=\"#008282\" offset=\"0\"/>\n   <stop stop-color=\"#008080\" offset=\"1\"/>\n  </linearGradient>\n  <linearGradient id=\"linearGradient2227\" x1=\"54.184\" x2=\"204.73\" y1=\"25.259\" y2=\"233.37\" gradientUnits=\"userSpaceOnUse\" xlink:href=\"#linearGradient2225\"/>\n  <linearGradient id=\"linearGradient6486\" x1=\"48.84\" x2=\"57.212\" y1=\"12.364\" y2=\"20.736\" gradientUnits=\"userSpaceOnUse\">\n   <stop stop-color=\"#404040\" offset=\"0\"/>\n   <stop stop-color=\"#404040\" stop-opacity=\"0\" offset=\"1\"/>\n  </linearGradient>\n  <clipPath id=\"clipPath6650\">\n   <path d=\"m54.378 15.156v42.341c0 2.4848-2.0004 4.4852-4.4852 4.4852h-31.301c-2.4848 0-4.4852-2.0004-4.4852-4.4852v-46.474c0-2.4848 2.0004-4.4852 4.4852-4.4852h27.274\" fill=\"url(#linearGradient6654)\" stroke-width=\".26458\"/>\n  </clipPath>\n  <linearGradient id=\"linearGradient6654\" x1=\"54.184\" x2=\"204.73\" y1=\"25.259\" y2=\"233.37\" gradientTransform=\"scale(.26458)\" gradientUnits=\"userSpaceOnUse\" xlink:href=\"#linearGradient2225\"/>\n </defs>\n <g>\n  <path transform=\"scale(.26458)\" d=\"m205.53 57.283v160.03c0 9.3915-7.5607 16.952-16.952 16.952h-118.31c-9.3915 0-16.952-7.5607-16.952-16.952v-175.65c0-9.3915 7.5607-16.952 16.952-16.952h103.09\" fill=\"url(#linearGradient2227)\"/>\n  <path d=\"m47.174 13.907 2.9773-2.9773 8.5383 8.5383-2.9773 2.9773z\" clip-path=\"url(#clipPath6650)\" fill=\"url(#linearGradient6486)\" opacity=\".35018\"/>\n  <path d=\"m54.378 15.156h-4.027c-2.4848 0-4.4852-2.0004-4.4852-4.4852v-4.1325\" fill=\"#00b7b7\" stroke-width=\".26458\"/>\n </g>\n</svg>\n";

//const char* const SVG_ICON_NEW = "<svg id=\"Layer_1\" data-name=\"Layer 1\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 98.63 122.88\"><title>blank-file</title><path fill=\"#000000\" d=\"M98.63,35.57A3.58,3.58,0,0,0,96,32.12L64.39,1.32A3.53,3.53,0,0,0,61.63,0H6.43A6.42,6.42,0,0,0,0,6.43v110a6.42,6.42,0,0,0,6.43,6.43H92.21a6.42,6.42,0,0,0,6.4-6.43q0-40.45,0-80.88Zm-33.43-23L86.68,32.69H65.2V12.57ZM7.18,115.7V7.15H58V36.26a3.61,3.61,0,0,0,3.61,3.61H91.45q0,37.92,0,75.83Z\"/></svg>";
const char* const SVG_ICON_OPEN = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg width=\"256\" height=\"256\" version=\"1.1\" viewBox=\"0 0 67.732 67.732\" xmlns=\"http://www.w3.org/2000/svg\">\n <g>\n  <rect x=\"5.2916\" y=\"3.9687\" width=\"56.885\" height=\"59.53\" fill=\"#5eba1a\"/>\n  <rect x=\"11.906\" y=\"9.2603\" width=\"9.2603\" height=\"48.947\" fill=\"#fff\"/>\n </g>\n</svg>\n";