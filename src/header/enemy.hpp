#pragma once 
#include "raylib.h"

class Enemy {
public:
    Texture2D texture = LoadTexture("../../assets/enemy.png");
    Vector2 position;

    Enemy(Vector2 position) {
        this -> position = position;
    }

    void UnloadEnemyTexture() {
        UnloadTexture(texture);
    }

    void Update(int direction) {
        position.x += direction;
    }

    void Draw() {
        DrawTextureEx(texture, position, 0.0f, 3.0f, WHITE);
    }

    Rectangle getRect() {
        return {position.x, position.y, float(texture.width * 3), float(texture.height * 3)};
    }

private:

};