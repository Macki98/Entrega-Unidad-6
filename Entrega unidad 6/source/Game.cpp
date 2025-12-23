#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}


void Game::DrawGame(){

	player.DrawPlayer();
	
	for (auto& projectile : player.projectiles) {
		projectile->DrawProjectile();
	}

}

void Game::Events()
{
	player.Aim();
	player.FireProjectile();

}

void Game::UpdateGame()
{
	for (auto& projectile: player.projectiles){
		projectile->UpdateProjectile();
	}

}
