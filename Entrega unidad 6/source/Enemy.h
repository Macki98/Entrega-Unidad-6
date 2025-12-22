#pragma once

#include <vector>
#include <iostream>

#include "raylib.h"

class Enemy
{
private:

	Vector2 enemy_position;

	Vector2 enemy_velocity;
	
	Texture2D enemy_alien_texture;
	Texture2D enemy_asteroid_texture;

	const float enemy_gravity = 500.f;

public:
	Enemy();
	~Enemy();

	void Move();
	bool ItsEnemyAlive();


};

