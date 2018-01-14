//
// Created by laci200270 on 2017.12.30..
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "../headers/Wall.h"


void Wall::update() {

}
void Wall::loadTexture() {
    texture=sf::Texture();
    texture.loadFromFile("textures/wall.gif");
    sprite=sf::Sprite(texture);
    std::cout<<"Wall texture loaded"<<std::endl;
    //sprite.scale(0.1ff);
    sprite.setPosition(400,700);

}
 void Wall::render(sf::RenderWindow &window) {
   // cout<<"Render"<<endl;
    window.draw(sprite);
}

bool Wall::doesRectCollide(const sf::Rect<float> &rectangle) {
   //return true;
    return sprite.getGlobalBounds().intersects(rectangle);

}
sf::Rect<float> Wall::getBoundingBox() {
    return sprite.getGlobalBounds();
}
void Wall::move(sf::Vector2f coords) {

}
void Wall::move(float x, float y) {

}
