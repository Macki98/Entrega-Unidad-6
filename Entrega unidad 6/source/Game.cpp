#include "Game.h"

Game::Game()
{
	width = 1080;
	heigth = 720;
	title = "Operacion: furia cinetica. Leonel Mc Cormack";

}

Game::~Game()
{
}

void Game::init_game()
{
	InitWindow(width, heigth, title);
	SetTargetFPS(60);
}
