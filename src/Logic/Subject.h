//
// Created by niels on 13/12/2022.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

#include "Observer.h"
#include <vector>

/**
 * The Subject Class is the Parent of LogicEntity. You can add observers through this object to create a connection
 * between Logic an Representation Entities.
 */
class Subject {
public:
    /**
     * destructor of class Subject
     */
    virtual ~Subject() = default;

    /**
     * adds an observer to the list of observers
     * @param observer : observer that need to be updated later
     */
    void addObserver(std::shared_ptr<Observer> observer);

    /**
     * resets the pointers of observers
     */
    void deleteObservers();

protected:
    /**
     * calls the update function of all observers
     */
    void updateObservers();

private:
    std::vector<std::shared_ptr<Observer>> observers; // vector of pointers to the observers
};

#endif // PROJECT_SUBJECT_H
