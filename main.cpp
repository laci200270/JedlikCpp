#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include "headers/World.h"
#include "headers/configs.h"
#include "headers/GameManager.h"
#include "headers/Pipe.h"


int main() {
    Player player1("Flesh", "flash");
    player1.loadTexture();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    sf::View view(sf::FloatRect(200, 200, WIDTH * SCALING_W, HEIGHT * SCALING_H));
    window.setView(view);
    std::list<std::shared_ptr<Pipe>> pipes;
    for (int i = 0; i < 16; i++) {
        Pipe *pipe = new Pipe();
        pipe->move(WIDTH * SCALING_W + i * 600 + 1200, 800);
        std::shared_ptr<Pipe> pipePtr(pipe);
        pipes.emplace_back(pipePtr);
    }

    window.setFramerateLimit(60);
    World world(player1);
    for (auto &&pipe:pipes) {
        world.addObject(pipe);
    }
    world.loadTextures();

    while (window.isOpen()) {

        sf::Event event;
        window.clear(sf::Color::White);
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

        }

        if (!GameManager::getGameRunning() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            GameManager::startGame();
        view.move(MOVINGSPEEDX, 0);
        window.setView(view);
        world.tick();
        window.setActive();
        world.render(window);
        window.display();
    }
}


