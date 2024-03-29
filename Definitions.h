//Definitions

	//Settings
	#define FRAME_RATE 30
	#define GRID_JUSTIFICATION_X 68
	#define GRID_JUSTIFICATION_Y 68

	#define ROBOT_VELOCITY 4
	#define PLAYER_VELOCITY 4
	#define BULLET_VELOCITY 6
	#define SPIDER_VELOCITY 2
	#define BAT_VELOCITY 2

	#define PLAYER_FIRE_PERIOD 10
	#define ROBOT_FIRE_PERIOD 12
	#define MEAN_RANDOM_SPAWN_PERIOD 6000

	#define GUN_CAPACITY 6

	#define SCREEN_WIDTH 1024
	#define SCREEN_HEIGHT 768 
	#define BIT_DEPTH 32
	#define RBG_TRANSPARENCY_KEY 255,77,255

	#define SAFEHOUSE_POSITION 454, 254
	#define PLAYER_INITIAL_POSITION 520, 264
	#define ROBOT_INITIAL_POSITION 72, 648
	#define SPIDER_INITIAL_POSITION 72, 72
	#define BAT1_INITIAL_POSITION 688, 200
	#define BAT2_INITIAL_POSITION 688, 648

	#define DEATH_ANIMATION_OFFSET 27
	#define STUN_ANIMATION_OFFSET 20
	#define VERTICAL_BULLET_OFFSET -20
	#define HORIZONAL_BULLET_OFFSET 12
	#define ROBOT_HORIZONTAL_BULLET_OFFSET 24
	#define ROBOT_VERTICAL_BULLET_OFFSET -20

	//Keypress scan codes
	#define W_KEYCODE 17
	#define A_KEYCODE 30
	#define S_KEYCODE 31
	#define D_KEYCODE 32
	#define ESCAPE_KEYCODE 1

	//Other Constants
	#define HIGH_PRIORITY 1
	#define HIGHER_PRIORITY 2
