//Player.cpp - Player SubClass Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Player.h"


//Constructors
Player::Player() : SpriteObject() {}

Player::Player(const int spriteID, const int x, const int y, int initialImageID, const unsigned int velocity) : SpriteObject(spriteID, x, y, initialImageID)
{
	//Argument-Passed Init Variable
	Velocity = velocity;
	//Non-Argument Init Variables
	CurrentDirection = none;

	FSLFire = 0;
	FSLAnimation = 0;
	FSDeath = 0;
	FSLDeathAnimation = 31;
	FSStunned = 0;
	FSLStunAnimation = 0;

	LatestBulletDirection = none;
	ShotsRemaining = 0;
	Fired = false;
	Respawn = false;
	IsDead = false;
	IsStunned = false;
}



//Management Methods
void Player::MovePlayer(const std::map<Tile, NearbyWalls>& WallsMap)
{
	if(!IsDead && !IsStunned)
	{
		switch(StateManager.MainDirectionKeyInput()) //first we check for a key press
		{
		case upPressed:
			if(Move(WallsMap, Coordinate(0, -int(Velocity)))) //then we check to see if the move is valid (no collisions with walls)
			{
				if(CurrentDirection != up) //If the direction has changed, the animation clock gets reset
				{
					CurrentDirection = up;
					FSLAnimation = 0;
				}
				else
					FSLAnimation++;
			}
		break;

		case downPressed:
			if(Move(WallsMap, Coordinate(0, Velocity)))
			{
				if(CurrentDirection != down)
				{
					CurrentDirection = down;
					FSLAnimation = 0;
				}
				else
					FSLAnimation++;
			}
		break;

		case leftPressed:
			if(Move(WallsMap, Coordinate(-int(Velocity), 0)))
			{
				if(CurrentDirection != left)
				{
					CurrentDirection = left;
					FSLAnimation = 0;
				}
				else
					FSLAnimation++;
			}
		break;

		case rightPressed:
			if(Move(WallsMap, Coordinate(Velocity, 0)))
			{
				if(CurrentDirection != right)
				{
					CurrentDirection = right;
					FSLAnimation = 0;
				}
				else
					FSLAnimation++;
			}
		break;

		FSLAnimation = 0;
		}

	Animate();
	}
	else if(IsDead)
		DeathAnimate();
	else
		StunAnimate();
}

void Player::FireDriection()
{
	if(FSLFire > PLAYER_FIRE_PERIOD && ShotsRemaining > 0)
	{
		switch(StateManager.SecondaryDirectionKeyInput()) //first we check for a key press
		{
		case upPressed:
			Fired = true;
			LatestBulletDirection = up;
			FSLFire = 0;
			ShotsRemaining--;
			break;
		case downPressed:
			Fired = true;
			LatestBulletDirection = down;
			FSLFire = 0;
			ShotsRemaining--;
			break;
		case leftPressed:
			Fired = true;
			LatestBulletDirection = left;
			FSLFire = 0;
			ShotsRemaining--;
			break;
		case rightPressed:
			Fired = true;
			LatestBulletDirection = right;
			FSLFire = 0;
			ShotsRemaining--;
			break;
		case noPressed:
			Fired = false;
			LatestBulletDirection = none;
			FSLFire++;
			break;
		}
	}
	else
	{
		if(Fired)
			Fired = false;
		FSLFire++;
	}
}



//Animation Methods
void Player::Animate()
{
	if(FSLAnimation == 0)
		CurrentImageID = IMG_PLAYER_STAND;
	else if(FSLAnimation > 10)
	{
		FSLAnimation = 0;
		switch(CurrentDirection)
		{
		case up:
		case down:
			switch(CurrentImageID)
			{
			case IMG_PLAYER_STAND:
				CurrentImageID = IMG_PLAYER_UP;
				break;
			case IMG_PLAYER_UP:
				CurrentImageID = IMG_PLAYER_DOWN;
				break;
			case IMG_PLAYER_DOWN:
				CurrentImageID = IMG_PLAYER_UP;
			}
			break;
		case left:
			switch(CurrentImageID)
			{
			case IMG_PLAYER_STAND:
				CurrentImageID = IMG_PLAYER_LEFT1;
				break;
			case IMG_PLAYER_LEFT1:
				CurrentImageID = IMG_PLAYER_LEFT2;
				break;
			case IMG_PLAYER_LEFT2:
				CurrentImageID = IMG_PLAYER_LEFT1;
				break;
			}
			break;
		case right:
			switch(CurrentImageID)
			{
			case IMG_PLAYER_STAND:
				CurrentImageID = IMG_PLAYER_RIGHT1;
				break;
			case IMG_PLAYER_RIGHT1:
				CurrentImageID = IMG_PLAYER_RIGHT2;
				break;
			case IMG_PLAYER_RIGHT2:
				CurrentImageID = IMG_PLAYER_RIGHT1;
				break;
			}
			break;
		}
	}
}

void Player::DeathAnimate()
{
	FSDeath++;
	FSLDeathAnimation++;
	if(FSDeath < 3*FRAME_RATE)
	{
		if(FSLDeathAnimation > FRAME_RATE/2)
		{
			switch(CurrentImageID)
			{
			case IMG_PLAYER_STAND:
			case IMG_PLAYER_UP:
			case IMG_PLAYER_DOWN:
			case IMG_PLAYER_LEFT1:
			case IMG_PLAYER_LEFT2:
			case IMG_PLAYER_RIGHT1:
			case IMG_PLAYER_RIGHT2:
				CurrentImageID = IMG_PLAYER_DEAD1;
				break;
			case IMG_PLAYER_DEAD1:
				CurrentImageID = IMG_PLAYER_DEAD2;
				break;
			case IMG_PLAYER_DEAD2:
				CurrentImageID = IMG_PLAYER_DEAD1;
			}
			FSLDeathAnimation = 0;
		}
		DrawSprite();
	}
	else
	{
		Respawn = true;
	}
}

void Player::StunAnimate()
{
	FSStunned++;
	FSLStunAnimation++;
	if(FSStunned < 2*FRAME_RATE)
	{
		CurrentImageID = IMG_PLAYER_STUN1 + (FSStunned/15);
		SpriteOffset_X = STUN_ANIMATION_OFFSET;
		DrawSprite();
	}
	else if(FSStunned < 4*FRAME_RATE)
		DrawSprite();
	else
	{
		CurrentImageID = IMG_PLAYER_STAND;
		FSStunned = 0;
		FSLStunAnimation = 0;
		SpriteOffset_X = 0;
		IsStunned = false;
		DrawSprite();
//			ResetStunned = true;
	}

}



//Access Methods
bool Player::GetDeathState() const
{
	return IsDead;
}

void Player::SetDeathStateTrue()
{
	IsDead = true;
}

bool Player::GetStunnedState() const
{
	return IsStunned;
}

void Player::SetStunnedStateTrue()
{
	IsStunned = true;
}

void Player::SetShotsRemaining(unsigned int shotsRemaining)
{
	ShotsRemaining = shotsRemaining;
}

bool Player::GetRespawnRequest() const
{
	return Respawn;
}

Direction Player::GetLatestBulletDirection() const
{
	return LatestBulletDirection;
}

Direction Player::GetCurrentDirection() const
{
	return LatestBulletDirection;
}

bool Player::GetFiredState() const
{
	return Fired;
}

unsigned int Player::GetShotsRemaining() const
{
	return ShotsRemaining;
}