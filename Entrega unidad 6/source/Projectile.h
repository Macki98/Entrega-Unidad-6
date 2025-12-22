#pragma once
#include "raylib.h"


class Projectile
{
private:

	Vector2 projectile_position;
	Vector2 projectile_velocity;
	float projectile_acceleration;
	//const float projectile_gravity = 500.0f;

	Texture2D projectile_texture;
	float projectile_scale;

	
	

public:
	Projectile(Vector2 projetcile_position);
	~Projectile();


	void DrawProjectile();

	void UpdateProjectile();

	bool active;

	
};

