//Atlas.h - JailBreak Atlas Class Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128


#pragma once

#include "DarkGDK.h"
#include "Definitions.h"
#include "SimpleStructs.h"

#include <map>

class Atlas
{
public:

	Atlas();

	void SetUpWallMap();

	void SetUpWalls();

	void SetUpRobotTurnSpots();

	//The atlas contains a map of the walls and a map of intersections of paths navigatable by the AI characters
	static std::map<Tile, NearbyWalls> WallsMap;
	static std::map<Coordinate, PossibleTurns> RobotTurnSpots;
};