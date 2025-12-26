#include "Game.h"
#include <iostream>


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

	for (auto enemy : enemies)
	{
		enemy->DrawEnemy();
	}

	DrawHUD();
}

void Game::Events()
{
	player.Aim();
	player.FireProjectile();

}

void Game::UpdateGame()
{

	//Actualizamos y borramos proyectiles
	for (auto& projectile: player.projectiles){
		projectile->UpdateProjectile();
	}
	DeleteInactiveProjectiles();
	

	//Actualizamos, generamos y borramos enemigos
	float dt = GetFrameTime();
	spawnTimer += dt;

	if (spawnTimer >= spawnInterval)
	{
		enemies.push_back(new Enemy(GetRandomValue(1,2), (float)GetScreenWidth(), (float)GetScreenHeight()));
		spawnTimer = 0.0f;
	}
	
	for (auto it = enemies.begin(); it != enemies.end();)
	{
		(*it)->EnemyUpdate(dt);

		if ((*it)->IsOffScreenX())
		{
			delete* it;
			it = enemies.erase(it);
		}
		else
		{
			it++;
		}
	}

	//Chequear colisiones
	CheckForCollisions();

}

void Game::CheckForCollisions()
{

	//projectiles -> enemigos

	for (auto& projectile : player.projectiles) {
		auto it = enemies.begin();
		while(it != enemies.end()){
			if (CheckCollisionRecs((*it)->GetEnemyRect(), projectile->GetProjectileRect())) 
			{
				it = enemies.erase(it);
				projectile->active = false;
				player.Score();
			}
			else
			{
				++it;
			}
		}

	}

	//enemigos -> jugador
	
	for (auto it = enemies.begin(); it != enemies.end();) {
		if (CheckCollisionRecs((*it)->GetEnemyRect(), player.GetPlayerRect())) {
			it = enemies.erase(it);
			player.Damage();
			
		}
		else
		{
			it++;
		}
	}

}

void Game::DrawHUD()
{
	DrawRectangle(0, 0, 500, 100, Fade(BLACK, 0.5f));
	DrawText(TextFormat("Vidas: %.1d", player.GetLifes()), 0, 0, 20, BLACK);
	DrawText(TextFormat("Potencia Y: %.1f Potencia X: %.1f", player.GetAngleY(), player.GetAngleX()), 0, 23, 20, BLACK);
	DrawText(TextFormat("Puntos:  %.1f", player.GetScore()), 0, 46, 20, BLACK);
}

//Eliminamos los proyectiles inactivos para liberar memoria
void Game::DeleteInactiveProjectiles()
{
	for (auto it = player.projectiles.begin(); it != player.projectiles.end();)
	{

		if (!(*it)->active)
		{
			delete* it;
			it = player.projectiles.erase(it);
		}
		else
		{
			it++;
		}
	}
}

