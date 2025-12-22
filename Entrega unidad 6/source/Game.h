#pragma once
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "Player.h"


class Game
{

private:

	Player player;
	

public:

	Game();
	~Game();


	void DrawGame();

	void Events();

	void UpdateGame();

	

};

