#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

#include "Game.h"


int main(void)
{
    int window_width = 1080;
    int window_heigth = 720;

    const char* title = "Operacion: furia cinetica. Leonel Mc Cormack";

    InitWindow(window_width,window_heigth,title);
    SetTargetFPS(60);


    Game* game = new Game();


    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        game->DrawGame();

        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

