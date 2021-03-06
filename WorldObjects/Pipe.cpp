//
// Created by laci200270 on 2017.12.30..
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../headers/Pipe.h"
#include "../headers/configs.h"

void Pipe::update() {

}

void Pipe::loadTexture() {
    texture = sf::Texture();
    texture.loadFromFile("textures/pipe.png");
    sprite = sf::Sprite(texture);
#if DBG_TEXTURES == 1
    std::cout<<"Pipe texture loaded"<<std::endl;
#endif


}

void Pipe::render(sf::RenderWindow &window) {
#if DBG_USELESS_RENDER_LOGS
    std::cout<<"Rendering"<<std::endl;
    std::cout << "a pipe at " << sprite.getPosition().x <<" ; "<<sprite.getPosition().y<<std::endl;
#endif
#if DBG_BOUNDING_BOX==1
    sf::FloatRect floatRect=sprite.getGlobalBounds();
    sf::RectangleShape rectangleShape(sf::Vector2f(floatRect.width,floatRect.height));
    rectangleShape.move(floatRect.left,floatRect.top);
    rectangleShape.setFillColor(sf::Color::Transparent);
    rectangleShape.setOutlineColor(sf::Color::Red);
    rectangleShape.setOutlineThickness(15);
    window.draw(rectangleShape);
#endif
    window.draw(sprite);
}

bool Pipe::doesRectCollide(const sf::Rect<float> &rectangle) {
    //return true;
    return sprite.getGlobalBounds().intersects(rectangle);

}

sf::Rect<float> Pipe::getBoundingBox() {
    return sprite.getGlobalBounds();
}

void Pipe::move(sf::Vector2f &coords) {
    move(coords.x, coords.y);
}

void Pipe::move(float x, float y) {
#if DBG_USELESS_MOVING_LOGS==1
    std::cout << "Moving a pipe to" << x <<" ; "<<y<<std::endl;
#endif
    sprite.setPosition(x, y);
}

void Pipe::flip(){
    sprite.rotate(180);
}