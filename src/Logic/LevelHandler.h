//
// Created by niels on 7/12/2022.
//

#ifndef PROJECT_LEVELHANDLER_H
#define PROJECT_LEVELHANDLER_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/stat.h>
#include <utility>
#include <vector>

#include "../json.hpp"
#include "AbstractFactory.h"
#include "Camera.h"
#include "FileException.h"
#include "World.h"

/**
 * The LevelHandler Class handles everything that has to do with the Level-files. Such as reading the files and checking
 * if they are configured correctly. It is implemented as a singleton Class.
 */
class LevelHandler {
public:
    /**
     * constructor of the class Levelhandler
     */
    LevelHandler();

    /**
     * returns the strings of the names of the levels
     */
    std::vector<std::string> getLevelNames();

    /**
     * returns the string of the levelname
     * @param level : index of the level
     * @return : string of levelname
     */
    std::string getLevelName(int level);

    /**
     * loads a level from a configuration file and generates the corresponding world, camera and entities
     * @param level : index of the level
     * @param factory : factory to easily create entities
     * @return : returns the world of the level
     */
    std::shared_ptr<World> loadLevel(int level, std::unique_ptr<AbstractFactory> factory);

    /**
     * checks if the given level is the last one available
     * @param level : index of the level
     * @return : true if its the last level, otherwise false
     */
    bool checkLastLevel(int level);

private:
    std::vector<std::pair<std::string, std::string>>
        levelNames; // vector of all levelnames with their corresponding file names: pair<levelname, filename>
};

#endif // PROJECT_LEVELHANDLER_H
