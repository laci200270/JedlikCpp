#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include "headers/World.h"
#include "headers/Wall.h"
#include "configs.h"

using namespace sf;
using namespace std;
static int tombBenKeres(int tomb[], int mit){
    for(int i=0;i<sizeof(tomb);i++){
        if(mit==tomb[i])
            return i;
    }
}
int main() {
    Player player1("Steve","dickbutt");
    player1.loadTexture();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    View view(FloatRect(200,200,WIDTH*SCALING_W,HEIGHT*SCALING_H));

    window.setView(view);
    window.setFramerateLimit(60);
    World world(player1);
    Wall* wall=new Wall();
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
        if(!player1.getGameRunning()&&Keyboard::isKeyPressed(Keyboard::Space))
            player1.setGameRunning(true);
        world.tick();
        window.setActive();
        world.render(window);
        //wall.render(window);
        window.display();
    }
}


