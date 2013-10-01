//WallsMap.h - JailBreak Walls Mapping Functions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128


#pragma once

#include "DarkGDK.h"
#include "Definitions.h"
#include "SimpleStructs.h"

#include <map>

class Walls
{
public:
	Walls()
	{
	SetupWallMap(wallsMap);
	}

	void SetUpWallMap(std::map<Tile, NearbyWalls>& wallsMap)
{
	//Column 1
	wallsMap[Tile(1,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_LEFT,0);
	wallsMap[Tile(1,2)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,3)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,4)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,5)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,6)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,7)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A);
	wallsMap[Tile(1,8)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_B);
	wallsMap[Tile(1,10)] = NearbyWalls(SPRITE_WALL_LEFT, SPRITE_WALL_INNER_B, SPRITE_WALL_BOTTOM);

	//Column 2
	wallsMap[Tile(2,1)] = NearbyWalls(SPRITE_WALL_TOP);
	wallsMap[Tile(2,2)] = NearbyWalls(SPRITE_WALL_INNER_A);
	wallsMap[Tile(2,8)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_B);
	wallsMap[Tile(2,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_B);

	//Column 3
	wallsMap[Tile(3,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_C);
	wallsMap[Tile(3,2)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
	wallsMap[Tile(3,3)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
	wallsMap[Tile(3,4)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C);
	wallsMap[Tile(3,5)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_D);
	wallsMap[Tile(3,6)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D);
	wallsMap[Tile(3,7)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D);
	wallsMap[Tile(3,8)] = NearbyWalls(SPRITE_WALL_INNER_A, SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_B);
	wallsMap[Tile(3,9)] = NearbyWalls(SPRITE_WALL_INNER_B, SPRITE_WALL_INNER_D);
	wallsMap[Tile(3,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_B, SPRITE_WALL_INNER_D);

	//Column 4
	wallsMap[Tile(4,5)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_D);
	wallsMap[Tile(4,10)] = NearbyWalls(SPRITE_WALL_BOTTOM, SPRITE_WALL_INNER_D);

	//Column 5
	wallsMap[Tile(5,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E);
	wallsMap[Tile(5,2)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E);
	wallsMap[Tile(5,3)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F);
	wallsMap[Tile(5,4)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_F);
	wallsMap[Tile(5,5)] = NearbyWalls(SPRITE_WALL_INNER_C, SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
	wallsMap[Tile(5,6)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
	wallsMap[Tile(5,7)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D);
	wallsMap[Tile(5,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G);
	wallsMap[Tile(5,9)] = NearbyWalls(SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G);
	wallsMap[Tile(5,10)] = NearbyWalls(SPRITE_WALL_INNER_D, SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

	//Column 6
	wallsMap[Tile(6,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
	wallsMap[Tile(6,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F);
	wallsMap[Tile(6,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_G);
	wallsMap[Tile(6,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

	//Column 7
	wallsMap[Tile(7,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
	wallsMap[Tile(7,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_F);
	wallsMap[Tile(7,4)] = NearbyWalls(SPRITE_WALL_INNER_F);
	wallsMap[Tile(7,5)] = NearbyWalls(SPRITE_WALL_INNER_F);
	wallsMap[Tile(7,6)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I);
	wallsMap[Tile(7,7)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I);
	wallsMap[Tile(7,8)] = NearbyWalls(SPRITE_WALL_INNER_F, SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
	wallsMap[Tile(7,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);


	//Column 8
	wallsMap[Tile(8,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E);
	wallsMap[Tile(8,3)] = NearbyWalls(SPRITE_WALL_INNER_E);
	wallsMap[Tile(8,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
	wallsMap[Tile(8,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
	wallsMap[Tile(8,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);


	//Column 9
	wallsMap[Tile(9,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H);
	wallsMap[Tile(9,2)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H);
	wallsMap[Tile(9,3)] = NearbyWalls(SPRITE_WALL_INNER_E, SPRITE_WALL_INNER_H);
	wallsMap[Tile(9,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
	wallsMap[Tile(9,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_G);
	wallsMap[Tile(9,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_BOTTOM);

	//Column 10
	wallsMap[Tile(10,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H);
	wallsMap[Tile(10,3)] = NearbyWalls(SPRITE_WALL_INNER_H);
	wallsMap[Tile(10,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
	wallsMap[Tile(10,8)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_G);
	wallsMap[Tile(10,9)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_INNER_J);
	wallsMap[Tile(10,10)] = NearbyWalls(SPRITE_WALL_INNER_G, SPRITE_WALL_INNER_J, SPRITE_WALL_BOTTOM);

	//Column 11
	wallsMap[Tile(11,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H);
	wallsMap[Tile(11,3)] = NearbyWalls(SPRITE_WALL_INNER_H);
	wallsMap[Tile(11,6)] = NearbyWalls(SPRITE_WALL_INNER_I);
	wallsMap[Tile(11,10)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_BOTTOM);

	//Column 12
	wallsMap[Tile(12,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_H, SPRITE_WALL_INNER_K);
	wallsMap[Tile(12,2)] = NearbyWalls(SPRITE_WALL_INNER_H, SPRITE_WALL_INNER_K);
	wallsMap[Tile(12,3)] = NearbyWalls(SPRITE_WALL_INNER_K);
	wallsMap[Tile(12,4)] = NearbyWalls(SPRITE_WALL_INNER_K);
	wallsMap[Tile(12,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_M);
	wallsMap[Tile(12,6)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_N);
	wallsMap[Tile(12,7)] = NearbyWalls(SPRITE_WALL_INNER_I, SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_J);
	wallsMap[Tile(12,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P);	
	wallsMap[Tile(12,9)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P);
	wallsMap[Tile(12,10)] = NearbyWalls(SPRITE_WALL_INNER_J, SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

	//Column 13
	wallsMap[Tile(13,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_K);
	wallsMap[Tile(13,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_M);
	wallsMap[Tile(13,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_P);
	wallsMap[Tile(13,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

	//Column 14
	wallsMap[Tile(14,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_Q);
	wallsMap[Tile(14,2)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_Q);
	wallsMap[Tile(14,3)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_Q);
	wallsMap[Tile(14,5)] = NearbyWalls(SPRITE_WALL_INNER_K, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_M);
	wallsMap[Tile(14,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_O);
	wallsMap[Tile(14,8)] = NearbyWalls(SPRITE_WALL_INNER_N, SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P);
	wallsMap[Tile(14,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

	//Column 15
	wallsMap[Tile(15,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_Q);
	wallsMap[Tile(15,3)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R);
	wallsMap[Tile(15,4)] = NearbyWalls(SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R);
	wallsMap[Tile(15,5)] = NearbyWalls(SPRITE_WALL_INNER_L, SPRITE_WALL_INNER_R, SPRITE_WALL_INNER_M);
	wallsMap[Tile(15,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_O);
	wallsMap[Tile(15,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_BOTTOM);

	//Column 16
	wallsMap[Tile(16,1)] = NearbyWalls(SPRITE_WALL_TOP, SPRITE_WALL_INNER_Q, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,2)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,3)] = NearbyWalls(SPRITE_WALL_INNER_Q, SPRITE_WALL_INNER_R, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,5)] = NearbyWalls(SPRITE_WALL_INNER_R, SPRITE_WALL_INNER_M, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,6)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,7)] = NearbyWalls(SPRITE_WALL_INNER_M, SPRITE_WALL_INNER_O, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,8)] = NearbyWalls(SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,9)] = NearbyWalls(SPRITE_WALL_INNER_O, SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT);
	wallsMap[Tile(16,10)] = NearbyWalls(SPRITE_WALL_INNER_P, SPRITE_WALL_RIGHT, SPRITE_WALL_BOTTOM);

	Tile currentTile;
	


	//For any tile, up to a maximum of 3 nearby walls are defined, where wall B cannot be meaningful
	//without A being meaningful (a nearby wall subvalue of 0 indactes no wall to check)
	//Thus, the checks are nested, such that collision checks occur a minimum number of times



}

	void SetUpWalls()
{
	
	//Setup Background
	dbSprite(SPRITE_BACKGROUND, 0, 0, IMG_BACKGROUND);

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
	dbStretchSprite(SPRITE_WALL_INNER_I, 400, 100);

	dbSprite(SPRITE_WALL_INNER_J, 624, 512, IMG_WALL);
	dbStretchSprite(SPRITE_WALL_INNER_J, 100, 200);

	dbSprite(SPRITE_WALL_INNER_K, 736, 128, IMG_WALL);
	dbStretchSprite(SPRITE_WALL_INNER_K, 100, 300);

	dbSprite(SPRITE_WALL_INNER_L, 792, 256, IMG_WALL);

	dbSprite(SPRITE_WALL_INNER_M, 736, 384, IMG_WALL);
	dbStretchSprite(SPRITE_WALL_INNER_M, 300, 100);

	dbSprite(SPRITE_WALL_INNER_N, 736, 448, IMG_WALL);

	dbSprite(SPRITE_WALL_INNER_O, 848, 512, IMG_WALL);

	dbSprite(SPRITE_WALL_INNER_P, 736, 576, IMG_WALL);
	dbStretchSprite(SPRITE_WALL_INNER_P, 300, 100);

	dbSprite(SPRITE_WALL_INNER_Q, 848, 128, IMG_WALL);

	dbSprite(SPRITE_WALL_INNER_R, 906, 256, IMG_WALL);
}

	void MovePlayer(int& playerX, int& playerY)
{
	if(dbUpKey() == 1)
		playerY-=2;
	if(dbDownKey() ==1)
		playerY+=2;
	if(dbLeftKey() ==1)
		playerX-=2;
	if(dbRightKey() ==1)
		playerX+=2;
		

	dbSprite(SPRITE_PLAYER, playerX, playerY, IMG_PLAYER_STAND);



}


	static map<Tile, NearbyWalls> wallsMap;
}