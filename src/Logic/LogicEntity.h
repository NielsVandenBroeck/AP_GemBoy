//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_LOGICENTITY_H
#define PROJECT_LOGICENTITY_H

#include "Camera.h"
#include "Stopwatch.h"
#include "Subject.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <utility>

class LogicWall;
class LogicGoal;

/**
 * The LogicEntity Class represents the Logic parts of an entity like keeping track of it's position.
 */
class LogicEntity : public Subject {
public:
    /**
     * constructor of the class LogicEntity
     * @param Xpos : X position of the entity
     * @param Ypos : Y position of the entity
     * @param camera : camera of the level
     */
    LogicEntity(float Xpos, float Ypos, std::shared_ptr<Camera> camera);

    /**
     * returns the representative X and Y position of the entity, calculated by the camera
     */
    std::pair<float, float> getViewPosition();

    /**
     * returns the logic X and Y position of the entity
     */
    std::pair<float, float> getLogicPosition();

    /**
     * returns the string that stands for the current animation texture
     */
    virtual std::string getAnimation();

protected:
    std::pair<float, float> position; // location of the entity
    std::shared_ptr<Camera> camera;   // pointer to the camera
};

/**
 * The LogicPlayer is a child of the LogicEntity Class. It handles movement and forces like gravity, as well as
 * collision detection between wall entities.
 */
class LogicPlayer : public LogicEntity {
public:
    /**
     * constructor of the class LogicPlayer
     * @param Xpos : X position of the player
     * @param Ypos : Y position of the player
     * @param camera : camera of the level
     */
    LogicPlayer(float Xpos, float Ypos, std::shared_ptr<Camera> camera);

    /**
     * updates the players position and animation and updates the observers
     * @param walls : vector of walls. these are needed to check collisions
     */
    void update(const std::vector<std::shared_ptr<LogicWall>> walls);

    /**
     * handles moving left by increasing the horizontal speed
     */
    void moveLeft();

    /**
     * handles moving right by increasing the horizontal speed
     */
    void moveRight();

    /**
     * handles jumping by increasing the speed
     * vertical if jumping normally,
     * vertical and horizontal if jumping from wall
     */
    void jump();

    /**
     * imitates gravitational pull by decreasing the vertical speed
     */
    void applyGravity();

    /**
     * imitates traction by decreasing the horizontal speed
     */
    void applyTraction();

    /**
     * checks if the player collided with walls
     * @param walls : vector of LogicWalls
     */
    void checkCollisions(const std::vector<std::shared_ptr<LogicWall>> walls);

    /**
     * checks if the player is colliding with the borders (if no walls are there)
     */
    void checkBorders();

    /**
     * checks if the player has reached the goal by comparing their positions
     * @param goal : LogicGoal
     * @return true if it reached the goal, false otherwise
     */
    bool checkGoal(const std::shared_ptr<LogicGoal> goal);

    /**
     * checks if the player is outside the camera's view
     * @return true if he is outside, false otherwise
     */
    bool gameOver();

    /**
     * returns the string of the current animation texture
     */
    std::string getAnimation() override;

private:
    /**
     * handles the collision with a wall
     * @param wall : logicWall
     */
    void checkCollision(const std::shared_ptr<LogicWall> wall);

    /**
     * sets all the collision booleans to false in the map<string,bool> collision
     */
    void resetCollision();

    /**
     * checks the players movement and collision and changes the animation string to make it fit
     */
    void updateAnimation();

    float horizontalSpeed = 0; // amount of speed the player moves horizontally. negative -> left, positive -> right.
    float verticalSpeed = 0;   // amount of speed the player moves vertically. negative -> down, positive -> up.
    std::map<std::string, bool> collision; // map that keeps track of the collisions, true means a collision is
                                           // detected.
    std::pair<std::string, float> animation;
};

/**
 * The LogicGoal is a child of the LogicEntity Class. It represents the Finish of the level.
 */
class LogicGoal : public LogicEntity {
public:
    /**
     * constructor of the class LogicGoal
     * @param Xpos : X position of the goal
     * @param Ypos : Y position of the goal
     * @param camera : camera of the level
     */
    LogicGoal(float Xpos, float Ypos, std::shared_ptr<Camera> camera);

    /**
     * updates the observers
     */
    void update();
};

/**
 * The LogicWall is a child of the LogicEntity Class. It represents the walls and borders of the environment.
 */
class LogicWall : public LogicEntity {
public:
    /**
     * constructor of the class LogicWall
     * @param Xpos : X position of the wall
     * @param Ypos : Y position of the wall
     * @param camera : camera of the level
     */
    LogicWall(float Xpos, float Ypos, std::shared_ptr<Camera> camera);

    /**
     * updates the observers
     */
    void update();
};

#endif // PROJECT_LOGICENTITY_H
