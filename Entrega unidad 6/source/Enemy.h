#pragma once

#include <vector>
#include <iostream>

#include "raylib.h"

class Enemy
{
private:

public:
	Enemy(int type, float screen_width, float screen_height);
	~Enemy();

	void EnemyUpdate(float deltaTime);
	void DrawEnemy();
	
	int GetType();

	bool IsOffScreenX();
	bool IsOffScreenY();

	Rectangle GetEnemyRect();

	Texture2D enemy_texture;

	Vector2 enemy_position;


	Vector2 enemy_velocity;

	float enemy_scale;

	const float enemy_gravity = 500.0f;

	int type;

};