//ImageID's start at 1000, split by 100, Sprite IDs start at 10000, split by 1000

	//Image IDs
	//Image
	#define IMG_BACKGROUND 1001
	#define IMG_WALL 1002
	#define IMG_SPLASH_SCREEN_BACKGROUND 1003
	#define IMG_SPLASH_SCREEN_1 1004
	#define IMG_SPLASH_SCREEN_2 1005
	#define IMG_SPLASH_SCREEN_3 1006
	#define IMG_PAUSE_SCREEN 1007
	#define IMG_GAME_OVER_SCREEN 10008
	#define IMG_SAFEHOUSE 10009
	//Player
		#define IMG_PLAYER_STAND 1100
		#define IMG_PLAYER_UP 1101
		#define IMG_PLAYER_DOWN 1102
		#define IMG_PLAYER_LEFT1 1103
		#define IMG_PLAYER_LEFT2 1104
		#define IMG_PLAYER_RIGHT1 1105
		#define IMG_PLAYER_RIGHT2 1106
		#define IMG_PLAYER_DEAD1 1107
		#define IMG_PLAYER_DEAD2 1108
		#define IMG_PLAYER_STUN1 1109
		#define IMG_PLAYER_STUN2 1110
		#define IMG_PLAYER_STUN3 1111
		#define IMG_PLAYER_STUN4 1112
		#define IMG_PLAYER_STUN5 1113
		#define IMG_PLAYER_STUN6 1114
		#define IMG_PLAYER_STUN7 1115
		#define IMG_PLAYER_STUN8 1116

		//Bat
		#define IMG_BAT_UP 1200
		#define IMG_BAT_DOWN 1201
		//Robot1
		#define IMG_ROBOT1 1300
		#define IMG_ROBOT1_DEATH1 1301
		#define IMG_ROBOT1_DEATH2 1302
		#define IMG_ROBOT1_DEATH3 1303
		#define IMG_ROBOT1_DEATH4 1304
		#define IMG_ROBOT1_DEATH5 1305
		#define IMG_ROBOT1_DEATH6 1306
		#define IMG_ROBOT1_DEATH7 1307
		#define IMG_ROBOT1_DEATH8 1308
		#define IMG_ROBOT1_DEATH9 1309
		#define IMG_ROBOT1_DEATH10 1310
		#define IMG_ROBOT1_DEATH11 1311
		#define IMG_ROBOT1_DEATH12 1312
		#define IMG_ROBOT1_DEATH13 1313
		#define IMG_ROBOT1_DEATH14 1314
		#define IMG_ROBOT1_DEATH15 1315
		#define IMG_ROBOT1_DEATH16 1316
		#define IMG_ROBOT1_DEATH17 1317
		#define IMG_ROBOT1_DEATH18 1318
		#define IMG_ROBOT1_DEATH19 1319
		#define IMG_ROBOT1_DEATH20 1320
		#define IMG_ROBOT1_DEATH21 1321
		#define IMG_ROBOT1_DEATH22 1322
		#define IMG_ROBOT1_DEATH23 1323
		#define IMG_ROBOT1_DEATH24 1324
		#define IMG_ROBOT1_DEATH25 1325
		#define IMG_ROBOT1_DEATH26 1326
		#define IMG_ROBOT1_DEATH27 1327

		//Robot2
		#define IMG_ROBOT2_1 1400
		//Bullets
			//Standard Bullet
			#define IMG_BULLET1 1500

		//Gun
		#define IMG_GUN_1 1600
		#define IMG_GUN_2 1601
		#define IMG_GUN_3 1602

		//Spider
		#define IMG_SPIDER_DEFAULT 1700
		#define IMG_SPIDER_UP 1701
		#define IMG_SPIDER_DOWN 1702

		#define IMG_SPIDER_DEATH_1 1703
		#define IMG_SPIDER_DEATH_2 1704
		#define IMG_SPIDER_DEATH_3 1705
		#define IMG_SPIDER_DEATH_4 1706
		#define IMG_SPIDER_DEATH_5 1707
		#define IMG_SPIDER_DEATH_6 1708
		#define IMG_SPIDER_DEATH_7 1709
		#define IMG_SPIDER_DEATH_8 1710
		#define IMG_SPIDER_DEATH_9 1711
		#define IMG_SPIDER_DEATH_10 1712

	//Sprite IDs
	#define SPRITE_BACKGROUND 10000
	#define SPRITE_WALL_TOP 10001
	#define SPRITE_WALL_BOTTOM 10002
	#define SPRITE_WALL_LEFT 10003
	#define SPRITE_WALL_RIGHT 10004
	#define SPRITE_WALL_INNER_A 10005
	#define SPRITE_WALL_INNER_B 10006
	#define SPRITE_WALL_INNER_C 10007
	#define SPRITE_WALL_INNER_D 10008
	#define SPRITE_WALL_INNER_E 10009
	#define SPRITE_WALL_INNER_F 10010
	#define SPRITE_WALL_INNER_G 10011
	#define SPRITE_WALL_INNER_H 10012
	#define SPRITE_WALL_INNER_I 10013
	#define SPRITE_WALL_INNER_J 10014
	#define SPRITE_WALL_INNER_K 10015
	#define SPRITE_WALL_INNER_L 10016
	#define SPRITE_WALL_INNER_M 10017
	#define SPRITE_WALL_INNER_N 10018
	#define SPRITE_WALL_INNER_O 10019
	#define SPRITE_WALL_INNER_P 10020
	#define SPRITE_WALL_INNER_Q 10021
	#define SPRITE_WALL_INNER_R 10022
	#define SPRITE_SPLASH_SCREEN_BACKGROUND 10023
	#define SPRITE_SPLASH_SCREEN_1 10024
	#define SPRITE_SPLASH_SCREEN_2 10025
	#define SPRITE_SPLASH_SCREEN_3 10026
	#define SPRITE_PAUSE_SCREEN 10027
	#define SPRITE_SAFEHOUSE 10028
	#define SPRITE_WALL_SAFEHOUSE_BOTTOM 10029
	#define SPRITE_WALL_SAFEHOUSE_LEFT 10030
	#define SPRITE_WALL_SAFEHOUSE_RIGHT 10031
	#define SPRITE_WALL_SAFEHOUSE_TOPLEFT 10032
	#define SPRITE_WALL_SAFEHOUSE_TOPRIGHT 10033
	#define SPRITE_GAME_OVER_SCREEN 10034
	#define SPRITE_PLAYER 10100
	#define SPRITE_ROBOT1 10200
	#define SPRITE_SPIDER 10300
	#define SPRITE_BAT1 10400
	#define SPRITE_BAT2 10401
	#define SPRITE_GUN 10500
	#define SPRITE_BULLET1 10600


//Sound IDs
#define SOUND_BACKGROUND_LOOP 100000
#define SOUND_PLAYER_DEATH 100001
#define SOUND_ENEMY_DEATH 100002
#define SOUND_FIRE 100003