//Gun.cpp - Gun Subclass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Gun.h"


	//Constructors
	Gun::Gun() : SpriteObject() {}

	Gun::Gun(const int spriteID, Coordinate startingPosition, int initialImageID) : SpriteObject(spriteID, startingPosition, initialImageID)
	{
		//Set first ImageID and draw the initial sprite
		CurrentImageID = initialImageID;
		dbSprite(SpriteID, Position.X, Position.Y, CurrentImageID);
		//Initialize state variables
		FSLAnimation = 0;
		Collided = false;
		Hidden = false;
	}


	//Management Methods
	void Gun::Hide()
	{
		//First, we set the hidden token to true, then we delete the sprite as to allow no more collisions
		Hidden = true;
		dbDeleteSprite(SpriteID);
	}

	void Gun::Update(const unsigned int player)
	{
		//first, we check for a collision between the player and an unhidden gun
		if(dbSpriteCollision(SpriteID, player) && !Hidden)
		{
			Collided = true;
			Hide();
		}
		else if(!Hidden) //otherwise, if the gun is unhidden (but not taken), we animate it
			Animate();
	}


	//Animation Method
	void Gun::Animate()
	{
		//First, we increment the frame counter for the animation
		FSLAnimation++;
		//Then, we switch between images every 10 frames
		if (FSLAnimation > 10)
		{
			FSLAnimation = 0;
			switch(CurrentImageID)
			{
			case IMG_GUN_1:
				CurrentImageID = IMG_GUN_2;
				break;
			case IMG_GUN_2:
				CurrentImageID = IMG_GUN_3;
				break;
			case IMG_GUN_3:
				CurrentImageID = IMG_GUN_1;
				break;
			}
		}
		dbSprite(SpriteID, Position.X, Position.Y, CurrentImageID);
	}


	//Access Methods
	bool Gun::GetCollisionState() const
	{
		return Collided;
	}

	bool Gun::GetHiddenState() const
	{
		return Hidden;
	}

	void Gun::SetCollisionStateTrue()
	{
		Collided = true;
	}

	void Gun::SetCollisionStateFalse()
	{
		Collided = false;
	}