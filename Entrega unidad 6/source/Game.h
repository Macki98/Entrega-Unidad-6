#pragma once
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

class Game
{
public:

	int width;
	int heigth;
	const char* title;

	Game();
	~Game();

	void init_game();
};

