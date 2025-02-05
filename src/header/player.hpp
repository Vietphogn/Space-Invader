#pragma once
#include "raylib.h"
#include "bullet.hpp"
#include <vector>

class Player {
public:
    Vector2 position;
    Texture2D texture;
    Image image;
    std::vector<Bullet> bullets;

    Player() {
        image = LoadImage("../../assets/player.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position.x = (GetScreenWidth() - image.width) / 2;
        position.y = GetScreenHeight() - image.height * 2;
    }
    ~Player() {
        UnloadTexture(texture);
    }

    void Draw() {
        DrawTextureEx(texture, position, 0.0f, 2.0f, WHITE);
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
        bullets.push_back(Bullet({position.x + image.width - 2, position.y}, 6));
    }

    Rectangle getRect() {
        return {position.x, position.y, float(texture.width * 2), float(texture.height * 2)};
    }

    void Reset() {
        position.x = (GetScreenWidth() - image.width) / 2;
        position.y = GetScreenHeight() - image.height * 2;
        bullets.clear();
    }
};