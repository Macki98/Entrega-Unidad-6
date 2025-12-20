#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::init_game()
{
	InitWindow(width, heigth, title);
	SetTargetFPS(60);
}
