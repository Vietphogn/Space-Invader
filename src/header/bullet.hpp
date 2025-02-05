#pragma once
#include "raylib.h"

class Bullet {
public:
    Image image;
    Texture2D texture;

    Bullet(Vector2 position, int speed) {
        this -> position = position;
        this -> speed = speed;
        image = LoadImage("assets/bullet.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Bullet() {
        UnloadTexture(texture);
    }

    void Update() {

    }

    void Draw() {
        DrawTexture(texture, position.x, position.y, WHITE);
    }
private:
    Vector2 position;
    int speed;
};