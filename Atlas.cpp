//Atlas.cpp - JailBreak Atlas Class Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128


#pragma once

#include "DarkGDK.h"
#include "Definitions.h"
#include "SimpleStructs.h"
#include "Atlas.h"

#include <map>


std::map<Tile, NearbyWalls> Atlas::WallsMap;
std::map<Coordinate, PossibleTurns> Atlas::RobotTurnSpots;

	Atlas::Atlas()
	{
		if(WallsMap.size() ==0)
		{
			SetUpWallMap();
			SetUpRobotTurnSpots();
		}
	}

	//Populate the map containing wall information for collision detection
	void Atlas::SetUpWallMap()
	{
		//Column 1
		WallsMap[Tile(1,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_LEFT,0);
		WallsMap[Tile(1,2)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,3)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,4)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,5)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,6)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,7)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
		WallsMap[Tile(1,8)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_B);
		WallsMap[Tile(1,9)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_B);
		WallsMap[Tile(1,10)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_B, SPRITE_WALL_BOTTOM);

		//Column 2
		WallsMap[Tile(2,1)] = NearbyWalls(SPRITE_WALL_TOP);
		WallsMap[Tile(2,2)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,3)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,4)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,5)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,6)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,7)] = NearbyWalls(SPRITE_WALL_INNER_A);
		WallsMap[Tile(2,8)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_B);
		WallsMap[Tile(2,9)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_B);
		WallsMap[Tile(2,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_B);

		//Column 3
		WallsMap[Tile(3,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_C);
		WallsMap[Tile(3,2)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
		WallsMap[Tile(3,3)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
		WallsMap[Tile(3,4)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
		WallsMap[Tile(3,5)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_D);
		WallsMap[Tile(3,6)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D);
		WallsMap[Tile(3,7)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D);
		WallsMap[Tile(3,8)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_B);
		WallsMap[Tile(3,9)] = NearbyWalls(SPRITE_WALL_INNER_B, SPRITE_WALL_INNER_D);
		WallsMap[Tile(3,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_B, SPRITE_WALL_INNER_D);

		//Column 4
		WallsMap[Tile(4,1)] = NearbyWalls(SPRITE_WALL_INNER_C);
		WallsMap[Tile(4,2)] = NearbyWalls(SPRITE_WALL_INNER_C);
		WallsMap[Tile(4,3)] = NearbyWalls(SPRITE_WALL_INNER_C);
		WallsMap[Tile(4,4)] = NearbyWalls(SPRITE_WALL_INNER_C);
		WallsMap[Tile(4,5)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_D);
		WallsMap[Tile(4,6)] = NearbyWalls(SPRITE_WALL_INNER_D);
		WallsMap[Tile(4,7)] = NearbyWalls(SPRITE_WALL_INNER_D);
		WallsMap[Tile(4,8)] = NearbyWalls(SPRITE_WALL_INNER_D);
		WallsMap[Tile(4,9)] = NearbyWalls(SPRITE_WALL_INNER_D);
		WallsMap[Tile(4,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_D);

		//Column 5
		WallsMap[Tile(5,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E);
		WallsMap[Tile(5,2)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E);
		WallsMap[Tile(5,3)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F);
		WallsMap[Tile(5,4)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_F);
		WallsMap[Tile(5,5)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
		WallsMap[Tile(5,6)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
		WallsMap[Tile(5,7)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
		WallsMap[Tile(5,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G);
		WallsMap[Tile(5,9)] = NearbyWalls(SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G);
		WallsMap[Tile(5,10)] = NearbyWalls(SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

		//Column 6
		WallsMap[Tile(6,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
		WallsMap[Tile(6,2)] = NearbyWalls(SPRITE_WALL_INNER_E);
		WallsMap[Tile(6,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F);
		WallsMap[Tile(6,4)] = NearbyWalls(SPRITE_WALL_INNER_F);
		WallsMap[Tile(6,5)] = NearbyWalls(SPRITE_WALL_INNER_F);
		WallsMap[Tile(6,6)] = NearbyWalls(SPRITE_WALL_INNER_F);
		WallsMap[Tile(6,7)] = NearbyWalls(SPRITE_WALL_INNER_F);
		WallsMap[Tile(6,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_G);
		WallsMap[Tile(6,9)] = NearbyWalls(SPRITE_WALL_INNER_G);
		WallsMap[Tile(6,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

		//Column 7
		WallsMap[Tile(7,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
		WallsMap[Tile(7,2)] = NearbyWalls(SPRITE_WALL_INNER_E);
		WallsMap[Tile(7,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F, SPRITE_WALL_SAFEHOUSE_LEFT);
		WallsMap[Tile(7,4)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_SAFEHOUSE_LEFT);
		WallsMap[Tile(7,5)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_SAFEHOUSE_LEFT);
		WallsMap[Tile(7,6)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I, SPRITE_WALL_SAFEHOUSE_LEFT);
		WallsMap[Tile(7,7)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I);
		WallsMap[Tile(7,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
		WallsMap[Tile(7,9)] = NearbyWalls(SPRITE_WALL_INNER_G);
		WallsMap[Tile(7,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);


		//Column 8
		WallsMap[Tile(8,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
		WallsMap[Tile(8,2)] = NearbyWalls(SPRITE_WALL_INNER_E);
		WallsMap[Tile(8,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_SAFEHOUSE_TOPLEFT);
		WallsMap[Tile(8,4)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_LEFT, SPRITE_WALL_SAFEHOUSE_TOPLEFT);
		WallsMap[Tile(8,5)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_LEFT, SPRITE_WALL_SAFEHOUSE_BOTTOM);
		WallsMap[Tile(8,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(8,7)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(8,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
		WallsMap[Tile(8,9)] = NearbyWalls(SPRITE_WALL_INNER_G);
		WallsMap[Tile(8,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);


		//Column 9
		WallsMap[Tile(9,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H);
		WallsMap[Tile(9,2)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H);
		WallsMap[Tile(9,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H, SPRITE_WALL_SAFEHOUSE_TOPRIGHT);
		WallsMap[Tile(9,4)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_TOPLEFT, SPRITE_WALL_SAFEHOUSE_TOPRIGHT);
		WallsMap[Tile(9,5)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_BOTTOM);
		WallsMap[Tile(9,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(9,7)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(9,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
		WallsMap[Tile(9,9)] = NearbyWalls(SPRITE_WALL_INNER_G);
		WallsMap[Tile(9,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

		//Column 10
		WallsMap[Tile(10,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H);
		WallsMap[Tile(10,2)] = NearbyWalls(SPRITE_WALL_INNER_H);
		WallsMap[Tile(10,3)] = NearbyWalls(SPRITE_WALL_INNER_H, SPRITE_WALL_SAFEHOUSE_TOPRIGHT, SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(10,4)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_TOPRIGHT, SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(10,5)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_BOTTOM, SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(10,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(10,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_G);
		WallsMap[Tile(10,7)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(10,9)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_INNER_J);
		WallsMap[Tile(10,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_INNER_J, SPRITE_WALL_BOTTOM);

		//Column 11
		WallsMap[Tile(11,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H);
		WallsMap[Tile(11,2)] = NearbyWalls(SPRITE_WALL_INNER_H);
		WallsMap[Tile(11,3)] = NearbyWalls(SPRITE_WALL_INNER_H, SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(11,4)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(11,5)] = NearbyWalls(SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(11,6)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_SAFEHOUSE_RIGHT);
		WallsMap[Tile(11,7)] = NearbyWalls(SPRITE_WALL_INNER_I);
		WallsMap[Tile(11,8)] = NearbyWalls(SPRITE_WALL_INNER_J);
		WallsMap[Tile(11,9)] = NearbyWalls(SPRITE_WALL_INNER_J);
		WallsMap[Tile(11,10)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_BOTTOM);

		//Column 12
		WallsMap[Tile(12,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H, SPRITE_WALL_INNER_K);
		WallsMap[Tile(12,2)] = NearbyWalls(SPRITE_WALL_INNER_H, SPRITE_WALL_INNER_K);
		WallsMap[Tile(12,3)] = NearbyWalls(SPRITE_WALL_INNER_K);
		WallsMap[Tile(12,4)] = NearbyWalls(SPRITE_WALL_INNER_K);
		WallsMap[Tile(12,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_M);
		WallsMap[Tile(12,6)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_N);
		WallsMap[Tile(12,7)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_J);
		WallsMap[Tile(12,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P);	
		WallsMap[Tile(12,9)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P);
		WallsMap[Tile(12,10)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

		//Column 13
		WallsMap[Tile(13,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_K);
		WallsMap[Tile(13,2)] = NearbyWalls(SPRITE_WALL_INNER_K);
		WallsMap[Tile(13,3)] = NearbyWalls(SPRITE_WALL_INNER_K);
		WallsMap[Tile(13,4)] = NearbyWalls(SPRITE_WALL_INNER_K);
		WallsMap[Tile(13,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_M);
		WallsMap[Tile(13,6)] = NearbyWalls(SPRITE_WALL_INNER_M);
		WallsMap[Tile(13,7)] = NearbyWalls(SPRITE_WALL_INNER_N);
		WallsMap[Tile(13,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_P);
		WallsMap[Tile(13,9)] = NearbyWalls(SPRITE_WALL_INNER_P);
		WallsMap[Tile(13,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

		//Column 14
		WallsMap[Tile(14,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_Q);
		WallsMap[Tile(14,2)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_Q);
		WallsMap[Tile(14,3)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_Q);
		WallsMap[Tile(14,4)] = NearbyWalls(SPRITE_WALL_INNER_L);
		WallsMap[Tile(14,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_M);
		WallsMap[Tile(14,6)] = NearbyWalls(SPRITE_WALL_INNER_M);
		WallsMap[Tile(14,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_O);
		WallsMap[Tile(14,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P);
		WallsMap[Tile(14,9)] = NearbyWalls(SPRITE_WALL_INNER_P);
		WallsMap[Tile(14,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

		//Column 15
		WallsMap[Tile(15,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_Q);
		WallsMap[Tile(15,2)] = NearbyWalls(SPRITE_WALL_INNER_Q);
		WallsMap[Tile(15,3)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R);
		WallsMap[Tile(15,4)] = NearbyWalls(SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R);
		WallsMap[Tile(15,5)] = NearbyWalls(SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R, SPRITE_WALL_INNER_M);
		WallsMap[Tile(15,6)] = NearbyWalls(SPRITE_WALL_INNER_M);
		WallsMap[Tile(15,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_O);
		WallsMap[Tile(15,8)] = NearbyWalls(SPRITE_WALL_INNER_O);
		WallsMap[Tile(15,9)] = NearbyWalls(SPRITE_WALL_INNER_P);
		WallsMap[Tile(15,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

		//Column 16
		WallsMap[Tile(16,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_Q, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,2)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,3)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_INNER_R, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,4)] = NearbyWalls(SPRITE_WALL_INNER_R);
		WallsMap[Tile(16,5)] = NearbyWalls(SPRITE_WALL_INNER_R, SPRITE_WALL_INNER_M, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,6)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_O, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,8)] = NearbyWalls(SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,9)] = NearbyWalls(SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT);
		WallsMap[Tile(16,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT, SPRITE_WALL_BOTTOM);
	}

	//"Draw" the walls (they are hidden using a rbg transparency switch)
	void Atlas::SetUpWalls()
	{
		//Setup Background
		dbSprite(SPRITE_BACKGROUND, 0, 0, IMG_BACKGROUND);

		//Safehouse
		dbSprite(SPRITE_SAFEHOUSE, SAFEHOUSE_POSITION, IMG_SAFEHOUSE);
		dbSetSpritePriority(SPRITE_SAFEHOUSE, HIGH_PRIORITY);
		dbHideSprite(SPRITE_SAFEHOUSE);

		//Outline Walls

		dbSprite(SPRITE_WALL_TOP, 0,2, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_TOP, 1829, 100); 

		dbSprite(SPRITE_WALL_BOTTOM, 0,701, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_BOTTOM, 1829, 100); 
	
		dbSprite(SPRITE_WALL_LEFT, 9,55, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_LEFT, 100, 1100); 	
	
		dbSprite(SPRITE_WALL_RIGHT, 959,55, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_RIGHT, 100, 1100); 	

		//Inner Walls
		dbSprite(SPRITE_WALL_INNER_A, 119, 192, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_A, 100, 500); 	

		dbSprite(SPRITE_WALL_INNER_B, 65, 577, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_B, 200, 100);

		dbSprite(SPRITE_WALL_INNER_C, 232, 66, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_C, 100, 400);

		dbSprite(SPRITE_WALL_INNER_D, 232, 385, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_D, 100, 400);

		dbSprite(SPRITE_WALL_INNER_E, 344, 128, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_E, 300, 100);

		dbSprite(SPRITE_WALL_INNER_F, 344, 256, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_F, 100, 400);

		dbSprite(SPRITE_WALL_INNER_G, 344, 576, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_G, 400, 100);

		dbSprite(SPRITE_WALL_INNER_H, 568, 128, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_H, 200, 100);

		dbSprite(SPRITE_WALL_INNER_I, 456, 448, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_I, 400, 104);

		dbSprite(SPRITE_WALL_INNER_J, 624, 512, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_J, 100, 200);

		dbSprite(SPRITE_WALL_INNER_K, 736, 128, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_K, 100, 300);

		dbSprite(SPRITE_WALL_INNER_L, 792, 256, IMG_WALL);

		dbSprite(SPRITE_WALL_INNER_M, 736, 384, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_M, 300, 104);

		dbSprite(SPRITE_WALL_INNER_N, 736, 448, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_N, 100, 100);

		dbSprite(SPRITE_WALL_INNER_O, 848, 512, IMG_WALL);

		dbSprite(SPRITE_WALL_INNER_P, 736, 576, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_INNER_P, 300, 100);

		dbSprite(SPRITE_WALL_INNER_Q, 848, 128, IMG_WALL);

		dbSprite(SPRITE_WALL_INNER_R, 906, 256, IMG_WALL);

		dbSprite(SPRITE_WALL_SAFEHOUSE_BOTTOM, 454, 380, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_SAFEHOUSE_BOTTOM, 300, 10);

		dbSprite(SPRITE_WALL_SAFEHOUSE_LEFT, 454, 254, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_SAFEHOUSE_LEFT, 10, 200);

		dbSprite(SPRITE_WALL_SAFEHOUSE_RIGHT, 622, 254, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_SAFEHOUSE_RIGHT, 10, 200);

		dbSprite(SPRITE_WALL_SAFEHOUSE_TOPLEFT, 454, 254, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_SAFEHOUSE_TOPLEFT, 100, 10);

		dbSprite(SPRITE_WALL_SAFEHOUSE_TOPRIGHT, 568, 254, IMG_WALL);
		dbStretchSprite(SPRITE_WALL_SAFEHOUSE_TOPRIGHT, 100, 10);
	}

	//Populate the map containing information for basic AI navigation
	void Atlas::SetUpRobotTurnSpots()
	{
		//The AI characters are designed to randomnly turn (or keep going straight) at every
		//possible intersection of navigatable paths. Because the choice to turn should only
		//happen once at each intersection, the map correlates coordinates, not entire tiles,
		//to the possible turns. This way, the map can be utilized with a simple look-up based
		//upon an AI Character's position each frame.

		RobotTurnSpots[Coordinate(Tile(1,1))] = PossibleTurns(right, down);
		RobotTurnSpots[Coordinate(Tile(1,2))] = PossibleTurns(right, down, up);
		RobotTurnSpots[Coordinate(Tile(1,8))] = PossibleTurns(up, right);
		RobotTurnSpots[Coordinate(Tile(1,10))] = PossibleTurns(right);

		RobotTurnSpots[Coordinate(Tile(3,1))] = PossibleTurns(left, down);
		RobotTurnSpots[Coordinate(Tile(3,2))] = PossibleTurns(left, down, up);
		RobotTurnSpots[Coordinate(Tile(3,5))] = PossibleTurns(left, left, left);
		RobotTurnSpots[Coordinate(Tile(3,8))] = PossibleTurns(left, up, down);
		RobotTurnSpots[Coordinate(Tile(3,10))] = PossibleTurns(right, left, up);

		RobotTurnSpots[Coordinate(Tile(5,1))] = PossibleTurns(right, down);
		RobotTurnSpots[Coordinate(Tile(5,3))] = PossibleTurns(up, right, down);
		RobotTurnSpots[Coordinate(Tile(5,5))] = PossibleTurns(up, left, down);
		RobotTurnSpots[Coordinate(Tile(5,8))] = PossibleTurns(up, right, down);
		RobotTurnSpots[Coordinate(Tile(5,10))] = PossibleTurns(up, left, right);

		RobotTurnSpots[Coordinate(Tile(7,3))] = PossibleTurns(left, right, down);
		RobotTurnSpots[Coordinate(Tile(7,6))] = PossibleTurns(up, right, down);
		RobotTurnSpots[Coordinate(Tile(7,8))] = PossibleTurns(up, left, right);

		RobotTurnSpots[Coordinate(Tile(9,1))] = PossibleTurns(left, right, down);
		RobotTurnSpots[Coordinate(Tile(9,3))] = PossibleTurns(left, right, down, up);
		RobotTurnSpots[Coordinate(Tile(9,6))] = PossibleTurns(left, right, up);

		RobotTurnSpots[Coordinate(Tile(10,8))] = PossibleTurns(left, down);
		RobotTurnSpots[Coordinate(Tile(10,10))] = PossibleTurns(left, right, up);

		RobotTurnSpots[Coordinate(Tile(12,1))] = PossibleTurns(left, right, down);
		RobotTurnSpots[Coordinate(Tile(12,3))] = PossibleTurns(left, up, down);
		RobotTurnSpots[Coordinate(Tile(12,5))] = PossibleTurns(left, right, down, up);
		RobotTurnSpots[Coordinate(Tile(12,6))] = PossibleTurns(left, up, down);
		RobotTurnSpots[Coordinate(Tile(12,8))] = PossibleTurns(right, up, down);
		RobotTurnSpots[Coordinate(Tile(12,10))] = PossibleTurns(left, up, right);

		RobotTurnSpots[Coordinate(Tile(14,1))] = PossibleTurns(left, right, down);
		RobotTurnSpots[Coordinate(Tile(14,3))] = PossibleTurns(up, right);
		RobotTurnSpots[Coordinate(Tile(14,7))] = PossibleTurns(down, right);
		RobotTurnSpots[Coordinate(Tile(14,8))] = PossibleTurns(up, left);

		RobotTurnSpots[Coordinate(Tile(15,3))] = PossibleTurns(down, right, left);
		RobotTurnSpots[Coordinate(Tile(15,5))] = PossibleTurns(up, right, left);

		RobotTurnSpots[Coordinate(Tile(16,1))] = PossibleTurns(down, left);
		RobotTurnSpots[Coordinate(Tile(16,3))] = PossibleTurns(up, left);
		RobotTurnSpots[Coordinate(Tile(16,5))] = PossibleTurns(down, left);
		RobotTurnSpots[Coordinate(Tile(16,7))] = PossibleTurns(up, down, left);
		RobotTurnSpots[Coordinate(Tile(16,10))] = PossibleTurns(up, left);
	}