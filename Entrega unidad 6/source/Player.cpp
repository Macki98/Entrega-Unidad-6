#include "Player.h"


Player::Player()
{

	player_texture = LoadTexture("Assets/Player.png");
	player_turret = LoadTexture("Assets/Cañon.png");


	lifes = 5;
	player_scale = 0.3f;
	player_angle = { 0,0 };
	player_position.x = 0;
	player_position.y = GetScreenHeight() - (player_texture.height * player_scale);

	player_turret_source = { 0,0,(float)player_turret.width, (float)player_turret.height };
	player_turret_dest = { (player_position.x + ((float)player_texture.width * player_scale)) / 1.5f, player_position.y,((float)player_texture.width * player_scale),((float)player_texture.height * player_scale) };
	player_turret_origin = { 50, ((float)player_turret.height * player_scale) / 2 };
	player_turret_rotation = 0.0f;
	
	
}

Player::~Player()
{
	UnloadTexture(player_texture);
}

bool Player::ItsPlayerAlive()
{
	return false;
}

void Player::DrawPlayer()
{

	DrawTextureEx(player_texture,player_position,0,player_scale,WHITE);
	DrawTexturePro(player_turret,player_turret_source,player_turret_dest,player_turret_origin, player_turret_rotation, WHITE);
}

void Player::Aim()
{
}

void Player::FireProjectile()
{
	projectiles.push_back(new Projectile({ player_position.x,player_position.y }));
}
