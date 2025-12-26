#pragma once
#include "raylib.h"

#include "Projectile.h"

#include <vector>

class Player
{
private:

	int lifes;

	Vector2 player_position;
	
	Rectangle player_turret_source;
	Rectangle player_turret_dest;
	Vector2 player_turret_origin;
	float player_turret_rotation;
	Vector2 player_angle;

	Texture2D player_texture;
	Texture2D player_turret;
	
	float player_scale;

	float points;
public:

	Player();
	~Player();



	void DrawPlayer();

	void Aim();
	void FireProjectile();

	void Damage();
	void Score();
	float GetScore();
	int GetLifes();

	float GetAngleX();
	float GetAngleY();

	Rectangle GetPlayerRect();
	std::vector<Projectile*> projectiles;

};

