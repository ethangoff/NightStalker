//Main.cpp - JailBreak Main Entry Point
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128
//Project Summary in "Notes.h"


#pragma once

#include "Game.h"

void DarkGDK ( void ) 
{
	//Initialize the game manager, running the pre-game setup and prompt screens
	Game Manager;


	//MAIN LOOP - Executed at the defined frame rate
	while(LoopGDK() && !Manager.GetExitRequest())
	{
		//Update the state of the game, sync the screen
		Manager.Update();
		dbSync();
	}
}