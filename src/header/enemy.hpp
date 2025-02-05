#pragma once 
#include "raylib.h"

class Enemy {
public:
    Texture2D texture = LoadTexture("../../assets/enemy.png");
    Vector2 position;

    Enemy(Vector2 position) {
        this -> position = position;
    }

    void Update() {

    }

    void Draw() {
        DrawTextureEx(texture, position, 0.0f, 3.0f, WHITE);
    }

private:

};