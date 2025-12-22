#include "Projectile.h"

Projectile::Projectile()
{
	projectile_position = { 0.0f,0.0f };
	projectile_velocity = { 0.0f, 0.0f };
	projectile_acceleration = 0.0f;
	projectile_texture = LoadTexture("Assets/Proyectil.png");

}

Projectile::~Projectile()
{
	UnloadTexture(projectile_texture);
}

void Projectile::Displace()
{
}

bool Projectile::ItsInMotion()
{
	return false;
}
