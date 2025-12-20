#include "Player.h"

#include "Game.h"

Player::Player()
{

	lifes = 5;

	player_position = { 0, 720 };

	player_angle = { 0,0 };

	player_texture = LoadTexture();

}

Player::~Player()
{
	UnloadTexture(player_texture);
}

bool Player::ItsPlayerAlive()
{
	return false;
}

void Player::Aim()
{
}

void Player::Shot()
{
}
