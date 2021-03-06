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
//  app.h
//  Program implementation and entry point.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_APP_H_
#define KIWI_APP_H_

namespace Kiwi
{

class App : public wxApp
{
private:
	Config config;

public:
	virtual bool OnInit();
};

}

#endif // KIWI_APP_H_

