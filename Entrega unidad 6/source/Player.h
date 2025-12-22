#pragma once
#include "raylib.h"


class Player
{
private:

	int lifes;

	Vector2 player_position;
	
	Vector2 player_angle;

	Texture2D player_texture;
	
	float player_scale;

public:

	Player();
	~Player();

	bool ItsPlayerAlive();

	void DrawPlayer();

	void Aim();
	void Shot();
};

