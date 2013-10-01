//Player.h - Player SubClass Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "SpriteObject.h"


//Player is a subclass of the SpriteObject Class - it's somewhat of an odd man out, since it
//is the only object controlled by the player. If the game was more complicated, it'd be worth
//setting up a multiple inheritence heirarchy for all characters vs. AI characters, but here, it
//would create more code than it would save.
class Player: public SpriteObject
{
public:
	//Constructors
	Player();
	Player(const int spriteID, const int x, const int y, int initialImageID, const unsigned int velocity);

	//Management Methods
	void MovePlayer(const std::map<Tile, NearbyWalls>& WallsMap);
	void FireDriection();

	//Animation Methods
	void Animate();
	void DeathAnimate();
	void StunAnimate();

	//Access Methods
	bool GetDeathState() const;
	void SetDeathStateTrue();
	bool GetStunnedState() const;
	void SetStunnedStateTrue();
	void SetShotsRemaining(unsigned int shotsRemaining);
	bool GetRespawnRequest() const;
	Direction GetLatestBulletDirection() const;
	Direction GetCurrentDirection() const;
	bool GetFiredState() const;
	unsigned int GetShotsRemaining() const;


//Data Members
private:
	unsigned int ShotsRemaining;
	bool Fired;
	bool IsDead;
	bool IsStunned;
	bool Respawn;
	Direction CurrentDirection;
	Direction LatestBulletDirection;
	unsigned int FSLAnimation;
	unsigned int FSLDeathAnimation;
	unsigned int FSLFire;
	unsigned int FSDeath;
	unsigned int FSStunned;
	unsigned int FSLStunAnimation;
	unsigned int Velocity;
	StateTools StateManager;
}; 