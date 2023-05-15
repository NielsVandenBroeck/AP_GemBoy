cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS graphics window system)

add_library(Logic
        src/Logic/Camera.h
        src/Logic/Camera.cpp
        src/Logic/Stopwatch.h
        src/Logic/Stopwatch.cpp
        src/Logic/World.h
        src/Logic/World.cpp
        src/Logic/LevelHandler.h
        src/Logic/LevelHandler.cpp
        src/Logic/AbstractFactory.h
        src/Logic/Subject.h
        src/Logic/Subject.cpp
        src/Logic/LogicEntity.h
        src/Logic/LogicEntity.cpp
        src/Logic/Observer.h
        src/Logic/Observer.cpp
        src/Logic/FileException.h
        )

add_executable(Project
        src/main.cpp
        src/Representation/Game.h
        src/Representation/Game.cpp
        src/Representation/StateManager.h
        src/Representation/StateManager.cpp
        src/Representation/State.h
        src/Representation/State.cpp
        src/Representation/ConcreteFactory.h
        src/Representation/ConcreteFactory.cpp
        src/Representation/RepresentationEntity.h
        src/Representation/RepresentationEntity.cpp
        )

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
target_link_libraries(Project Logic sfml-graphics sfml-window sfml-system)