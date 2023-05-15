//
// Created by niels on 24/11/2022.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include "Camera.h"
#include "LogicEntity.h"
#include <map>
#include <memory>
#include <vector>

/**
 * The World Class stores all the entities that belong to 1 certain level.
 */
class World {
public:
    /**
     * destructor of the class World
     */
    virtual ~World();

    /**
     * updates the game's logic
     * @param inputs : user input (keyboard input)
     */
    void update(std::map<std::string, bool> inputs);

    /**
     * returns true if the player has reached the goal, false otherwise
     */
    bool reachedGoal();

    /**
     * returns true of the player is below the camera, false otherwise
     */
    bool gameOver();

    /**
     * sets the player
     * @param p : LogicPlayer
     */
    void setPlayer(std::shared_ptr<LogicPlayer> p);

    /**
     * sets the goal
     * @param goal : LogicGoal
     */
    void setGoal(std::shared_ptr<LogicGoal> goal);

    /**
     * sets the walls
     * @param walls : vector of walls
     */
    void setWalls(std::vector<std::shared_ptr<LogicWall>> walls);

private:
    std::shared_ptr<LogicPlayer> player;           // pointer to the player
    std::shared_ptr<LogicGoal> goal;               // pointer to the goal
    std::vector<std::shared_ptr<LogicWall>> walls; // vector of pointers to the walls
};

#endif // PROJECT_WORLD_H
