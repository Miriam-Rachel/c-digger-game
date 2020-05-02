#pragma once
const int NUM_OF_TEXTURES = 22;
const int TEXTURES_FOR_MONSTER = 3;
const int TEXTURES_FOR_SMART = 5;
const int TEXTURES_FOR_PLAYER = 4;
const char MONSTER = '!';
const char PLAYER = '/';
const char DONT_WANT_TURN = ' ';
const char CLEAN = ' ';
const char STON = '@';
const char DIAMOND = 'D';
const char WALL = '#';
const char PRESENT = '+';
const int NUM_OF_LIVES = 3;
const int SCORS_FOR_LEVEL = 20;
const int SCORS_FOR_DIAMOND = 15;
const float WINDOW_HIGHT = 720;
const float WINDOW_WIDTH = 1280 ;
const float WIDTH_OF_WINDOW = 1280;
const float HEIGHT_OF_WINDOW = 720;
const float BOARD_WIDTH = 720;
const float BOARD_HEIGHT = 720;
const float HEIGHT_OF_BUTTON = 67;
const int TIME_PRESENT = 10;
const int SCORE_PRESENT = 2;
const int STONE_PRESENT = 2;
const int SMART_MONSTER = 0;
const int NUM_OF_DIRECTIONS = 4;
const int NUM_OF_BUTTONS = 2;
const int MAX_STEPS_FOR_DIRECTION = 200;
const float PIXELS_FOR_SEC = 120;
const int DIRECTIONS = 4;
const int  SUBPRACT =71;
const int NO_LIMIT = -1;
const int SCORE_OF_DIAMOND = 15;
const int SCORES_FOR_LEVEL = 20;
const int EPSILON = 1;
enum textures
{
	Background,
	BackgroundMenu,
	Diver1,
	Diver2,
	Diver3,
	Diver4,
	Exit1,
	NewGame1,
	Pearl,
	present,
	Shark1,
	Shark2,
	Shark3,
	Smart1,
	Smart2,
	Smart3,
	Smart4,
	Smart5,
	stone,
	wall,
	gameover,
	win,
};
enum Directions
{
	Left,
	Right,
	Up,
	Down,
	nothing,
};
enum Presents
{
	Time,
	Score,
	Stones,
};