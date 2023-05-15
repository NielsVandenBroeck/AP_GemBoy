//
// Created by niels on 8/12/2022.
//

#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

#include "../Logic/FileException.h"
#include "../Logic/LevelHandler.h"
#include "../Logic/World.h"

#include "ConcreteFactory.h"
#include "SFML/Graphics.hpp"
#include "memory"
#include <iostream>

class StateManager;

/**
 * The State Class is used to determine in which state the game is currently in.
 */
class State {
public:
    /**
     * constructor of the class State
     * @param window : the window where you can draw stuff on
     * @param stateManager : the statemanager that holds which state is currently active
     * @param levelHandler : levelhandler that can open level configuration files
     */
    State(std::shared_ptr<sf::RenderWindow> window, StateManager& stateManager,
          std::shared_ptr<LevelHandler> levelHandler);

    /**
     * function that creates a new levelstate and loads a level through the levelhandler
     * @param level : index of the loaded level
     * @return : returns true if level is loaded correctly, false otherwise
     */
    bool loadLevel(int level);

    /**
     * pure virtual function that gets some user input.
     * @param event : user input
     */
    virtual void update(sf::Event event) = 0;

private:
protected:
    sf::Font font;                                  // font of the text
    StateManager& stateManager;                     // pointer to the stateManager
    std::shared_ptr<sf::RenderWindow> window;       // pointer to the window
    sf::Sprite background;                          // sprite that represents the background
    std::unique_ptr<sf::Texture> backgroundTexture; // pointer to a texture that needs to be put on the background
                                                    // sprite
    std::shared_ptr<LevelHandler> levelHandler;
};

/**
 * The MenuState is a child of the State Class and it handles everything of the Menu section like showing the levels and
 * making it possible to go into another level.
 */
class MenuState : public State {
public:
    /**
     * constructor of the class MenuState
     * @param window : the window where you can draw stuff on
     * @param stateManager : the statemanager that holds which state is currently active
     * @param levelHandler : levelhandler that can open level configuration files
     */
    MenuState(std::shared_ptr<sf::RenderWindow> window, StateManager& stateManager,
              std::shared_ptr<LevelHandler> levelHandler);

    /**
     * function that gets some mouse input and handles it when for example a level or scrollArrow is clicked
     * @param event : user input
     */
    void update(sf::Event event) override;

    /**
     * function that draws all the level texts on the window
     */
    void displayLevels();

private:
    /**
     * initializes the leveltexts by getting them from the levelhandler
     */
    void initMenu();

    /**
     * function that changes the list of levelnames on screen
     * @param direction : the direction of the scroll: up = 1 and down = -1
     */
    void handleScroll(int direction);

    bool lock = false;       // makes it unable to click things multiple times befor mousebutton is released
    int currentTopLevel = 1; // keeps track of the showing list of levels
    sf::Text title;          // title of the game
    std::unique_ptr<sf::Texture> scrollTexture; // pointer to a texture that needs to be put on the scroll sprites
    sf::Sprite scrollUp;                        // sprite that represents the scroll button
    sf::Sprite scrollDown;                      // sprite that represents the scroll button
    std::vector<sf::Text> levelTexts;           // titles of the levels
};

/**
 * The LevelState is a child of the State Class and it handles everything of in the level section like creating the
 * corresponding world and entities, and passing player input through it.
 */
class LevelState : public State {
public:
    /**
     * constructor of the class LevelState
     * @param window : the window where you can draw stuff on
     * @param stateManager : the statemanager that holds which state is currently active
     * @param levelHandler : levelhandler that can open level configuration files
     * @param level : index of the level
     * @param world : logic part that contains all the entities of the level
     */
    LevelState(std::shared_ptr<sf::RenderWindow> window, StateManager& stateManager,
               std::shared_ptr<LevelHandler> levelHandler, int level, std::shared_ptr<World> world);

    /**
     * function that gets keyboard input and sends it to the world in some format
     * @param event : user input
     */
    void update(sf::Event event) override;

private:
    /**
     * initializes the texts and background of the level
     */
    void initLevel();

    std::map<std::string, bool> inputs; // the keyboard inputs. pressed -> true, not pressed -> false
    bool jumping = false;               // checks if the jumping button is still pressed
    int level;                          // the index that stands for this level
    std::shared_ptr<World> world;       // pointer to the world
    sf::Text levelName;                 // name of the level
};

#endif // PROJECT_STATE_H
