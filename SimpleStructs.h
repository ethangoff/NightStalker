//SimpleStructs.h - JailBreak Commonly Used Structs Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once
#include "StateTools.h"
#include "Definitions.h"

#include <map>

enum Direction {up, right, down, left, none};

//The tile struct represents one "tile" on the grid of the map - used for initial positioning, efficient collision mapping, and AI aiming
struct Tile
{
	int IndexX; 
	int IndexY;


	Tile(int indexX=1, int indexY=1);


	//Comparison operators
	bool operator==(const Tile& compareTo) const;
	bool operator!=(const Tile& compareTo) const;
	//The less than operator is utilized solely by the std::map container
	bool operator<(const Tile& compareTo) const;
};

//This struct is utilized in the map container used to efficiently check for possible collisions with the map's walls
//in the scope of the program, it's contents are SpriteIDs used by darkGDK. At any tile, a maximum of three wall sprites
//are checked by the WallCollision method for collisions with a target sprite, like an AI or the player
struct NearbyWalls
{
	unsigned int WallID_A;
	unsigned int WallID_B;
	unsigned int WallID_C;

	NearbyWalls(unsigned int a=0, unsigned int b=0, unsigned int c=0);

};

//This struct is utilized by the robot's navigation AI in determining directions possible at any intersection
struct PossibleTurns 
{
	PossibleTurns(Direction a = none, Direction b = none, Direction c = none, Direction d = none);

	Direction A;
	Direction B;
	Direction C;
	Direction D;

};

//A simple 2-D coordinate struct, used throughout the game for positioning
struct Coordinate 
{
	int X; 
	int Y;

	Coordinate();

	//Constructors excepting a tile or 2d arguments
	Coordinate(Tile Input);

	Coordinate(int x, int y);
	

	//Arithmetic operators
	Coordinate operator-() const;
	void operator+(const Coordinate& compareTo);
	void operator=(const Coordinate& compareTo);

	//Comparison Operators
	bool operator==(const Coordinate& compareTo) const;
	//The less than operator is utilized solely by the std::map container
	bool operator<(const Coordinate& compareTo) const;
};