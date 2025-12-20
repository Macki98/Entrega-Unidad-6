#pragma once
#include "raylib.h"

class Projectile
{
private:
	Vector2 projectile_position;
	Vector2 projectile_velocity;
	float acceleration;
	const float projectile_gravity;

	Texture2D projectile_texture;

public:
	Projectile();
	~Projectile();

	void Displace();

	bool ItsInMotion();

};

