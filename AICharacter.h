//AICharacter.h - AI Character SuperClass Header
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "SimpleStructs.h"
#include "StateTools.h"
#include "DarkGDK.h"
#include "SpriteObject.h"



class AICharacter : public SpriteObject
{
public:
	//init-Constructor
	AICharacter() : SpriteObject() {}

	AICharacter(const int spriteID, const int x, const int y, int initialImageID, Direction initialDirection, unsigned int velocity, int initialSpriteOffset_X = 0, int initialSpriteOffset_Y = 0) : SpriteObject(spriteID, x, y, initialImageID, initialSpriteOffset_X, initialSpriteOffset_Y)
	{
		//Argument-Passed Variables
		CurrentDirection = initialDirection;
		Velocity = velocity;

		//Non-Specified State Variables
		FSLAnimation = 0;
		FSDeath = 0;
		FSLDeathAnimation = 0;
		CollidedWithPlayer = false;
		IsDead = false;
		Respawn = false;
	}



	//Navigation Methods
	virtual void ChooseTurn(const std::map<Coordinate, PossibleTurns>& TurnsMap, bool CanStop = false)
	{	
		PossibleTurns turns = TurnsMap.find(Position)->second;
		Direction Last = CurrentDirection;
		switch(dbRND(3))//Choose a direction to turn, from a random seed
			{
			case 0:
				CurrentDirection = turns.A;
				break;
			case 1:
				CurrentDirection = turns.B;
				break;
			case 2:
				CurrentDirection = turns.C;
				break;
			case 3:
				CurrentDirection = turns.D;
				break;
			}
			if(CurrentDirection == none && !CanStop)//If the random choice was not to turn, reset the CurrentDirection
				CurrentDirection = Last;
	}

	virtual Coordinate PrepareMove()
	{
		switch (CurrentDirection)
		{
		case left:
			return Coordinate(-int(Velocity), 0);
			break;
		case right:
			return Coordinate(Velocity, 0);
			break;
		case up:
			return Coordinate(0, -int(Velocity));
			break;
		case down:
			return Coordinate(0, Velocity);
			break;
		}
		return Coordinate(0, 0);
	}
	
	virtual void MoveAICharacter(const std::map<Tile, NearbyWalls>& WallsMap, const std::map<Coordinate, PossibleTurns>& TurnsMap)
	{
		//If the AI Character isn't dead, move it
		if(!IsDead)
		{
			//Each time the AI enters an intersection, change the current direction
			if(TurnsMap.find(Position) != TurnsMap.end())
			{
				ChooseTurn(TurnsMap);
			}

			//If moving in one direction hits a wall, start moving in the opposite direction instead (allows bouncing)
			if(!Move(WallsMap, PrepareMove()))
			{
				switch (CurrentDirection)
				{
				case left:
					CurrentDirection = right;
					break;
				case right:
					CurrentDirection = left;
					break;
				case up:
					CurrentDirection = down;
					break;
				case down:
					CurrentDirection = up;
					break;
				}
				Move(WallsMap, PrepareMove());
			}
			Animate();
		}
		else //If the AI character is dead, call its death animation method
			DeathAnimate();
	}

	virtual void CheckCollisionStateWithPlayer(const Tile& PlayerLocale)
	{
		if(PlayerLocale == Locale)
		{
			CollidedWithPlayer = true;
			return;
		}
		else
			CollidedWithPlayer = false;
	}

	virtual void DeathAnimate() = 0;

	virtual void Animate() = 0;



	//Access Methods
	virtual bool GetCollisionStateWithPlayer() const
	{
		return CollidedWithPlayer;
	}

	virtual void SetCollisionStateWithPlayerTrue()
	{
		CollidedWithPlayer = true;
	}

	virtual void SetCollisionStateWithPlayerFalse()
	{
		CollidedWithPlayer = false;
	}

	virtual bool GetDeathState() const
	{
		return IsDead;
	}

	virtual void SetDeathStateTrue()
	{
		IsDead = true;
	}

	virtual bool GetRespawnRequest() const
	{
		return Respawn;
	}




protected:
	Direction CurrentDirection;
	unsigned int Velocity;
	bool CollidedWithPlayer;
	bool IsDead;
	bool Respawn;
	unsigned int FSLAnimation;
	unsigned int FSDeath;
	unsigned int FSLDeathAnimation;
};