#pragma once
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"


class Game
{

public:

	void DeleteInactiveProjectiles();
	
	Player player;
	std::vector<Enemy*> enemies;
	
	
	
	Texture2D backgraund = LoadTexture("Assets/fondo.png");
	Rectangle screen = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
	float spawnTimer = 0.0f;
	float spawnInterval = 3.5f;

	Rectangle game_over_rect = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2, 200,200 };
	bool game_over = false;

	Game();
	~Game();


	void DrawGame();
	void DrawGameOver();
	


	void Events();

	void UpdateGame();

	void CheckForCollisions();
	
	void DrawHUD();


};

