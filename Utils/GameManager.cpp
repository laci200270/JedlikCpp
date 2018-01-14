//
// Created by laci200270 on 2018.01.13..
//

#include "../headers/GameManager.h"

bool GameManager::isGameRunning = false;

bool GameManager::getGameRunning() {
    return isGameRunning;
}

void GameManager::startGame() {
    isGameRunning = true;
}
