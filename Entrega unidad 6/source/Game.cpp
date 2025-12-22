#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}


void Game::DrawGame()
{
	player.DrawPlayer();
	
	for (Projectile& projectile: player.projectiles){
		projectile.DrawProjectile();
	}
}

void Game::Events()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		player.FireProjectile();
	}
}

void Game::UpdateGame()
{
	for (auto& projectile: player.projectiles){
		projectile.UpdateProjectile();
	}

}
