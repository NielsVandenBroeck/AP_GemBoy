//
// Created by niels on 13/12/2022.
//

#include "RepresentationEntity.h"

RepresentationEntity::RepresentationEntity(const std::shared_ptr<sf::RenderWindow> window,
                                           const std::shared_ptr<LogicEntity> logicEntity)
    : Observer(logicEntity), window(window) {
    texture = std::make_unique<sf::Texture>();
}

void RepresentationEntity::update() {
    std::pair<float, float> viewPosition = this->logicEntity->getViewPosition();
    sprite.setPosition(viewPosition.first, viewPosition.second);
    window->draw(sprite);
}

RepresentationPlayer::RepresentationPlayer(const std::shared_ptr<sf::RenderWindow> window,
                                           const std::shared_ptr<LogicPlayer> logicPlayer)
    : RepresentationEntity(window, logicPlayer) {}

void RepresentationPlayer::update() {
    std::pair<float, float> viewPosition = this->logicEntity->getViewPosition();
    // get animation from logic entity
    std::string animation = "../Textures/Player/" + this->logicEntity->getAnimation() + ".png";
    texture->loadFromFile(animation);
    sprite.setTexture(*texture);
    sprite.setPosition(viewPosition.first, viewPosition.second);
    window->draw(sprite);
}

RepresentationWall::RepresentationWall(const std::shared_ptr<sf::RenderWindow> window,
                                       const std::shared_ptr<LogicWall> logicWall)
    : RepresentationEntity(window, logicWall) {
    texture->loadFromFile("../Textures/Wall.png");
    sprite.setTexture(*texture);
}

RepresentationGoal::RepresentationGoal(const std::shared_ptr<sf::RenderWindow> window,
                                       const std::shared_ptr<LogicGoal> logicGoal)
    : RepresentationEntity(window, logicGoal) {
    texture->loadFromFile("../Textures/Goal.png");
    sprite.setTexture(*texture);
}