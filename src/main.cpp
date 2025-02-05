#include "raylib.h"
#include "header/game.hpp"
#include "header/bullet.hpp"

int main() {
    const int WIDTH = 750;
    const int HEIGHT = 700;

    InitWindow(WIDTH, HEIGHT, "Space Invader (nah phogn'd win)");
    SetTargetFPS(60);

    Game game;
    Bullet bullet = Bullet({100, 100}, 7);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        game.HandleInput();

        ClearBackground(BLACK);
        game.Draw();
        bullet.Draw(); //idk

        EndDrawing();
    }

    CloseWindow();
    return 0;
}