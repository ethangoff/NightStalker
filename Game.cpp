//Game.cpp - JailBreak Game Management Class Definitions
//Written by Ethan Goff, April 2013
//Uses Dark GDK, http://www.thegamecreators.com/?m=view_product&id=2128

#pragma once
#include "Game.h"

typedef std::pair<int, std::unique_ptr<Bullet>> ActiveBullet;

Game::Game()
{
	InitialSetup();
}



//Setup Methods
void Game::InitialSetup()
{
	//Set the game managment state variables
	ExitGame = false;
	Lives = 5;
	Score = 0;
	BulletOffset = 0;
	RobotOffset = 0;

	//Seed the DarkGDK random int generator
	dbRandomize(dbTimer()); 

	//Disable the escape key as a standard kill-key (so pause functions correctly)
	dbDisableEscapeKey();

	//Set up application window
	WindowSet();
	
	//Display the title screen, to be shown during loading
	SplashScreenA();
	
	//Load images into memory for later use
	InitialLoad();
	
	//Draw the walls (they are transparent and thus will not appear on the pre-game screens)
	Maps.SetUpWalls();

	//Display a prompt to press anykey (and watch for this event)
	SplashScreenB();
	
	//Display the controls screen, and await the user to start the game
	SplashScreenC();

	//Set up the intial charactars
	SpawnNewPlayer();
	SpawnNewRobot();
	SpawnNewSpider();

	//Initialize a "dummy" gun (that will cooperate with the GunManagement method)
	ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(4,1)), IMG_GUN_1); //in a wall... doesn't really matter, it will be immeadiatley re-initialized
	ActiveGun.Hide();
}

