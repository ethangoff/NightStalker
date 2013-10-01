//FirstRobot.cpp - FirstRobot SubClass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "FirstRobot.h"

	//Constructors
	FirstRobot::FirstRobot() : AICharacter() {}

	FirstRobot::FirstRobot(const int spriteID, int x, int y, int initialImageID, Direction initialDirection, const unsigned int velocity) : AICharacter(spriteID, x, y, initialImageID, initialDirection, velocity)
	{
		FSLFire = 0;
		FireDirection = none;
	}
	

	//AI Aiming Management Method
	void FirstRobot::Aim(Tile& PlayerLocale)
	{
		FSLFire++;
		if(FSLFire > ROBOT_FIRE_PERIOD)
		{
			FSLFire = 0;
			if(PlayerLocale.IndexX == Locale.IndexX)
			{
				if(PlayerLocale.IndexY < Locale.IndexY)
					FireDirection = up;
				else
					FireDirection = down;
				return;
			}
			else if(PlayerLocale.IndexY == Locale.IndexY)
			{
				if(PlayerLocale.IndexX > Locale.IndexX)
					FireDirection = right;
				else
					FireDirection = left;
				return;
			}
		}
		else
			FireDirection = none;
	}


	//Animation Methods
	void FirstRobot::Animate(){}

	void FirstRobot::DeathAnimate()
	{
		FSDeath++;
		FSLDeathAnimation++;
		if(FSDeath < 3*FRAME_RATE)
		{
			dbSprite(SpriteID, Position.X, Position.Y, IMG_ROBOT1_DEATH1 + (FSDeath/3));
			dbOffsetSprite(SpriteID, 0, DEATH_ANIMATION_OFFSET);
		}
		else
		{
			Respawn = true;
		}
	}


	//Access Methods
	Direction FirstRobot::GetFireDirection() const
	{
		return FireDirection;
	}