#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
	enemy_position = { 1080 / 2,720 / 2 };
	enemy_velocity = {-100.0f,0.0f};
	
	enemy_alien_texture = LoadTexture("Assets/Alien.png");
	enemy_asteroid_texture = LoadTexture("Assets/Meteorito.png");

}

Enemy::~Enemy()
{
	UnloadTexture(enemy_alien_texture);
	UnloadTexture(enemy_asteroid_texture);
}

void Enemy::Move()
{
}

bool Enemy::ItsEnemyAlive()
{
	return false;
}