void Game::InitialLoad()
{
	//Set a chroma key for transparency - allows use of bmps with psuedo-transparency, defined by an rbg value
	dbSetImageColorKey(RBG_TRANSPARENCY_KEY);
	
	//Preload Textures and Sprites
	dbLoadImage("Graphics\\Map.fw.png", IMG_BACKGROUND);
	dbLoadImage("Graphics\\Safehouse.fw.png", IMG_SAFEHOUSE);
	dbLoadImage("Graphics\\wall.bmp", IMG_WALL);	
	dbLoadImage("Graphics\\PauseScreen.fw.png", IMG_PAUSE_SCREEN);
	dbLoadImage("Graphics\\GameOver.fw.png", IMG_GAME_OVER_SCREEN);

	dbLoadImage("Graphics\\Sprites\\Player\\standing position.fw.png", IMG_PLAYER_STAND);
	dbLoadImage("Graphics\\Sprites\\Player\\updown1.fw.png", IMG_PLAYER_UP);
	dbLoadImage("Graphics\\Sprites\\Player\\updown2.fw.png", IMG_PLAYER_DOWN);
	dbLoadImage("Graphics\\Sprites\\Player\\right1.fw.png", IMG_PLAYER_LEFT1);
	dbLoadImage("Graphics\\Sprites\\Player\\right2.fw.png", IMG_PLAYER_LEFT2);	
	dbLoadImage("Graphics\\Sprites\\Player\\left1.fw.png", IMG_PLAYER_RIGHT1);
	dbLoadImage("Graphics\\Sprites\\Player\\left2.fw.png", IMG_PLAYER_RIGHT2);	
	dbLoadImage("Graphics\\Sprites\\Player\\dead1.fw.png", IMG_PLAYER_DEAD1);
	dbLoadImage("Graphics\\Sprites\\Player\\dead2.fw.png", IMG_PLAYER_DEAD2);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\1.fw.png", IMG_PLAYER_STUN1);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\2.fw.png", IMG_PLAYER_STUN2);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\3.fw.png", IMG_PLAYER_STUN3);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\4.fw.png", IMG_PLAYER_STUN4);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\5.fw.png", IMG_PLAYER_STUN5);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\6.fw.png", IMG_PLAYER_STUN6);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\7.fw.png", IMG_PLAYER_STUN7);
	dbLoadImage("Graphics\\Sprites\\Player\\StunAnimation\\7.fw.png", IMG_PLAYER_STUN8);

	dbLoadImage("Graphics\\Sprites\\Bat\\wingsUp.fw.png", IMG_BAT_UP);
	dbLoadImage("Graphics\\Sprites\\Bat\\wingsDown.fw.png", IMG_BAT_DOWN);

	dbLoadImage("Graphics\\Sprites\\Spider\\default.fw.png", IMG_SPIDER_DEFAULT);
	dbLoadImage("Graphics\\Sprites\\Spider\\up.fw.png", IMG_SPIDER_UP);
	dbLoadImage("Graphics\\Sprites\\Spider\\down.fw.png", IMG_SPIDER_DOWN);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\1.fw.png", IMG_SPIDER_DEATH_1);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\2.fw.png", IMG_SPIDER_DEATH_2);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\3.fw.png", IMG_SPIDER_DEATH_3);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\4.fw.png", IMG_SPIDER_DEATH_4);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\5.fw.png", IMG_SPIDER_DEATH_5);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\6.fw.png", IMG_SPIDER_DEATH_6);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\7.fw.png", IMG_SPIDER_DEATH_7);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\8.fw.png", IMG_SPIDER_DEATH_8);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\9.fw.png", IMG_SPIDER_DEATH_9);
	dbLoadImage("Graphics\\Sprites\\Spider\\DeathAnimation\\10.fw.png", IMG_SPIDER_DEATH_10);


	dbLoadImage("Graphics\\Sprites\\Robot1\\default.fw.png", IMG_ROBOT1);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\1.fw.png", IMG_ROBOT1_DEATH1);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\2.fw.png", IMG_ROBOT1_DEATH2);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\3.fw.png", IMG_ROBOT1_DEATH3);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\4.fw.png", IMG_ROBOT1_DEATH4);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\5.fw.png", IMG_ROBOT1_DEATH5);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\6.fw.png", IMG_ROBOT1_DEATH6);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\7.fw.png", IMG_ROBOT1_DEATH7);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\8.fw.png", IMG_ROBOT1_DEATH8);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\9.fw.png", IMG_ROBOT1_DEATH9);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\10.fw.png", IMG_ROBOT1_DEATH10);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\11.fw.png", IMG_ROBOT1_DEATH11);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\12.fw.png", IMG_ROBOT1_DEATH12);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\13.fw.png", IMG_ROBOT1_DEATH13);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\14.fw.png", IMG_ROBOT1_DEATH14);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\15.fw.png", IMG_ROBOT1_DEATH15);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\16.fw.png", IMG_ROBOT1_DEATH16);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\17.fw.png", IMG_ROBOT1_DEATH17);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\18.fw.png", IMG_ROBOT1_DEATH18);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\19.fw.png", IMG_ROBOT1_DEATH19);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\20.fw.png", IMG_ROBOT1_DEATH20);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\21.fw.png", IMG_ROBOT1_DEATH21);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\22.fw.png", IMG_ROBOT1_DEATH22);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\23.fw.png", IMG_ROBOT1_DEATH23);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\24.fw.png", IMG_ROBOT1_DEATH24);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\25.fw.png", IMG_ROBOT1_DEATH25);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\26.fw.png", IMG_ROBOT1_DEATH26);
	dbLoadImage("Graphics\\Sprites\\Robot1\\DeathAnimation\\27.fw.png", IMG_ROBOT1_DEATH27);

	dbLoadImage("Graphics\\Sprites\\Bullets\\standard.fw.png", IMG_BULLET1);

	dbLoadImage("Graphics\\Sprites\\Gun\\1.fw.png", IMG_GUN_1);
	dbLoadImage("Graphics\\Sprites\\Gun\\2.fw.png", IMG_GUN_2);
	dbLoadImage("Graphics\\Sprites\\Gun\\3.fw.png", IMG_GUN_3);



	//PreLoad Sounds
	dbLoadSound("Sounds\\BackgroundLoop.wav", SOUND_BACKGROUND_LOOP);
	dbLoadSound("Sounds\\PlayerDeath.wav", SOUND_PLAYER_DEATH);
	dbLoadSound("Sounds\\EnemyDeath.wav", SOUND_ENEMY_DEATH);
	dbLoadSound("Sounds\\Fire.wav", SOUND_FIRE);
}

void Game::WindowSet()
{
	//Set up the window itself
	dbSetDisplayMode(SCREEN_WIDTH, SCREEN_HEIGHT, BIT_DEPTH);
	dbSetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	dbSetWindowPosition(1,1);

	//Set up the sync setting - manual sync control, frame rate
	dbSyncOn();
	dbSyncRate(FRAME_RATE);
}



