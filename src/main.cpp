#include "raylib.h"
#include "header/game.hpp"

int main() {
    const int WIDTH = 750;
    const int HEIGHT = 700;

    InitWindow(WIDTH, HEIGHT, "Space Invader (nah phogn'd win)");
    SetTargetFPS(60);

    Game game;

    while (WindowShouldClose() == false) {
        game.HandleInput();
        game.Update();

        BeginDrawing();

        ClearBackground(BLACK);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}