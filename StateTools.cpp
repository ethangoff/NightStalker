//StateTools.h - Jailbreak Control State Utilities Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once
#include "StateTools.h"

	KeyArrowPress StateTools::MainDirectionKeyInput()
	{
		if(dbUpKey()==1)
			return upPressed;
		else if (dbDownKey() == 1)
			return downPressed;
		else if (dbLeftKey() == 1)
			return leftPressed;
		else if (dbRightKey() == 1)
			return rightPressed;
		else
			return noPressed;

	}

	KeyArrowPress StateTools::SecondaryDirectionKeyInput()
	{
		if(dbKeyState (W_KEYCODE))
			return upPressed;
		else if (dbKeyState (S_KEYCODE))
			return downPressed;
		else if (dbKeyState (A_KEYCODE))
			return leftPressed;
		else if (dbKeyState (D_KEYCODE))
			return rightPressed;
		else
			return noPressed;

	}