#pragma once
#include "raylib.h"

class Player {
public:
    Vector2 position;
    Texture2D texture;
    Image image;

    Player() {
        image = LoadImage("../../assets/player.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position.x = (GetScreenWidth() - image.width) / 2;
        position.y = GetScreenHeight() - image.height;
    }
    ~Player() {
        UnloadTexture(texture);
    }

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    void MoveLeft() {
        position.x -= 4;
        if (position.x < 0) {
            position.x = 0;
        }
    }

    void MoveRight() {
        position.x += 4;
        if (position.x > GetScreenWidth() - image.width) {
            position.x = GetScreenWidth() - image.width;
        }
    }

    void Fire() {

    }
};