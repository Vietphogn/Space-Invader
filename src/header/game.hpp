#pragma once
#include "player.hpp"
#include "enemy.hpp"
#include <iostream>

class Game {
public:
    bool run;

    Game() {
        InitGame();
    }
    ~Game() {
        for (int i = 0; i < enemies.size(); ++i) {
            enemies[i].UnloadEnemyTexture();
        }
    }

    void Draw() {
        player.Draw();

        for (auto& bullet : player.bullets) {
            bullet.Draw();
        }

        for (auto& enemy : enemies) {
            enemy.Draw();
        }

        for (auto& bullet : enemyBullets) {
            bullet.Draw();
        }
    }

    void Update() {
        if (run) {
            for (auto& bullet : player.bullets) {
                bullet.Update();
            }

            MoveEnemies();
            EnemyShoot();
            
            for (auto& bullet : enemyBullets) {
                bullet.Update();
            }

            DeleteInactiveBullets();
            CheckForCollisions();
        }
    }

    void HandleInput() {
        if (run) {
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
        else {
            if (IsKeyPressed(KEY_R)) {
                ResetGame();
                InitGame();
            }
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

        for (auto it = enemyBullets.begin(); it != enemyBullets.end();) {
            if (!it -> active) {
                it = enemyBullets.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    std::vector<Enemy> CreateEnemies() {
        std::vector<Enemy> enemies;
        
        for (int row = 0; row < 5; ++row) {
            for (int column = 0; column < 15; ++column) {
                float x = column * 40 + 90;
                float y = row * 40 + 100;
                enemies.push_back(Enemy({x, y}));
            }
        }

        return enemies;
    }

    void MoveEnemies() {
        for (auto& enemy : enemies) {
            if (enemy.position.x + enemy.texture.width * 3 > GetScreenWidth()) {
                enemiesDirection = -3;
                MoveDownEnemies(4);
            }
            if (enemy.position.x < 0) {
                enemiesDirection = 3;
                MoveDownEnemies(4);
            }
            enemy.Update(enemiesDirection);
        }
    }

    void MoveDownEnemies(int distance) {
        for (auto& enemy : enemies) {
            enemy.position.y += distance;
        }
    }

    void EnemyShoot() {
        double currentTime = GetTime();
        
        if (currentTime - timeLastEnemyFired >= enemyShootInterval && !enemies.empty()) {
            int randomIndex = GetRandomValue(0, enemies.size() - 1);
            Enemy& enemy = enemies[randomIndex];
            enemyBullets.push_back(Bullet({enemy.position.x + enemy.texture.width * 3 / 2, enemy.position.y + enemy.texture.height}, -6));
            timeLastEnemyFired = GetTime();
        }
    }

    void CheckForCollisions() {
        //Player bullets
        for (auto& bullet : player.bullets) {
            auto it = enemies.begin();
            while (it != enemies.end()) {
                if (CheckCollisionRecs(it -> getRect(), bullet.getRect())) {
                    it = enemies.erase(it);
                    bullet.active = false;
                }
                else {
                    ++it;
                }
            }
        }

        //Enemies bullets
        for (auto& bullet : enemyBullets) {
            if (CheckCollisionRecs(bullet.getRect(), player.getRect())) {
                bullet.active = false;
                --lives;
                if (lives == 0) {
                    GameOver();
                }
            }
        }

        //Enemies Collision with Player
        for (auto& enemy : enemies) {
            if (CheckCollisionRecs(enemy.getRect(), player.getRect())) {

            }
        }
    }

    void InitGame() {
        enemies = CreateEnemies();
        enemiesDirection = 3;
        timeLastEnemyFired = 0.0;
        lives = 3;
        run = true;
    }

    void GameOver() {
        run = false;
    }

    void ResetGame() {
        player.Reset();
        enemies.clear();
        enemyBullets.clear();
    }

    Player player;
    std::vector<Enemy> enemies;
    int enemiesDirection;
    std::vector<Bullet> enemyBullets;
    constexpr static float enemyShootInterval = 0.2;
    float timeLastEnemyFired;
    int lives;
};