#pragma once
#include "player.hpp"

class Game {
public:
    Game() {

    }
    ~Game() {

    }

    void Draw() {
        player.Draw();
    }

    void Update() {

    }

    void HandleInput() {
        if (IsKeyDown(KEY_LEFT)) {
            player.MoveLeft();
        }
        if (IsKeyDown(KEY_RIGHT)) {
            player.MoveRight();
        }
    }
private:
    Player player;
};