#pragma once
#include "raylib.h"


class Player
{
private:

	int lifes;

	Vector2 player_position;
	
	Vector2 player_angle;

	Texture2D player_texture;

public:

	Player();
	~Player();

	bool ItsPlayerAlive();

	void Aim();
	void Shot();
};

