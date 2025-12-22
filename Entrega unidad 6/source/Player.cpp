#include "Player.h"



Player::Player()
{
	player_texture = LoadTexture("Assets/Player.png");

	lifes = 5;

	player_angle = { 0,0 };

	player_scale = 0.3f;

	player_position.x = 0;
	player_position.y = GetScreenHeight() - (player_texture.height * player_scale);
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
}

void Player::Aim()
{
}

void Player::Shot()
{
}
