//
// Created by niels on 13/12/2022.
//

#include "Observer.h"
#include "LogicEntity.h"

Observer::Observer(const std::shared_ptr<LogicEntity> logicEntity) : logicEntity(logicEntity) {
    logicEntity->addObserver(std::shared_ptr<Observer>(this));
}
