//Gun.h - Gun Subclass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "SpriteObject.h"

// Gun is a subclass of SpriteObject
class Gun: public SpriteObject
{
public:

	//Constructors
	Gun();
	//The gun is always initialised to a tile position, passed as a coordinate (from a random list or at a dummy position)
	Gun(const int spriteID, const Coordinate startingPosition, int initialImageID = IMG_GUN_1);

	//Management Methods
	void Hide();
	void Update(unsigned int player);

	//Animation Method
	void Animate();

	//Access Methods
	bool GetCollisionState() const;
	bool GetHiddenState() const;
	void SetCollisionStateTrue();
	void SetCollisionStateFalse();


private:
	bool Hidden;
	bool Collided;
	unsigned int FSLAnimation;
	Direction CurrentDirection;
};
