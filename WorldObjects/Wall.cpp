//
// Created by laci200270 on 2017.12.30..
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "../headers/Wall.h"

using namespace std;

void Wall::update() {

}
void Wall::loadTexture() {
    texture=Texture();
    texture.loadFromFile("textures/wall.gif");
    sprite=Sprite(texture);
    cout<<"Wall texture loaded"<<endl;
    //sprite.scale(0.1ff);
    sprite.setPosition(2,2);
}
 void Wall::render(RenderWindow &window) {
   // cout<<"Render"<<endl;
    window.draw(sprite);
}

bool Wall::doesRectCollide(const Rect<float> &rectangle) {
   // return false;
    return sprite.getLocalBounds().intersects(rectangle);

}
Rect<float> Wall::getBoundingBox() {
    return sprite.getGlobalBounds();
}