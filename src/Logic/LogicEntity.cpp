//
// Created by niels on 13/12/2022.
//

#include "LogicEntity.h"

LogicEntity::LogicEntity(float Xpos, float Ypos, std::shared_ptr<Camera> camera) : camera(camera) {
    position = std::make_pair(Xpos, Ypos);
}

std::pair<float, float> LogicEntity::getViewPosition() { return camera->transformPositionToView(position); }

std::pair<float, float> LogicEntity::getLogicPosition() { return position; }

std::string LogicEntity::getAnimation() { return ""; }

LogicPlayer::LogicPlayer(float Xpos, float Ypos, std::shared_ptr<Camera> camera) : LogicEntity(Xpos, Ypos, camera) {
    resetCollision();
}

void LogicPlayer::update(const std::vector<std::shared_ptr<LogicWall>> walls) {
    // first add value to x and y position (moving)
    position.first += horizontalSpeed * Stopwatch::GetInstance().getDeltaTime();
    position.second += verticalSpeed * Stopwatch::GetInstance().getDeltaTime();
    // accelerations
    applyGravity();
    applyTraction();
    // collisions
    resetCollision();
    checkCollisions(walls);
    checkBorders();
    updateAnimation();
    camera->update(position.second);
    updateObservers();
}

void LogicPlayer::moveLeft() {
    if (!collision["Left"]) {
        horizontalSpeed =
            std::max(float(horizontalSpeed - (10 * Stopwatch::GetInstance().getDeltaTime())), float(-1.5));
    }
}

void LogicPlayer::moveRight() {
    if (!collision["Right"]) {
        horizontalSpeed = std::min(float(horizontalSpeed + (10 * Stopwatch::GetInstance().getDeltaTime())), float(1.5));
    }
}

void LogicPlayer::jump() {
    if (collision["Bottom"]) {
        verticalSpeed = 20.0;
    } else if (collision["Left"]) {
        verticalSpeed = 20.0;
        horizontalSpeed = 2.0;
    } else if (collision["Right"]) {
        verticalSpeed = 20.0;
        horizontalSpeed = -2.0;
    }
}

void LogicPlayer::applyGravity() {
    if (collision["Left"] || collision["Right"]) {
        verticalSpeed = std::max(float(verticalSpeed - (100 * Stopwatch::GetInstance().getDeltaTime())), float(-5.0));
    } else if (!collision["Bottom"]) {
        verticalSpeed -= 50 * Stopwatch::GetInstance().getDeltaTime();
    }
}

void LogicPlayer::applyTraction() {
    float amount = 3;
    if (collision["Bottom"]) {
        amount = 6;
    }
    if (horizontalSpeed < 0) {
        horizontalSpeed =
            std::min(float(horizontalSpeed + (Stopwatch::GetInstance().getDeltaTime() * amount)), float(0.0));
    } else if (horizontalSpeed > 0) {
        horizontalSpeed =
            std::max(float(horizontalSpeed - (Stopwatch::GetInstance().getDeltaTime() * amount)), float(0.0));
    }
}

void LogicPlayer::checkCollisions(const std::vector<std::shared_ptr<LogicWall>> walls) {
    for (auto& wall : walls) {
        std::pair<float, float> WallPos = wall->getLogicPosition();
        // if wall is not in radius of player, continue
        if (WallPos.first > position.first + 0.133334)
            continue;
        if (WallPos.first < position.first - 0.133334)
            continue;
        if (WallPos.second > position.second + 1)
            continue;
        if (WallPos.second < position.second - 1)
            continue;
        checkCollision(wall);
    }
}

void LogicPlayer::checkBorders() {
    if (position.first >= 1 - 0.133333) {
        collision["Right"] = true;
        horizontalSpeed = 0;
        this->position.first = 1 - 0.133333;
    }
    if (position.first <= -1) {
        collision["Left"] = true;
        horizontalSpeed = 0;
        this->position.first = -1;
    }
    if (position.second > camera->getMaxheight()) {
        collision["Top"] = true;
        verticalSpeed = std::min(verticalSpeed, float(0.0));
        position.second = camera->getMaxheight();
    }
}

