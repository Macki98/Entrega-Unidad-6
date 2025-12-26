#pragma once
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"


class Game
{

private:

	void DeleteInactiveProjectiles();
	
	Player player;
	std::vector<Enemy*> enemies;
	

	float spawnTimer = 0.0f;
	float spawnInterval = 3.5f;

	bool in_game = true;


public:

	Game();
	~Game();


	void DrawGame();
	void DrawGameOver();
	void DrawWin();

	void Events();

	void UpdateGame();

	void CheckForCollisions();
	
	void DrawHUD();
};