//Graphical Prompt / Non-Game Display Methods
void Game::SplashScreenA()
{
	//Load only the images needed for the starting screens
	dbLoadImage("Graphics\\SplashScreenBack.fw.png", IMG_SPLASH_SCREEN_BACKGROUND);
	dbLoadImage("Graphics\\SplashScreen1.fw.png", IMG_SPLASH_SCREEN_1);
	dbLoadImage("Graphics\\SplashScreen2.fw.png",IMG_SPLASH_SCREEN_2);
	dbLoadImage("Graphics\\SplashScreen3.fw.png",IMG_SPLASH_SCREEN_3);

	//Draw the opening title screen, sync the screen
	dbSprite(SPRITE_SPLASH_SCREEN_BACKGROUND, 0, 0, IMG_SPLASH_SCREEN_BACKGROUND);
	dbSprite(SPRITE_SPLASH_SCREEN_1, 0, 0, IMG_SPLASH_SCREEN_1);
	dbSync();
}

void Game::SplashScreenB()
{
	dbWait(200); //Avoid skipping the control splash screen
	//Blink "Press any key" until the user does so
	unsigned int blink = 0;
	while(dbScanCode() == 0)
	{
		if(blink > FRAME_RATE && blink < 2*FRAME_RATE) //on
		{
			dbSprite(SPRITE_SPLASH_SCREEN_2, 0, 0, IMG_SPLASH_SCREEN_2);
		}
		else if (blink >= 2*FRAME_RATE) //off
		{
			dbDeleteSprite(SPRITE_SPLASH_SCREEN_2);
			blink = 0;
		}
		blink++;
		dbSync();
	}
	dbDeleteSprite(SPRITE_SPLASH_SCREEN_2); //insure the message is removed from the screen
}

void Game::SplashScreenC()
{
	dbWait(200); //Avoid skipping the control splash screen
	//Remove the previous title screen
	dbDeleteSprite(SPRITE_SPLASH_SCREEN_1);
	//draw the controls dialouge
	dbSprite(SPRITE_SPLASH_SCREEN_3, 0, 0, IMG_SPLASH_SCREEN_3);
	//Again, flash "press any key" until the user does
	unsigned int blink = 0;
	while(dbScanCode() == 0)
	{
		if(blink > FRAME_RATE && blink < 2*FRAME_RATE)
		{
			dbSprite(SPRITE_SPLASH_SCREEN_2, 0, 0, IMG_SPLASH_SCREEN_2); //on
		}
		else if (blink >= 2*FRAME_RATE)
		{
			dbDeleteSprite(SPRITE_SPLASH_SCREEN_2); //off
			blink = 0;
		}
		blink++;
		//sync the screen
		dbSync();
	}
	//Remove any remaining title screen elements
	dbDeleteSprite(SPRITE_SPLASH_SCREEN_BACKGROUND);
	dbDeleteSprite(SPRITE_SPLASH_SCREEN_2);
	dbDeleteSprite(SPRITE_SPLASH_SCREEN_3);
	//Start the background music
	dbLoopSound(SOUND_BACKGROUND_LOOP);
	dbShowSprite(SPRITE_SAFEHOUSE);
}

void Game::PauseScreen()
{
	dbWait(300); //Avoid skipping the pause splash screen
	//Draw the pause screen, forcing it to the top
	dbSprite(SPRITE_PAUSE_SCREEN, 0, 0, IMG_PAUSE_SCREEN);
	dbSetSpritePriority (SPRITE_PAUSE_SCREEN, HIGHER_PRIORITY);
	dbSync();
	//Wait for the user to press the escape key or the space bar
	while(dbScanCode() != 1 && dbSpaceKey() != 1)
	{
	}
	if(dbScanCode() == 1) //if the escape key is pressed
	{
		//Remove the pause dialouge
		dbDeleteSprite(SPRITE_PAUSE_SCREEN);
		dbWait(300); //avoid re-entering the pause screen immeadiatley
		return;
	}
	else
	{
		//Set the token to break out of the main sync loop
		ExitGame = true;
		dbWait(300);
	}
}

void Game::GameOver()
{
	dbWait(300); //Avoid skipping the pause splash screen
	//Draw the pause screen, forcing it to the top
	dbSprite(SPRITE_GAME_OVER_SCREEN, 0, 0, IMG_GAME_OVER_SCREEN);
	dbSetSpritePriority (SPRITE_GAME_OVER_SCREEN, HIGHER_PRIORITY);
	dbSync();
	//Wait for the user to press the escape key or the space bar
	while(dbScanCode() == 0)
	{
	}
	ExitGame = true;
}




