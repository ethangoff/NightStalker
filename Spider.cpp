//Spider.cpp - Jailbreak Spider SubClass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Spider.h"

	//Constructors
	Spider::Spider() : AICharacter() {}

	Spider::Spider(const int spriteID, int x, int y, int initialImageID, Direction initialDirection, const unsigned int velocity) : AICharacter(spriteID, x, y, initialImageID, initialDirection, velocity)
	{}


	//Animation Methods
	void Spider::DeathAnimate()
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

	void Spider::Animate()
	{
		FSLAnimation++;
		if(FSLAnimation > 5)
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
				case IMG_SPIDER_DEFAULT:
					CurrentImageID = IMG_SPIDER_UP;
					break;
				case IMG_SPIDER_UP:
					CurrentImageID = IMG_SPIDER_DOWN;
					break;
				case IMG_SPIDER_DOWN:
					CurrentImageID = IMG_SPIDER_UP;
					break;
				}
				break;
			case none:
				CurrentImageID = IMG_SPIDER_DEFAULT;
				break;
			}
		}
	}