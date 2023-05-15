//
// Created by niels on 7/12/2022.
//

#include "LevelHandler.h"

using json = nlohmann::json;

LevelHandler::LevelHandler() {
    const char* dirPath = "../Levels";
    struct stat sb {};
    // open the levels map
    if (stat(dirPath, &sb) != 0) {
        std::cout << "The directory 'Levels' (where the level configuration files should be) is not found."
                  << std::endl;
        return;
    }
    // read all files inside the levels map
    for (const auto& file : std::filesystem::directory_iterator(dirPath)) {
        json j;
        std::ifstream levelFile;
        levelFile.open(file.path(), std::ios::out);
        levelFile >> j;
        if (j.find("name") == j.end()) {
            continue;
        }
        levelNames.emplace_back(j["name"].get<std::string>(), file.path());
        levelFile.close();
    }
    if (levelNames.empty()) {
        std::cout << "The directory 'Levels' does not contain any levels." << std::endl;
    }
}

std::vector<std::string> LevelHandler::getLevelNames() {
    std::vector<std::string> names;
    for (const auto& x : levelNames) {
        names.emplace_back(x.first);
    }
    return names;
}

std::string LevelHandler::getLevelName(int level) { return levelNames[level - 1].first; }

std::shared_ptr<World> LevelHandler::loadLevel(int level, std::unique_ptr<AbstractFactory> factory) {
    // open levelFile
    std::string fileName = levelNames[level - 1].second;
    json j;
    std::ifstream levelFile;
    levelFile.open(fileName, std::ios::out);
    levelFile >> j;
    if (!levelFile) {
        throw Nofilesfound();
    }
    if (j.find("name") == j.end()) {
        throw IncorrectFile();
    }
    if (j.find("rising_speed") == j.end()) {
        throw IncorrectFile();
    }
    if (j.find("environment") == j.end()) {
        throw IncorrectFile();
    }
    std::shared_ptr<Camera> camera =
        std::make_shared<Camera>(j["environment"].size() - 2, j["rising_speed"].get<float>());
    std::shared_ptr<World> world = std::make_shared<World>();
    std::vector<std::shared_ptr<LogicWall>> walls;
    // read environment
    bool player = false;
    bool goal = false;
    for (int y = j["environment"].size() - 1; y >= 0; y--) {
        if (j["environment"][y].size() != 15) {
            throw IncorrectFile();
        }
        for (int x = 0; x < 15; x++) {
            float Xpos = float(x / 7.5) - 1;
            float Ypos = int(j["environment"].size() - 2 - y);
            switch (j["environment"][y][x].get<int>()) {
            case 1:
                walls.emplace_back(factory->createWall(camera, Xpos, Ypos));
                break;
            case 2:
                // check if the player doesnt exist already
                if (player) {
                    throw IncorrectFile();
                }
                world->setPlayer(factory->createPlayer(camera, Xpos, Ypos));
                player = true;
                break;
            case 3:
                // check if the goal doesnt exist already
                if (goal) {
                    throw IncorrectFile();
                }
                world->setGoal(factory->createGoal(camera, Xpos, Ypos));
                goal = true;
                break;
            }
        }
    }
    if (!player || !goal) {
        throw IncorrectFile();
    }
    world->setWalls(walls);
    levelFile.close();
    return world;
}

bool LevelHandler::checkLastLevel(int level) {
    if (level == levelNames.size()) {
        return true;
    }
    return false;
}