bool LogicPlayer::checkGoal(const std::shared_ptr<LogicGoal> goal) {
    return (goal->getLogicPosition().first < position.first + 0.133333 &&
            goal->getLogicPosition().first > position.first - 0.133333 &&
            goal->getLogicPosition().second < position.second + 1 &&
            goal->getLogicPosition().second > position.second - 1);
}

bool LogicPlayer::gameOver() { return !camera->checkPlayerHeight(position.second); }

void LogicPlayer::checkCollision(const std::shared_ptr<LogicWall> wall) {
    // case wel player's corner hits walls corner and doesnt know which collision (side) it should be, so skip
    if (std::abs(std::abs(((wall->getLogicPosition().first - position.first) * 7.5)) -
                 std::abs((wall->getLogicPosition().second - position.second))) < 0.05) {
        return;
    }
    // calculate the difference between player and wall with x and y, if space between x is bigger, than its left/right
    // collision, otherwise its top/bottom collision
    if (std::abs(wall->getLogicPosition().first - position.first) * 7.5 >
        std::abs(wall->getLogicPosition().second - position.second)) {
        // Left and Right
        if (wall->getLogicPosition().first <= this->getLogicPosition().first) {
            collision["Left"] = true;
            horizontalSpeed = 0;
            this->position.first = wall->getLogicPosition().first + 0.133333;
        } else {
            collision["Right"] = true;
            horizontalSpeed = 0;
            this->position.first = wall->getLogicPosition().first - 0.133333;
        }
    } else {
        // Top and Bottom
        if (wall->getLogicPosition().second <= position.second) {
            collision["Bottom"] = true;
            verticalSpeed = 0;
            position.second = wall->getLogicPosition().second + 1.0;
        } else {
            collision["Top"] = true;
            verticalSpeed = std::min(verticalSpeed, float(0.0));
            position.second = wall->getLogicPosition().second - 1.0;
        }
    }
}

void LogicPlayer::resetCollision() {
    collision["Top"] = false;
    collision["Bottom"] = false;
    collision["Left"] = false;
    collision["Right"] = false;
}

void LogicPlayer::updateAnimation() {
    // animations to make player look cooler
    animation.second += Stopwatch::GetInstance().getDeltaTime() * 4;
    if (horizontalSpeed != 0 && verticalSpeed != 0) {
        if (animation.second >= 2) {
            animation.second = 0;
        }
        if (horizontalSpeed > 0) {
            animation.first = "AirRight" + std::to_string(int(animation.second));
        } else {
            animation.first = "AirLeft" + std::to_string(int(animation.second));
        }
    } else if (horizontalSpeed != 0) {
        if (animation.second >= 4) {
            animation.second = 0;
        }
        if (horizontalSpeed > 0) {
            animation.first = "WalkRight" + std::to_string(int(animation.second));
        } else {
            animation.first = "WalkLeft" + std::to_string(int(animation.second));
        }
    } else if (verticalSpeed < 0) {
        if (animation.second >= 2) {
            animation.second = 0;
        }
        if (collision["Left"]) {
            animation.first = "WallLeft" + std::to_string(int(animation.second));
        }
        if (collision["Right"]) {
            animation.first = "WallRight" + std::to_string(int(animation.second));
        }
    } else {
        if (animation.second >= 4) {
            animation.second = 0;
        }
        animation.first = "Idle" + std::to_string(int(animation.second));
    }
}

std::string LogicPlayer::getAnimation() { return animation.first; }

LogicGoal::LogicGoal(float Xpos, float Ypos, std::shared_ptr<Camera> camera) : LogicEntity(Xpos, float(Ypos), camera) {}

void LogicGoal::update() { updateObservers(); }

LogicWall::LogicWall(float Xpos, float Ypos, std::shared_ptr<Camera> camera) : LogicEntity(Xpos, Ypos, camera) {}

void LogicWall::update() { updateObservers(); }