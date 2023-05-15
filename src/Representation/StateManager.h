//
// Created by niels on 7/12/2022.
//

#ifndef PROJECT_STATEMANAGER_H
#define PROJECT_STATEMANAGER_H

#include "../Logic/LevelHandler.h"
#include "SFML/Graphics.hpp"
#include "State.h"
#include <memory>

/**
 * The StateManager Class keeps track of the current State the game is in at a moment.
 */
class StateManager {
public:
    /**
     * constructor of the class Statemanager
     * @param window : the window where you can draw stuff on
     */
    explicit StateManager(const std::shared_ptr<sf::RenderWindow> window);

    /**
     * changes the current state to a given LevelState
     * @param state : the level state that needs to become the current state
     */
    void changeToLevelState(const std::shared_ptr<LevelState> state);

    /**
     * changes the current state to the MenuState
     */
    void changeToMenuState();

    /**
     * returns the current active state
     * @return the currentState
     */
    std::shared_ptr<State> getCurrentState();

private:
    std::shared_ptr<MenuState> menuState; // pointer to the menuState
    std::shared_ptr<State> currentState;  // pointer to the current State
};

#endif // PROJECT_STATEMANAGER_H
