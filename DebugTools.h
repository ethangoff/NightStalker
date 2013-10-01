//DebugTools.h - JailBreak Debugging Routines
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128


#pragma once

#include "SimpleStructs.h"
#include "DarkGDK.h"
#include "StateTools.h"

#include <string>
#include <iostream>
#include <math.h>

class DebugTools
{
public:

	void SendRaw(int Input, char* precedingLabel = "  ", char* trailingLabel = "  ")
	{
		char debugTemp1[20] = " \0";

		strcat(TitleText, precedingLabel);
		std::sprintf(debugTemp1, "%d", Input);
		strcat(TitleText, debugTemp1);
		strcat(TitleText, trailingLabel);
	}

	void SendRaw(char* Input, char* precedingLabel = "  ", char* trailingLabel = "  ")
	{
		strcat(TitleText, precedingLabel);
		strcat(TitleText, Input);
		strcat(TitleText, trailingLabel);
	}

	void SendRaw(std::string& Input, char* precedingLabel = "  ", char* trailingLabel = "  ")
	{
		strcat(TitleText, precedingLabel);
		strcat(TitleText, Input.c_str());
		strcat(TitleText, trailingLabel);
	}

	int TrueX(int spriteID)
	{
		return dbSpriteX(spriteID)-GRID_JUSTIFICATION_X;
	}

	int TrueY(int spriteID)
	{
		return dbSpriteY(spriteID)-GRID_JUSTIFICATION_Y;
	}

	void SendCoordinate(int spriteID)
	{
		char debugTemp1[10] = " \0";
		char debugTemp2[10] = " \0";

		strcat(TitleText, "X:");
		std::sprintf(debugTemp1, "%d", TrueX(spriteID));
		strcat(TitleText, debugTemp1);

		strcat(TitleText, " | Y:");
		
		std::sprintf(debugTemp1, "%d", TrueY(spriteID));
		strcat(TitleText, debugTemp1);
	}

	void SendCoordinate(Coordinate Input)
	{
		char debugTemp1[20] = " \0";
		char debugTemp2[20] = " \0";

		strcat(TitleText, " Raw Coordinate: (");
		std::sprintf(debugTemp1, "%d", Input.X);
		strcat(TitleText, debugTemp1);
		strcat(TitleText, ",");
		std::sprintf(debugTemp1, "%d", Input.Y);
		strcat(TitleText, debugTemp1);
		strcat(TitleText, ")  ");
	}

	void SendLocation(int spriteID)
	{
		char debugTemp1[10] = " \0";
		char debugTemp2[10] = " \0";

		int tileX = 1 + TrueX(spriteID)/56;
		int tileY = 1 + TrueY(spriteID)/64;

		strcat(TitleText, " Current Tile: (");
		std::sprintf(debugTemp1, "%d", tileX);
		strcat(TitleText, debugTemp1);
		strcat(TitleText, ",");
		std::sprintf(debugTemp1, "%d", tileY);
		strcat(TitleText, debugTemp1);
		strcat(TitleText, ")  ");

	}

	void SendNeighborhood(NearbyWalls input)
	{
		char debugTemp1[10] = " \0";
		char debugTemp2[10] = " \0";
		
		strcat(TitleText, " Current Walls: (");
		std::sprintf(debugTemp1, "%d", input.WallID_A);
		strcat(TitleText, ", ");
		std::sprintf(debugTemp1, "%d", input.WallID_B);	
		strcat(TitleText, ", ");
		std::sprintf(debugTemp1, "%d", input.WallID_C);	
		strcat(TitleText, ") ");	
	}




	void CollisionDetect(int spriteID)
	{
		for (int i = SPRITE_WALL_TOP; i <= SPRITE_WALL_INNER_R; i++)
		{
			if (dbSpriteCollision(spriteID, i))
				dbShowSprite(i);
			else
				dbHideSprite(i);
		}
	}


	void ClearTitle()
	{
		TitleText[0] = '\0';
	}

	void UpdateTitle()
	{
		dbSetWindowTitle(TitleText);
	}


	char TitleText[100];
	StateTools StateManager;


};