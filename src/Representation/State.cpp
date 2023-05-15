//
// Created by niels on 8/12/2022.
//

#include "State.h"
#include "StateManager.h"

State::State(std::shared_ptr<sf::RenderWindow> w, StateManager& m, std::shared_ptr<LevelHandler> l)
    : stateManager(m), window(w), levelHandler(l) {
    font.loadFromFile("../Textures/font.ttf");
}

bool State::loadLevel(int level) {
    // try to load a level, skip if it goes wrong
    try {
        std::shared_ptr<World> world = levelHandler->loadLevel(level, std::make_unique<ConcreteFactory>(window));
        std::shared_ptr<LevelState> levelState =
            std::make_shared<LevelState>(window, stateManager, levelHandler, level, world);
        stateManager.changeToLevelState(levelState);
    } catch (FileException& e) {
        std::cout << e.explanation() << std::endl;
        return false;
    }
    return true;
}

MenuState::MenuState(std::shared_ptr<sf::RenderWindow> w, StateManager& m, std::shared_ptr<LevelHandler> l)
    : State(w, m, l) {
    initMenu();
    displayLevels();
}

void MenuState::displayLevels() {
    window->clear();
    window->draw(background);
    window->draw(title);
    // check if going up is an option
    if (currentTopLevel != 1) {
        window->draw(scrollUp);
    }
    // check if going down is an option
    if (currentTopLevel + 4 < levelTexts.size()) {
        window->draw(scrollDown);
    }
    // only show the current 5 levels
    for (int i = -1; i < 4; i++) {
        if (i + currentTopLevel >= levelTexts.size())
            break;
        levelTexts[i + currentTopLevel].setPosition(300, float((i + 4) * 80));
        window->draw(levelTexts[i + currentTopLevel]);
    }
    window->display();
}

void MenuState::update(sf::Event event) {
    if (event.type == sf::Event::MouseWheelMoved) {
        handleScroll(event.mouseWheel.delta);
        displayLevels();
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        lock = false;
    }
    if (event.type == sf::Event::MouseButtonPressed && !lock) {
        // lock mouseclick such that function cannot be executed multiple times in 1 click
        lock = true;
        int Xpos = event.mouseButton.x;
        int Ypos = event.mouseButton.y;
        // check position for level selection
        if (150 < Xpos && Xpos < 450 && 230 < Ypos && Ypos < 580) {
            loadLevel(((Ypos - 210) / 80) + currentTopLevel);
        }
        // check position for arrow pressed (scroll down)
        if (450 < Xpos && Xpos < 550 && 560 < Ypos && Ypos < 660) {
            handleScroll(-1);
        }
        // check position for arrow pressed (scroll up)
        if (450 < Xpos && Xpos < 550 && 150 < Ypos && Ypos < 250) {
            handleScroll(1);
        }
        displayLevels();
    }
}

void MenuState::initMenu() {
    title.setFont(font);
    title.setString("GEM BOY");
    title.setCharacterSize(50);
    title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
    title.setPosition(300, 100);
    title.setFillColor(sf::Color::Black);

    scrollTexture = std::make_unique<sf::Texture>();
    scrollTexture->loadFromFile("../Textures/Arrow.png");

    scrollUp.setTexture(*scrollTexture);
    scrollUp.setOrigin(scrollUp.getGlobalBounds().width / 2, scrollUp.getGlobalBounds().height / 2);
    scrollUp.scale(5.0f, 5.0f);
    scrollUp.setPosition(500, 200);

    scrollDown.setTexture(*scrollTexture);
    scrollDown.setOrigin(scrollDown.getGlobalBounds().width / 2, scrollDown.getGlobalBounds().height / 2);
    scrollDown.setRotation(180.0f);
    scrollDown.scale(5.0f, 5.0f);
    scrollDown.setPosition(500, 610);

    backgroundTexture = std::make_unique<sf::Texture>();
    backgroundTexture->loadFromFile("../Textures/MenuBackground.png");
    background.setTexture(*backgroundTexture);
    background.scale(10.0f, 10.0f);

    try {
        std::vector<std::string> levels = levelHandler->getLevelNames();
        for (auto& level : levels) {
            sf::Text levelText;
            levelText.setFont(font);
            levelText.setString(level);
            levelText.setFillColor(sf::Color::Black);

            levelText.setCharacterSize(30);
            levelText.setOrigin(levelText.getGlobalBounds().width / 2, levelText.getGlobalBounds().height / 2);
            levelTexts.emplace_back(levelText);
        }
    } catch (FileException& e) {
        std::cout << e.explanation() << std::endl;
    }
}

void MenuState::handleScroll(int direction) {
    if (direction == 1 && currentTopLevel != 1) {
        currentTopLevel--;
    }
    if (direction == -1 && currentTopLevel + 4 < levelTexts.size()) {
        currentTopLevel++;
    }
}

LevelState::LevelState(std::shared_ptr<sf::RenderWindow> window, StateManager& m,
                       std::shared_ptr<LevelHandler> lhandler, int l, std::shared_ptr<World> world)
    : State(window, m, lhandler), level(l), world(world) {
    inputs["Left"] = false;
    inputs["Right"] = false;
    inputs["Jump"] = false;
    initLevel();
}

void LevelState::update(sf::Event event) {
    window->clear();
    window->draw(background);
    // get user input and send to world
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            stateManager.changeToMenuState();
            return;
        }
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            inputs["Left"] = true;
        }
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            inputs["Right"] = true;
        }
        if (event.key.code == sf::Keyboard::Space && !jumping) {
            inputs["Jump"] = true;
            jumping = true;
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            inputs["Left"] = false;
        }
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            inputs["Right"] = false;
        }
        if (event.key.code == sf::Keyboard::Space) {
            jumping = false;
        }
    }
    world->update(inputs);
    inputs["Jump"] = false;
    window->draw(levelName);
    window->display();
    if (world->gameOver()) {
        loadLevel(level);
    }
    // if the player reached the goal, go to next level that did not throw an exception
    if (world->reachedGoal()) {
        if (levelHandler->checkLastLevel(level)) {
            stateManager.changeToMenuState();
            return;
        }
        int nextLevel = level + 1;
        while (!loadLevel(nextLevel)) {
            if (levelHandler->checkLastLevel(nextLevel)) {
                stateManager.changeToMenuState();
                return;
            }
            nextLevel++;
        }
    }
}

void LevelState::initLevel() {
    backgroundTexture = std::make_unique<sf::Texture>();
    backgroundTexture->loadFromFile("../Textures/LevelBackground.png");
    background.setTexture(*backgroundTexture);
    background.scale(2.5f, 2.5f);

    levelName.setFont(font);
    levelName.setString(levelHandler->getLevelName(level));
    levelName.setCharacterSize(30);
    levelName.setOrigin(levelName.getGlobalBounds().width / 2, levelName.getGlobalBounds().height / 2);
    levelName.setPosition(300, 15);
    levelName.setFillColor(sf::Color::Yellow);
}
