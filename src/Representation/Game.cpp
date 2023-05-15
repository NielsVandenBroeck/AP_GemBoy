//
// Created by niels on 24/11/2022.
//

#include "Game.h"

Game::Game(int x, int y) {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x, y), "Gem Boy", sf::Style::Close | sf::Style::Titlebar);
    stateManager = std::make_shared<StateManager>(window);
    run();
}

void Game::run() {
    sf::Event event{};
    // main game loop
    while (window->isOpen()) {
        Stopwatch::GetInstance().start();
        if (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }
        }
        update(event);
        Stopwatch::GetInstance().stop();
    }
}

void Game::update(sf::Event event) { stateManager->getCurrentState()->update(event); }
