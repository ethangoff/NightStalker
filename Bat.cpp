//Bat.cpp - Jailbreak Bat SubClass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Bat.h"

	//Constructors
	Bat::Bat() : AICharacter() {}

	Bat::Bat(int spriteID, int x, int y, int initialImageID, Direction initialDirection, unsigned int velocity) : AICharacter(spriteID, x, y, initialImageID, initialDirection, velocity)
	{}


	//Animation Methods
	void Bat::DeathAnimate()
	{
		FSDeath++;
		FSLDeathAnimation++;
		if(FSDeath < 2*FRAME_RATE)
		{
			CurrentImageID = IMG_SPIDER_DEATH_1 + (FSDeath/12);
			DrawSprite();
		}
		else if(FSDeath == 2* FRAME_RATE)
		{
			dbDeleteSprite(SpriteID);
		}
		else if(FSDeath < 10*FRAME_RATE)
		{
		}
		else
		{
			Respawn = true;
		}
	}

	void Bat::Animate()
	{
		FSLAnimation++;
		if(FSLAnimation > 10)
		{
			FSLAnimation = 0;
			switch(CurrentDirection)
			{
			case left:
			case right:
			case up:
			case down:
				switch(CurrentImageID)
				{
				case IMG_BAT_UP:
					SpriteOffset_Y = -20;
					CurrentImageID = IMG_BAT_DOWN;
					break;
				case IMG_BAT_DOWN:
					SpriteOffset_Y = 0;
					CurrentImageID = IMG_BAT_UP;
					break;
				}
				break;
			case none:
				CurrentImageID = IMG_BAT_UP;
				break;
			}
		}
	}