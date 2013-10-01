//StateTools.h - Jailbreak Control State Utilities Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once
#include "SimpleStructs.h"
#include "DarkGDK.h"
#include "Definitions.h"

//Enum for directional keypress states
enum KeyArrowPress{upPressed, downPressed, leftPressed, rightPressed, noPressed};

class StateTools
{
public:
	//Returns a cardinal direction based upon keyboard input (allows switch statements elsewhere, filters/disallows diagonal movement)
	KeyArrowPress MainDirectionKeyInput();

	//Similar to above, for w/a/s/d keys
	KeyArrowPress SecondaryDirectionKeyInput();
};