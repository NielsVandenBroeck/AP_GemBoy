//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_CONCRETEFACTORY_H
#define PROJECT_CONCRETEFACTORY_H

#include "../Logic/AbstractFactory.h"
#include "RepresentationEntity.h"
#include "SFML/Graphics.hpp"
#include <memory>

/**
 * The ConcreteFactory is a child of the AbstractFactory Class.
 * It has access to the RepresentationEntities and can create them without the caller having to know anything about it.
 * It has a function for each entity to create.
 */
class ConcreteFactory : public AbstractFactory {
public:
    /**
     * constructor of the class ConcreteFactory
     * @param window
     */
    explicit ConcreteFactory(std::shared_ptr<sf::RenderWindow> window);
    /**
     * creates a player entity on both representation as logic side
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the player
     * @param Ypos :the initial Y location of the player
     * @return : returns the logicPlayer in a shared pointer
     */
    std::shared_ptr<LogicPlayer> createPlayer(std::shared_ptr<Camera> camera, float Xpos, float Ypos) override;

    /**
     * creates a wall entity on both representation as logic side
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the wall
     * @param Ypos :the initial Y location of the wall
     * @return : returns the logicWall in a shared pointer
     */
    std::shared_ptr<LogicWall> createWall(std::shared_ptr<Camera> camera, float Xpos, float Ypos) override;

    /**
     * creates a goal entity on both representation as logic side
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the goal
     * @param Ypos :the initial Y location of the goal
     * @return : returns the logicGoal in a shared pointer
     */
    std::shared_ptr<LogicGoal> createGoal(std::shared_ptr<Camera> camera, float Xpos, float Ypos) override;

private:
    std::shared_ptr<sf::RenderWindow> window; // pointer to the window
};

#endif // PROJECT_CONCRETEFACTORY_H
