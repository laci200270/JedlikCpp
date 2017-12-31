#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include "headers/World.h"
#include "headers/Wall.h"

using namespace sf;
using namespace std;
int main() {
    Player player1("Steve","dickbutt");
    player1.loadTexture();
    sf::RenderWindow window(sf::VideoMode(1200, 700), "SFML window");
    window.setFramerateLimit(60);
    World world(player1);
    Wall* wall=new Wall();
    world.addObject(wall);
    world.loadTextures();
    while (window.isOpen())
    {

        sf::Event event;
        window.clear(Color::White);
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

        }
        world.tick();
        window.setActive();
        world.render(window);
        //wall.render(window);
        window.display();
    }
}


