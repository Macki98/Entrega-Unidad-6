#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

#include "Game.h"

int main(void)
{
    Game* partida = new Game();

    partida->init_game();

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        
        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

