#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Vector2 projectile_position, Vector2 projectile_velocity)
{
	projectile_acceleration = 0.0f;
	projectile_texture = LoadTexture("Assets/Proyectil.png");
	projectile_scale = 0.2f;

	
	this -> projectile_position = projectile_position;
	this -> projectile_velocity = projectile_velocity;


	active = true;
}

Projectile::~Projectile()
{
	UnloadTexture(projectile_texture);
}

void Projectile::DrawProjectile()
{
	if (active)
		DrawTextureEx(projectile_texture, projectile_position, 0, projectile_scale, WHITE);

}

void Projectile::UpdateProjectile()
{
	float deltaTime = GetFrameTime();

	projectile_velocity.y += projectile_gravity * deltaTime;
	projectile_position.x += projectile_velocity.x * deltaTime;
	projectile_position.y += projectile_velocity.y * deltaTime;

	if (active){
		if (projectile_position.y > GetScreenHeight() || projectile_position.y < 0) {
			active = false;

			std::cout << "projectile inactive" << std::endl;
		}
	}
}




