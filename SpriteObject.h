//SpriteObject.h - SpriteObject SuperClass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "SimpleStructs.h"
#include "StateTools.h"
#include "DarkGDK.h"

class SpriteObject
{
public:
	SpriteObject(){}

	//init-Constructors
	SpriteObject(const int spriteID, const int initialX, const int initialY, int initialImageID, int initialSpriteOffset_X = 0, int initialSpriteOffset_Y = 0)
	{
		Position.X = initialX;
		Position.Y = initialY;
		SpriteOffset_X = initialSpriteOffset_X;
		SpriteOffset_Y = initialSpriteOffset_Y;
		UniversalInitRoutine(spriteID, initialImageID);
	}

	SpriteObject(const int spriteID, const Coordinate initialCoordinate, int initialImageID, int initialSpriteOffset_X = 0, int initialSpriteOffset_Y = 0)
	{
		Position = initialCoordinate;
		SpriteOffset_X = initialSpriteOffset_X;
		SpriteOffset_Y = initialSpriteOffset_Y;
		UniversalInitRoutine(spriteID, initialImageID);
	}

	//Common Init Routine
	void UniversalInitRoutine(int spriteID, int initialImageID)
	{
		CurrentImageID = initialImageID;
		SpriteID = spriteID;
		UpdateLocale();
		DrawSprite();
	}


	
	//Management Methods
	virtual void DrawSprite()
	{
		dbSprite(SpriteID, Position.X, Position.Y, CurrentImageID);
		dbOffsetSprite(SpriteID, SpriteOffset_X, SpriteOffset_Y);
	}

	virtual void UpdateLocale()
	 {
		Locale.IndexX = 1 + TrueX(SpriteID)/56;
		Locale.IndexY = 1 + TrueY(SpriteID)/64;
	 }

	virtual bool Move(const std::map<Tile, NearbyWalls>& WallsMap, const Coordinate move)
	{
		Position.X+=move.X;
		Position.Y+=move.Y;

		DrawSprite();

		if(WallCollision(WallsMap))
		{
			Position.X-=move.X;
			Position.Y-=move.Y;
			DrawSprite();
			return false;
		}
		else
		{
			UpdateLocale();
			return true;
		}
	}

	virtual bool WallCollision(const std::map<Tile, NearbyWalls>& WallsMap)
	{
		//first, we check for a collison with the safehouse
		if(dbSpriteCollision(SpriteID, SPRITE_SAFEHOUSE) && SpriteID != SPRITE_PLAYER)
			return true;
		//For any tile, up to a maximum of 3 nearby walls are defined, where wall B cannot be meaningful
		//without A being meaningful (a nearby wall subvalue of 0 indactes no wall to check)
		//Thus, the checks are nested, such that collision checks occur a minimum number of times
		else if(WallsMap.find(Locale) != WallsMap.end())
		{
			NearbyWalls Neighborhood = WallsMap.find(Locale)->second;
			if(Neighborhood.WallID_A != 0)
			{
				if (dbSpriteCollision(SpriteID, Neighborhood.WallID_A) == 1)
				{
					return true;
				}
				else if (Neighborhood.WallID_B != 0)
				{
					if (dbSpriteCollision(SpriteID, Neighborhood.WallID_B) == 1)
					{
						return true;
					}
					else if(Neighborhood.WallID_C != 0)
					{
						if(dbSpriteCollision(SpriteID, Neighborhood.WallID_C) == 1)
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}



	//Utility Methods
	virtual int TrueX(const int spriteID) const
	{
		return dbSpriteX(spriteID)-GRID_JUSTIFICATION_X;
	}

	virtual int TrueY(const int spriteID) const
	{
		return dbSpriteY(spriteID)-GRID_JUSTIFICATION_Y;
	}



	//Access Methods
	virtual Coordinate GetPosition() const
	 {
		 return Position;
	 }

	virtual int GetSpriteID() const
	 {
		 return SpriteID;
	 }

	virtual Tile GetLocale() const
	 {
		 return Locale;
	 }




protected:
	Coordinate Position;
	Tile Locale;
	int SpriteID;
	int CurrentImageID;
	int SpriteOffset_X;
	int SpriteOffset_Y;
};