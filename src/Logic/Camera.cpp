//
// Created by niels on 24/11/2022.
//

#include "Camera.h"

Camera::Camera(int height, float speed) : maxHeight(height), risingSpeed(speed) {}

void Camera::update(float playerHeight) {
    currentHeight = std::min(maxHeight, float(currentHeight + (risingSpeed * Stopwatch::GetInstance().getDeltaTime())));
    // rise if the player is above 80% of the view
    if (playerHeight > currentHeight - 4) {
        currentHeight = std::min(maxHeight, float(playerHeight + 4));
    }
}

std::pair<float, float> Camera::transformPositionToView(std::pair<float, float> logicPosition) const {
    // calculate the position on screen
    std::pair<float, float> viewPosition =
        std::make_pair((logicPosition.first + 1) * 300, (currentHeight - logicPosition.second) * 40);
    return viewPosition;
}

bool Camera::checkPlayerHeight(float playerHeight) const {
    return playerHeight >= currentHeight - 20;
}

float Camera::getMaxheight() const { return maxHeight; }
