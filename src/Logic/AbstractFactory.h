//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_ABSTRACTFACTORY_H
#define PROJECT_ABSTRACTFACTORY_H

#include "LogicEntity.h"
#include "World.h"

/**
 * The AbstractFactory makes it possible to easily create entities without having to know much about them.
 * It has a function for each entity to create.
 */
class AbstractFactory {
public:
    /**
     * pure virtual function that creates a player entity
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the player
     * @param Ypos :the initial Y location of the player
     * @return : returns the logicPlayer in a shared pointer
     */
    virtual std::shared_ptr<LogicPlayer> createPlayer(std::shared_ptr<Camera> camera, float Xpos, float Ypos) = 0;

    /**
     * pure virtual function that creates a wall entity
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the wall
     * @param Ypos :the initial Y location of the wall
     * @return : returns the logicWall in a shared pointer
     */
    virtual std::shared_ptr<LogicWall> createWall(std::shared_ptr<Camera> camera, float Xpos, float Ypos) = 0;

    /**
     * pure virtual function that creates a goal entity
     * @param camera : the camera that converts logic positions to a position on screen
     * @param Xpos : the initial X location of the goal
     * @param Ypos :the initial Y location of the goal
     * @return : returns the logicGoal in a shared pointer
     */
    virtual std::shared_ptr<LogicGoal> createGoal(std::shared_ptr<Camera> camera, float Xpos, float Ypos) = 0;

    /**
     * default destructor of the class AbstractFactory
     */
    virtual ~AbstractFactory() = default;
};

#endif // PROJECT_ABSTRACTFACTORY_H