//Core Game State Update Method
void Game::Update()
{
	//Check for a pause
	if(dbScanCode() == ESCAPE_KEYCODE)
		PauseScreen();

	//Check for respawns
	CheckRespawns();

	//Check for random robot spawns
	RandomSpawn();

	//Update the Player, then the Robots, then the other enemies
	UpdatePlayer();
	UpdateRobots();
	UpdateSpiderAndBats();	

	//Update Existing Bullets
	BulletManagement(PlayerBullets);
	BulletManagement(RobotBullets);

	//Update the death and stunned state tokens for the player and the AIs
	CheckPlayerLife();
	CheckRobotLife();
	CheckSpiderLife();
	CheckBatsLife();

	//Update Gun (spawn if needed)
	GunManagement();

	//Update the info bar
	ClearTitleBar();
	SendRaw(Score, "Score: ");
	SendRaw(Lives, "  --  Lives Remaining: ");
	SyncTitleBar();
}



//Object Creation / Initialization Methods
void Game::CheckRespawns()
{
	if(ActivePlayer.GetRespawnRequest())
	{
		//if the player still has lives, respawn and decrement the count of lives available
		if(Lives > 0) 
		{
			SpawnNewPlayer();
			Lives--;
		}
		else //otherwise, it's game over, pal
			GameOver();
	}
	for(unsigned int i = 0; i < Robots.size(); i++)
	{
		//iterate through the vector of robots, checking for a need to be respawned
		if(Robots[i].GetRespawnRequest())
		{
			//Find the iterator of the robot to be respawned
			std::vector<FirstRobot>::iterator eraseTarget = Robots.begin() + i;
			//erase the current intance that needs respawned
			Robots.erase(eraseTarget);
			//Spawn a new robot to replace the previous one
			SpawnNewRobot();
			//Award the player 1000 points
			Score += 1000;
		}
	}
	if(ActiveSpider.GetRespawnRequest())
	{
		SpawnNewSpider();
		Score += 250;
	}
	if(ActiveBat1.GetRespawnRequest())
	{
		SpawnNewBat(1);
		Score += 250;
	}
	if(ActiveBat2.GetRespawnRequest())
	{
		SpawnNewBat(2);
		Score += 250;
	}
}

void Game::SpawnNewPlayer()
{
	//Reset the robots' collision tokens
	for(unsigned int i = 0; i < Robots.size(); i++)
		Robots[i].SetCollisionStateWithPlayerFalse();

	//Re-initialize the player
	ActivePlayer = Player(SPRITE_PLAYER, PLAYER_INITIAL_POSITION, IMG_PLAYER_STAND, PLAYER_VELOCITY);
}

void Game::SpawnNewRobot()
{
	//Add a new robot to the fray
	Robots.push_back(FirstRobot(SPRITE_ROBOT1 + RobotOffset, ROBOT_INITIAL_POSITION, IMG_ROBOT1, right, ROBOT_VELOCITY));
	RobotOffset++;
}

void Game::SpawnNewGun()
{
	switch(dbRND(5))
		{
		case 0:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(9,6)));
			break;
		case 1:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(15,3)));
			break;
		case 2:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(4,5)));
			break;
		case 3:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(2,8)));
			break;
		case 4:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(10,8)));
			break;
		case 5:
			ActiveGun = Gun(SPRITE_GUN, Coordinate(Tile(14,8)));
			break;
		}
}

void Game::SpawnNewSpider()
{
	ActiveSpider = Spider(SPRITE_SPIDER, SPIDER_INITIAL_POSITION, IMG_SPIDER_DEFAULT, right, SPIDER_VELOCITY);
}

void Game::SpawnNewBat(const unsigned int BatID)
{
	if(BatID == 1)
		ActiveBat1 = Bat(SPRITE_BAT1, BAT1_INITIAL_POSITION, IMG_BAT_UP, up, BAT_VELOCITY);
	else
		ActiveBat2 = Bat(SPRITE_BAT2, BAT2_INITIAL_POSITION, IMG_BAT_UP, left, BAT_VELOCITY);
}

void Game::RandomSpawn()
{
	if(dbRND(MEAN_RANDOM_SPAWN_PERIOD) == 0)
		SpawnNewRobot();
}


//Object Management Methods
void Game::UpdatePlayer()
{
	ActivePlayer.MovePlayer(Maps.WallsMap);
	if(!ActivePlayer.GetDeathState()) //if the player isn't dead, allow him to fire
		PlayerFire();
}

