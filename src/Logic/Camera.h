//
// Created by niels on 24/11/2022.
//

#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H

#include "Stopwatch.h"
#include <cmath>
#include <utility>

/**
 * The Camera keeps track of the player's position in the world.
 * It also transforms the location of the LogicEntities to a location on the screen.
 */
class Camera {
public:
    /**
     * constructor of the class Camera
     * @param height : the maximum height of the level
     * @param risingSpeed : the speed that the camera automatically has to rise
     */
    Camera(int height, float risingSpeed);

    /**
     * rises the camera whenever the player's height is above 80% of the screen
     * @param playerHeight : the height of the player
     */
    void update(float playerHeight);

    /**
     * transforms a location in the level to a position on screen
     * @param logicPosition : the x and y value of the entitie
     * @return : a pair that contains the x and y value for the representation entity on screen
     */
    std::pair<float, float> transformPositionToView(std::pair<float, float> logicPosition) const;

    /**
     * checks if the player is inside the view of the camera
     * @param playerHeight : the height of the player
     * @return : if the player is below the camera, the game should restart and returns false, if not, then true
     */
    bool checkPlayerHeight(float playerHeight) const;

    /**
     * returns the maximum height of the level
     * @return the maximum height of the level
     */
    float getMaxheight() const;

private:
    float maxHeight;          // the maximum height of the level
    float currentHeight = 18; // the current height of the view, it can only be between 18 and MaxHeight
    float risingSpeed;        // the amount of speed that the view rises
};

#endif // PROJECT_CAMERA_H
