//
// Created by niels on 13/12/2022.
//

#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory(std::shared_ptr<sf::RenderWindow> window) : window(window) {}

std::shared_ptr<LogicPlayer> ConcreteFactory::createPlayer(std::shared_ptr<Camera> camera, float Xpos, float Ypos) {
    std::shared_ptr<LogicPlayer> logicPlayer = std::make_shared<LogicPlayer>(Xpos, Ypos, camera);
    new RepresentationPlayer(window, logicPlayer);
    return logicPlayer;
}

std::shared_ptr<LogicWall> ConcreteFactory::createWall(std::shared_ptr<Camera> camera, float Xpos, float Ypos) {
    std::shared_ptr<LogicWall> logicWall = std::make_shared<LogicWall>(Xpos, Ypos, camera);
    new RepresentationWall(window, logicWall);
    return logicWall;
}

std::shared_ptr<LogicGoal> ConcreteFactory::createGoal(std::shared_ptr<Camera> camera, float Xpos, float Ypos) {
    std::shared_ptr<LogicGoal> logicGoal = std::make_shared<LogicGoal>(Xpos, Ypos, camera);
    new RepresentationGoal(window, logicGoal);
    return logicGoal;
}