void Game::UpdateRobots()
{
	for(unsigned int i = 0; i < Robots.size(); i++)
	{
		//For each robot, move, and if it isn't dead, allow it to fire
		Robots[i].MoveAICharacter(Maps.WallsMap, Maps.RobotTurnSpots);
		if(!Robots[i].GetDeathState())
		{
			RobotFire(Robots[i]);
			Robots[i].CheckCollisionStateWithPlayer(ActivePlayer.GetLocale());
		}
	}
}

void Game::UpdateSpiderAndBats()
{
	//Update the Spider
	ActiveSpider.MoveAICharacter(Maps.WallsMap, Maps.RobotTurnSpots);
	ActiveSpider.CheckCollisionStateWithPlayer(ActivePlayer.GetLocale());

	//Update Bats
	ActiveBat1.MoveAICharacter(Maps.WallsMap, Maps.RobotTurnSpots);
	ActiveBat1.CheckCollisionStateWithPlayer(ActivePlayer.GetLocale());
	ActiveBat2.MoveAICharacter(Maps.WallsMap, Maps.RobotTurnSpots);
	ActiveBat2.CheckCollisionStateWithPlayer(ActivePlayer.GetLocale());
}

void Game::PlayerFire()
{
	//Update the current direction the player wants to fire, and whether or not he can
	ActivePlayer.FireDriection();
	//If allowed, add a new bullet to the PlayerBullets map
	if(ActivePlayer.GetFiredState())
	{
		PlayerBullets.insert(ActiveBullet(SPRITE_BULLET1+BulletOffset, std::unique_ptr<Bullet>(new Bullet(SPRITE_BULLET1+BulletOffset, ActivePlayer.GetPosition().X,  ActivePlayer.GetPosition().Y,  ActivePlayer.GetLatestBulletDirection()))));
		BulletOffset++;
		dbPlaySound(SOUND_FIRE);
	}
}

void Game::RobotFire(FirstRobot& Bot)
{
	//Figure out whether the robot should shoot, and in which direction
	Bot.Aim(ActivePlayer.GetLocale());
	//If the robot should fire, add a new bullet to the robotbullets map
	if(Bot.GetFireDirection() != none)
	{
		RobotBullets.insert(ActiveBullet(SPRITE_BULLET1+BulletOffset, std::unique_ptr<Bullet> (new Bullet(SPRITE_BULLET1+BulletOffset, Bot.GetPosition().X,  Bot.GetPosition().Y,  Bot.GetFireDirection(), IMG_BULLET1, ROBOT_HORIZONTAL_BULLET_OFFSET, ROBOT_VERTICAL_BULLET_OFFSET))));
		BulletOffset++;
		dbPlaySound(SOUND_FIRE);
	}
}

void Game::BulletManagement(std::map <unsigned int, std::unique_ptr<Bullet>>& BulletMap)
{
	//Get the first and last iterators for the bullet map to be iterated through
	std::map <unsigned int, std::unique_ptr<Bullet>>::iterator currentIterator = BulletMap.begin();
	std::map <unsigned int, std::unique_ptr<Bullet>>::iterator endIterator = BulletMap.end();
	//iterate through the map
	while(currentIterator != endIterator)
	{
		//Check if the bullet hit a wall, erase it and restart the iteration if it has
		if(currentIterator->second->GetCollisionState())
		{
			dbDeleteSprite(currentIterator->first);
			BulletMap.erase(currentIterator);
			currentIterator = BulletMap.begin();
		}
		else
		{
			//Move each valid bullet
			currentIterator->second->MoveBullet(Maps.WallsMap);
			currentIterator++;
		}
	}

}

bool Game::CheckForBulletCollisions(std::map <unsigned int, std::unique_ptr<Bullet>>& BulletMap, const int targetSpriteID)
{
	//This method checks for specific collisions between bullets and other non-wall sprites (used for checking collisions with an AI or the player)

	//Get the first and last iterators for the bullet map to be iterated through
	std::map <unsigned int, std::unique_ptr<Bullet>>::iterator currentIterator = BulletMap.begin();
	std::map <unsigned int, std::unique_ptr<Bullet>>::iterator endIterator = BulletMap.end();
	//iterate through the bullets map
	while(currentIterator != endIterator)
	{
		//if a collision is detected between a bullet and the target sprite
		if(dbSpriteCollision(currentIterator->first, targetSpriteID))
		{
			//Erase the bullet and return true
			dbDeleteSprite(currentIterator->first);
			BulletMap.erase(currentIterator);
			return true;
		}
		else
			currentIterator++;
	}
	//If no collisions have occured, return false
	return false;
}

