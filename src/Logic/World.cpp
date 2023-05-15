//
// Created by niels on 24/11/2022.
//

#include "World.h"

World::~World() {
    // reset the observer pointers to the entities
    player->deleteObservers();
    goal->deleteObservers();
    for (auto wall : walls) {
        wall->deleteObservers();
    }
}

void World::update(std::map<std::string, bool> inputs) {
    // if both Left and Right is pressed, dont move
    if (!(inputs["Right"] && inputs["Left"])) {
        if (inputs["Right"]) {
            player->moveRight();
        }
        if (inputs["Left"]) {
            player->moveLeft();
        }
    }
    if (inputs["Jump"]) {
        player->jump();
    }
    player->update(walls);
    goal->update();
    for (auto& wall : walls) {
        wall->update();
    }
}

bool World::reachedGoal() { return player->checkGoal(goal); }

bool World::gameOver() { return player->gameOver(); }

void World::setPlayer(std::shared_ptr<LogicPlayer> p) { player = p; }

void World::setGoal(std::shared_ptr<LogicGoal> g) { goal = g; }

void World::setWalls(std::vector<std::shared_ptr<LogicWall>> w) { walls = w; }
