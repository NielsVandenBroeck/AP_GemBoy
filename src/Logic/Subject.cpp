//
// Created by niels on 13/12/2022.
//

#include "Subject.h"

void Subject::updateObservers() {
    for (auto& observer : observers) {
        observer->update();
    }
}

void Subject::addObserver(std::shared_ptr<Observer> observer) { observers.emplace_back(observer); }

void Subject::deleteObservers() {
    for (auto& observer : observers) {
        observer.reset();
    }
}
