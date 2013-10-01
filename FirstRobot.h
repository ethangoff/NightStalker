//FirstRobot.h - FirstRobot SubClass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "AICharacter.h"

//FirstRobot is a Subclass of AICharacter, a SubClass of SpriteObject
class FirstRobot : public AICharacter
{
public:
	//Constructors
	FirstRobot();
	FirstRobot(const int spriteID, const int x, const int y, int initialImageID, Direction initialDirection, const unsigned int velocity);


	//AI Aiming Management Method
	void Aim(Tile& PlayerLocale);


	//Animation Methods
	void Animate();
	void DeathAnimate();


	//Access Methods
	Direction GetFireDirection() const;



//Data Members
private:
	Direction FireDirection;
	unsigned int FSLFire;
	unsigned int FSLDeathAnimation;
};