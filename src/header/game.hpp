#pragma once
#include "player.hpp"
#include "enemy.hpp"
#include <iostream>

class Game {
public:
    Game() {
        enemies = CreateEnemies();
    }
    ~Game() {

    }

    void Draw() {
        player.Draw();

        for (auto& bullet : player.bullets) {
            bullet.Draw();
        }
    }

    void Update() {
        for (auto& bullet : player.bullets) {
            bullet.Update();
        }

        DeleteInactiveBullets();
    }

    void HandleInput() {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            player.MoveLeft();
        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            player.MoveRight();
        }
        if (IsKeyPressed(KEY_SPACE)) {
            player.Fire();
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            player.Fire();
        }
    }
private:
    void DeleteInactiveBullets() {
        for (auto it = player.bullets.begin(); it != player.bullets.end();) {
            if (!it -> active) {
                it = player.bullets.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    std::vector<Enemy> CreateEnemies() {
        std::vector<Enemy> enemies;
        
        for (int row = 0; row < 5; ++row) {
            for (int column = 0; column < 11, ++column) {
                float x = column * 55;
                float y = row * 55;
                enemies.push_back(Enemy({x, y}));
            }
        }

        return enemies;
    }

    Player player;
    std::vector<Enemy> enemies;
};