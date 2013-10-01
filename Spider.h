//Spider.h - Jailbreak Spider SubClass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "AICharacter.h"

//Spider is a SubClass of AICharacter, a SubClass of SpriteObject
class Spider : public AICharacter
{
public:
	//Constructors
	Spider();
	//Init-Constructor
	Spider(const int spriteID, const int x, const int y, int initialImageID, Direction initialDirection, const unsigned int velocity);


	//Animation Methods
	void DeathAnimate();
	void Animate();
};