//Bullet.cpp - Bullet SubClass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Bullet.h"


	//Constructors
	Bullet::Bullet() : SpriteObject() {}

	Bullet::Bullet(const int spriteID, int x, int y, Direction initialDirection, int initialImageID) : SpriteObject(spriteID, x, y, initialImageID)
	{
		//Define initial state variables
		CurrentDirection = initialDirection;
		Collided = false;

		//Rotate and re-position the bullet, in relation to the firing party, as needed
		if(CurrentDirection == up || CurrentDirection == down)
		{
			dbOffsetSprite(SpriteID, 0, HORIZONAL_BULLET_OFFSET);
			dbRotateSprite(SpriteID, 90.f);
		}
		else
			dbOffsetSprite(SpriteID, 0, VERTICAL_BULLET_OFFSET);
	}

	Bullet::Bullet(const int spriteID, int x, int y, Direction initialDirection, int initialImageID, const int initialSpriteOffset_X, const int initialSpriteOffset_Y) : SpriteObject(spriteID, x, y, initialImageID)
	{
		//Define initial state variables
		CurrentDirection = initialDirection;
		Collided = false;

		//Rotate and re-position the bullet, in relation to the firing party, as needed
		if(CurrentDirection == up || CurrentDirection == down)
		{
			dbRotateSprite(SpriteID, 90.f);
			SpriteOffset_Y = initialSpriteOffset_X;
		}
		else
			SpriteOffset_Y = initialSpriteOffset_Y;
	}


	//Positioning Methods
	void Bullet::MoveBullet(const std::map<Tile, NearbyWalls>& WallsMap)
	{
		//Prepare a coordinate to pass to the Move method (like a 2d vector)
		Coordinate mover = PrepareMove();

		//If the move fails (i.e. the bullet contacts a wall), set the collision token appropriately
		if(!Move(WallsMap, mover))
		{
			Collided = true;
		}
	}

	Coordinate Bullet::PrepareMove()
	{
		//Simple switch statement translating direction to a coordinate vector
		switch (CurrentDirection)
		{
		case left:
			return Coordinate(-BULLET_VELOCITY, 0);
			break;
		case right:
			return Coordinate(BULLET_VELOCITY, 0);
			break;
		case up:
			return Coordinate(0, -BULLET_VELOCITY);
			break;
		case down:
			return Coordinate(0, BULLET_VELOCITY);
			break;
		}
		return Coordinate(0, 0);
	}


	//Access Methods
	bool Bullet::GetCollisionState() const
	{
		return Collided;
	}