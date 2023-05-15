//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <memory>

class LogicEntity;

/**
 * The Observer Class is part of the Observer design pattern. It creates a connection between the LogicEntity and
 * RepresentationEntity.
 */
class Observer {
public:
    /**
     * constructor of the class Observer
     * @param logicEntity : the entity to observe
     */
    explicit Observer(const std::shared_ptr<LogicEntity> logicEntity);

    /**
     * destructor of class Observer
     */
    virtual ~Observer() = default;

    /**
     * pure virtual function that updates the entity
     */
    virtual void update() = 0;

protected:
    std::shared_ptr<LogicEntity> logicEntity; // pointer to the corresponding entity
};

#endif // PROJECT_OBSERVER_H
