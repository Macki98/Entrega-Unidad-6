#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(int type, float scree_width, float screen_height)
{
	this->type = type;
	enemy_scale = 0.3f;

	//Construimos el enemigo segun la textura deseada
	switch (type) {
	case 1:
		enemy_texture = LoadTexture("Assets/Alien.png");
		
		break;
	case 2:
		enemy_texture = LoadTexture("Assets/Meteorito.png");
		break;
	default:
		enemy_texture = LoadTexture("Assets/Alien.png");
		break;
	}
	
	

	if (type == 1)
	{
		enemy_position.x = (float)scree_width + ((float)enemy_texture.width * enemy_scale);
		enemy_position.y = (float)GetRandomValue(0, (float)screen_height / 2);
		enemy_velocity.x = (float)GetRandomValue(50, 100);
		enemy_velocity.y = 0;
	}
	
	if (type == 2)
	{
		enemy_position.x = (float)GetRandomValue(scree_width / 2, scree_width);
		enemy_position.y = 0 - ((float)enemy_texture.height * enemy_scale);
		enemy_velocity.x = (float)GetRandomValue(50, 100);
		enemy_velocity.y = 150.0f;
	}

}

Enemy::~Enemy()
{
	UnloadTexture(enemy_texture);
	
}

void Enemy::EnemyUpdate(float deltaTime)
{
	switch (type)
	{
	case 1:

		enemy_position.x -= enemy_velocity.x * deltaTime;
		enemy_position.y += enemy_velocity.y * deltaTime;
		break;

	case 2:

		enemy_velocity.y += enemy_gravity * deltaTime;
		enemy_position.x -= enemy_velocity.x * deltaTime;
		enemy_position.y += enemy_velocity.y * deltaTime;

		if (enemy_position.y >= GetScreenHeight() - (float)(enemy_texture.height * enemy_scale)) {

			enemy_position.y = GetScreenHeight() - ((float)enemy_texture.height * enemy_scale);
			enemy_velocity.y *= -1;
			enemy_velocity.y *= 0.90f;
			

		}
		break;
	}
	
}

void Enemy::DrawEnemy() 
{
	DrawTextureEx(enemy_texture, enemy_position,0, enemy_scale,WHITE);
	SetTextureFilter(enemy_texture, TEXTURE_FILTER_BILINEAR);
}



int Enemy::GetType() {
	return type;
}



bool Enemy::IsOffScreenX()
{
	if (enemy_position.x <= 0) {
		return true;
	}
	else
	{
		return false;
	}
}



Rectangle Enemy::GetEnemyRect()
{
	return { enemy_position.x, enemy_position.y,
	((float)enemy_texture.width * enemy_scale),
	((float)enemy_texture.height * enemy_scale),
	};
}