void Game::CheckPlayerLife()
{
	for(unsigned int i = 0; i < Robots.size() && !ActivePlayer.GetDeathState(); i++)
	{
		//First, check if any robots has physically collided with the player
		if(Robots[i].GetCollisionStateWithPlayer())
		{
			ActivePlayer.SetDeathStateTrue();
			dbPlaySound(SOUND_PLAYER_DEATH);
			return; //no point in continuing to look if the player is dead
		}
	}
	//Next, check if any of the bullets fired by robots have collided with the player
	if(CheckForBulletCollisions(RobotBullets, ActivePlayer.GetSpriteID()))
	{
		ActivePlayer.SetDeathStateTrue();
		dbPlaySound(SOUND_PLAYER_DEATH);
		return; //death also trumps stunning
	}

	//Then, check for collisions between the player and the Spider, and then the bats
	else if(ActiveSpider.GetCollisionStateWithPlayer() && !ActiveSpider.GetDeathState())
	{
		ActivePlayer.SetStunnedStateTrue();
		return;
	}

	else if(ActiveBat1.GetCollisionStateWithPlayer() && !ActiveBat1.GetDeathState())
	{
		ActivePlayer.SetStunnedStateTrue();
		return;
	}
	else if(ActiveBat2.GetCollisionStateWithPlayer() && !ActiveBat2.GetDeathState())
	{
		ActivePlayer.SetStunnedStateTrue();
		return;
	}

}

void Game::CheckRobotLife()
{
	//For each active robot, check if any of the bullets fired by player have collided
	for(unsigned int i = 0; i < Robots.size(); i++)
	{
		if(!Robots[i].GetDeathState())
		{
			if(CheckForBulletCollisions(PlayerBullets, Robots[i].GetSpriteID()))
			{
				Robots[i].SetDeathStateTrue();
				dbPlaySound(SOUND_ENEMY_DEATH);
			}
		}
	}
}

void Game::CheckSpiderLife()
{
	if(!ActiveSpider.GetDeathState())
	{
		if(CheckForBulletCollisions(PlayerBullets, ActiveSpider.GetSpriteID()))
		{
			ActiveSpider.SetDeathStateTrue();
			dbPlaySound(SOUND_ENEMY_DEATH);
		}
	}
}

void Game::CheckBatsLife()
{
	if(!ActiveBat1.GetDeathState())
	{
		if(CheckForBulletCollisions(PlayerBullets, ActiveBat1.GetSpriteID()))
		{
			ActiveBat1.SetDeathStateTrue();
			dbPlaySound(SOUND_ENEMY_DEATH);
		}
	}
	if(!ActiveBat2.GetDeathState())
	{
		if(CheckForBulletCollisions(PlayerBullets, ActiveBat2.GetSpriteID()))
		{
			ActiveBat2.SetDeathStateTrue();
			dbPlaySound(SOUND_ENEMY_DEATH);
		}
	}
}


void Game::GunManagement()
{
	//First, we update the active gun
	ActiveGun.Update(ActivePlayer.GetSpriteID());

	//If a collision occured between an available gun, we give the player six shots, hide the gun (delete its sprite), and reset the collision, as to not repeat this step
	if(ActiveGun.GetCollisionState())
	{
		ActivePlayer.SetShotsRemaining(GUN_CAPACITY);
		ActiveGun.Hide();
		ActiveGun.SetCollisionStateFalse();
		Score += 100;
	}	

	//Last, we check if a new gun needs to be spawned
	if(ActivePlayer.GetShotsRemaining() == 0 && ActiveGun.GetHiddenState())
		SpawnNewGun();
}



//Title Bar Management Methods
void Game::ClearTitleBar()
{
	TitleText[0] = '\0';
}

void Game::SyncTitleBar()
{
	dbSetWindowTitle(TitleText);
}

void Game::SendRaw(int Input, const char* precedingLabel)
{
	char Temp1[20] = " \0";

	strcat(TitleText, precedingLabel);
	std::sprintf(Temp1, "%d", Input);
	strcat(TitleText, Temp1);
}



//Access Members
bool Game::GetExitRequest()
{
	return ExitGame;
}
	
unsigned int Game::GetScore()
{
	return Score;
}

unsigned int Game::GetRemainingLives()
{
	return Lives;
}