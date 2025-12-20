#pragma once
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

#define WINDOW_WIDTH 1080;
#define WINDOW_HEIGTH 720;

class Game
{
public:

	int width = WINDOW_WIDTH;
	int heigth = WINDOW_HEIGTH;

	const char* title = "Operacion: furia cinetica. Leonel Mc Cormack";

	Game();
	~Game();

	void init_game();
};

