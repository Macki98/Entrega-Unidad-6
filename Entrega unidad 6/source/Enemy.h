#pragma once

#include <vector>
#include <iostream>

#include "raylib.h"

class Enemy
{
private:

	Vector2 enemy_position;
	Vector2 enemy_velocity;
	
	Texture2D enemy_texture;
	const float enemy_gravity;

public:
	Enemy();
	~Enemy();

	void Move();
	bool ItsEnemyAlive();


};

