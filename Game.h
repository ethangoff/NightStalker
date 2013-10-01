//Game.h - JailBreak Game Management Class Declarations
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once

#include "Atlas.h"
#include "SimpleStructs.h"
#include "DebugTools.h"
#include "Player.h"
#include "FirstRobot.h"
#include "Bat.h"
#include "Spider.h"
#include "Gun.h"
#include "Bullet.h"

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <list>

class Game
{
public:
	Game();


	//Setup Methods
	void InitialSetup();
	void InitialLoad();
	void WindowSet();


	//Graphical Prompt / Non-Game Display Methods
	void SplashScreenA();
	void SplashScreenB();
	void SplashScreenC();
	void PauseScreen();
	void GameOver();
	
	
	//Core Game State Update Method
	void Update();


	//Object Creation / Initialization Methods
	void CheckRespawns();
	void SpawnNewPlayer();
	void SpawnNewRobot();
	void SpawnNewGun();
	void SpawnNewSpider();
	void SpawnNewBat(const unsigned int BatID);
	void RandomSpawn();
	
	//Object Management Methods
	void UpdatePlayer();
	void UpdateRobots();
	void UpdateSpiderAndBats();
	void PlayerFire();
	void RobotFire(FirstRobot& Bot);
	void BulletManagement(std::map <unsigned int, std::unique_ptr<Bullet>>& BulletMap);
	bool CheckForBulletCollisions(std::map <unsigned int, std::unique_ptr<Bullet>>& BulletMap, const int targetSpriteID);
	void CheckPlayerLife();
	void CheckRobotLife();
	void CheckSpiderLife();
	void CheckBatsLife();
	void GunManagement();


	//Title Bar Management Methods
	void ClearTitleBar();
	void SendRaw(int Input, const char* precedingLabel);
	void SyncTitleBar();


	//Access Members
	bool GetExitRequest();
	unsigned int GetScore();
	unsigned int GetRemainingLives();



//private:
//Data Members

	//Singluar Objects on Stack
	Player ActivePlayer;
	Gun ActiveGun;
	Spider ActiveSpider;
	Bat ActiveBat1;
	Bat ActiveBat2;

	//Because very few robots are ever on screen, vs bullets, and they are 
	//re-initialized infrequently, ostack storage is acceptable
	std::vector <FirstRobot> Robots;

	//Atlas (collection of representative maps for the playable screen)
	Atlas Maps;

	//Bullets are initialized on heap becuase they are created and destroyed
	//frequently, on the fly. A large quantity may be present at any time,
	//and utilizing maps allows for linear access/construction and logarithmic
	//destruction.
	std::map <unsigned int, std::unique_ptr<Bullet>> PlayerBullets;
	std::map <unsigned int, std::unique_ptr<Bullet>> RobotBullets;


	//POD Members
		//Offsets ensuring unique sprite ID's for multiplicative objects
	unsigned int BulletOffset;
	unsigned int RobotOffset;
		//State Variables
	bool ExitGame;
	unsigned int Lives;
	unsigned int Score;
		//Simple Window Title String
	char TitleText[100];
};