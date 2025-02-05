#pragma once
#include "raylib.h"

class Bullet {
public:
    Image image;
    Texture2D texture;
    bool active;

    Bullet(Vector2 position, int speed) {
        this -> position = position;
        this -> speed = speed;
        active = true;
        image = LoadImage("../../assets/bullet.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Bullet() {
        UnloadTexture(texture);
    }

    void Update() {
        position.y -= speed;
        if (active) {
            if (position.y < 0 || position.y > GetScreenHeight()) {
                active = false;
            }
        }
    }

    void Draw() {
        if (active) {
            DrawTextureEx(texture, position, 0.0f, 4.0f, WHITE);
        }
    }

    Rectangle getRect() {
        return {position.x, position.y, float(texture.width * 4), float(texture.height * 4)};
    }
private:
    Vector2 position;
    int speed;
};