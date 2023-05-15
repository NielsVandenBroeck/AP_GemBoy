//
// Created by niels on 7/12/2022.
//

#include "StateManager.h"

StateManager::StateManager(const std::shared_ptr<sf::RenderWindow> window) {
    menuState = std::make_shared<MenuState>(window, *this, std::make_shared<LevelHandler>());
    currentState = menuState;
}

void StateManager::changeToLevelState(const std::shared_ptr<LevelState> state) { currentState = state; }

void StateManager::changeToMenuState() {
    currentState = menuState;
    menuState->displayLevels();
}

std::shared_ptr<State> StateManager::getCurrentState() { return currentState; }
