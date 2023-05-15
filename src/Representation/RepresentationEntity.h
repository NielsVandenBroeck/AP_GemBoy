//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_REPRESENTATIONENTITY_H
#define PROJECT_REPRESENTATIONENTITY_H

#include "../Logic/LogicEntity.h"
#include "../Logic/Observer.h"
#include "SFML/Graphics.hpp"
#include <memory>

/**
 * The RepresentationEntity is a child of the Observer class. It stands for the Representation of the entity on screen,
 * like its texture.
 */
class RepresentationEntity : public Observer {
public:
    /**
     * constructor of the class RepresentationEntity
     * @param window : the window where you can draw stuff on
     * @param logicEntity : the logic part of the entity
     */
    RepresentationEntity(const std::shared_ptr<sf::RenderWindow> window,
                         const std::shared_ptr<LogicEntity> logicEntity);
    /**
     * draws the sprite with the correct position
     */
    void update() override;

protected:
    sf::Sprite sprite;                        // sprite that represents the entity
    std::unique_ptr<sf::Texture> texture;     // pointer to a texture that needs to be put on the sprite
    std::shared_ptr<sf::RenderWindow> window; // pointer to the window
};

/**
 * The RepresentationPlayer is a child of the RepresentationEntity class.
 */
class RepresentationPlayer : public RepresentationEntity {
public:
    /**
     * contructor of the class RepresentationPlayer
     */
    RepresentationPlayer(const std::shared_ptr<sf::RenderWindow> window,
                         const std::shared_ptr<LogicPlayer> logicPlayer);

    /**
     * draws the sprite with the correct texture ans position
     */
    void update() override;
};

/**
 * The RepresentationWall is a child of the RepresentationEntity class.
 */
class RepresentationWall : public RepresentationEntity {
public:
    /**
     * contructor of the class RepresentationWall
     */
    RepresentationWall(const std::shared_ptr<sf::RenderWindow> window, const std::shared_ptr<LogicWall> logicWall);
};

/**
 * The RepresentationGoal is a child of the RepresentationEntity class.
 */
class RepresentationGoal : public RepresentationEntity {
public:
    /**
     * contructor of the class RepresentationGoal
     */
    RepresentationGoal(const std::shared_ptr<sf::RenderWindow> window, const std::shared_ptr<LogicGoal> logicGoal);
};

#endif // PROJECT_REPRESENTATIONENTITY_H
