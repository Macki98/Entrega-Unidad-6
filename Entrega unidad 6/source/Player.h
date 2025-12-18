#pragma once
#include "raylib.h"

class Player
{
private:
	int vidas;
	Vector2 player_position;
	Texture2D player_texture;

public:

	Player();
	~Player();

	void Aim();
	void Shot();
};

