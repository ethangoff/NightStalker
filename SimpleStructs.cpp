//SimpleStructs.cpp - JailBreak Commonly Used Structs Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once
#include "SimpleStructs.h"

//Tile Struct
	Tile::Tile(int indexX, int indexY)
	{
		IndexX = indexX;
		IndexY = indexY;
	}

	//Comparison operators
	bool Tile::operator==(const Tile& compareTo) const
	{
		return (IndexX == compareTo.IndexX && IndexY == compareTo.IndexY);	
	}

	bool Tile::operator!=(const Tile& compareTo) const
	{
		return (IndexX != compareTo.IndexX || IndexY != compareTo.IndexY);	
	}

	bool Tile::operator<(const Tile& compareTo) const
	{
		return (IndexX < compareTo.IndexX || (IndexX == compareTo.IndexX && IndexY<compareTo.IndexY));	
	}




//NearbyWalls Struct
	NearbyWalls::NearbyWalls(unsigned int a, unsigned int b, unsigned int c)
	{
		WallID_A = a;
		WallID_B = b;
		WallID_C = c;
	}




//PossibleTurns Struct
PossibleTurns::PossibleTurns(Direction a, Direction b, Direction c, Direction d) : A(a), B(b), C(c), D(d) {}




//Coordinate Struct
	Coordinate::Coordinate(){}

	//Constructors excepting a tile or 2d arguments
	Coordinate::Coordinate(Tile Input)
	{
		X = (Input.IndexX*56)+16;
		Y = (Input.IndexY*64)+8;
	}

	Coordinate::Coordinate(int x, int y) : X(x), Y(y){}
	

	//Arithmetic operators
	Coordinate Coordinate::operator-() const
	{
		return Coordinate(-X, -Y);	
	}

	void Coordinate::operator+(const Coordinate& compareTo)
	{
		X += compareTo.X;
		Y += compareTo.Y;	
	}
	
	void Coordinate::operator=(const Coordinate& compareTo)
	{
		X = compareTo.X;
		Y = compareTo.Y;	
	}


	//Comparison Operators
	bool Coordinate::operator==(const Coordinate& compareTo) const
	{
		return (X == compareTo.X && Y == compareTo.Y);	
	}

	//The less than operator is utilized solely by the std::map container
	bool Coordinate::operator<(const Coordinate& compareTo) const
	{
		return (X < compareTo.X || (X == compareTo.X && Y<compareTo.Y));	
	}