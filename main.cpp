#include "raylib.h"

class Player {
public:
    Vector2 position = {400, 760};
    Texture2D texture;

    Player() {
        Image image = LoadImage("assets/player.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Player() {
        UnloadTexture(texture);
    }

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }
};

Player player = Player();

class Bullet {
public:
    Vector2 position = player.position;
    
    void Draw() {
        
    }
};

int main() {
    InitWindow(800, 800, "Space Invader (nah phogn'd win)");
    SetTargetFPS(60);Image image = LoadImage("assets/player.png");

    while (WindowShouldClose() == false) {
        BeginDrawing();

        if (IsKeyDown(KEY_LEFT)) {
            player.position.x -= 3;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            player.position.x += 3;
        }

        ClearBackground(BLACK);
        player.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}