//Bullet.h - Bullet SubClass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "SpriteObject.h"


// Bullet is a subclass of SpriteObject
class Bullet: public SpriteObject
{
public:
	//Constructors
	Bullet();
	Bullet(const int spriteID, const int x, const int y, Direction initialDirection, int initialImageID = IMG_BULLET1);
	Bullet(const int spriteID, const int x, const int y, Direction initialDirection, int initialImageID, const int initialSpriteOffset_X, const int initialSpriteOffset_Y);

	//Positioning Methods
	void MoveBullet(const std::map<Tile, NearbyWalls>& WallsMap);
	Coordinate PrepareMove();

	//Access Methods
	bool GetCollisionState() const;


//Data Members
private:
	bool Collided;
	Direction CurrentDirection;
};