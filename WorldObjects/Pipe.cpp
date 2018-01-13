//
// Created by laci200270 on 2017.12.30..
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "../headers/Pipe.h"


void Pipe::update() {

}
void Pipe::loadTexture() {
    texture=sf::Texture();
    texture.loadFromFile("textures/pipe.png");
    sprite=sf::Sprite(texture);
    std::cout<<"Pipe texture loaded"<<std::endl;
    //sprite.scale(0.1ff);
    sprite.setPosition(400,700);

}
void Pipe::render(sf::RenderWindow &window) {
    // cout<<"Render"<<endl;
    window.draw(sprite);
}

bool Pipe::doesRectCollide(const sf::Rect<float> &rectangle) {
    //return true;
    return sprite.getGlobalBounds().intersects(rectangle);

}
sf::Rect<float> Pipe::getBoundingBox() {
    return sprite.getGlobalBounds();
}//
// Created by laci200270 on 2018.01.13..
//

#include "../headers/Pipe.h"
