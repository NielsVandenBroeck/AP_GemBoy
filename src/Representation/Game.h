//
// Created by niels on 24/11/2022.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "../Logic/Stopwatch.h"
#include "SFML/Graphics.hpp"
#include "StateManager.h"
#include <map>
#include <memory>

/**
 * The Game Class is The main loop of the game.
 */
class Game {
public:
    /**
     * constructor of the class Game
     * @param x : the width of the screen
     * @param y : the height of the screen
     */
    Game(int x, int y);

    /**
     * starts the main game loop
     */
    void run();

private:
    /**
     * function that gets called every frame
     * @param event : input event like mouse click of button pressed
     */
    void update(sf::Event event);

    std::shared_ptr<sf::RenderWindow> window;   // pointer to the window
    std::shared_ptr<StateManager> stateManager; // pointer to the stateManager
};

#endif // PROJECT_GAME_H
