#pragma once
#include "raylib.h"

class Bullet {
public:
    Bullet(Vector2 position, int speed) {
        this -> position = position;
        this -> speed = speed;
    }

    void Update() {

    }

    void Draw() {
        DrawRectangle(position.x, position.y, 4, 15, WHITE);
    }
private:
    Vector2 position;
    int speed;
};