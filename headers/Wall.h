//
// Created by laci200270 on 2017.12.30..
//

#ifndef JEDLIKGAME_WALL_H
#define JEDLIKGAME_WALL_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "WorldObject.h"

class Wall : public WorldObject {
protected: int size;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    void update() override ;
    void loadTexture() override ;
    void render(sf::RenderWindow &window) override ;
    bool doesRectCollide(const sf::Rect<float> &rectangle)  ;
    sf::Rect<float> getBoundingBox() override ;
    void move(sf::Vector2f coords) override ;
    void move(float x,float y) override ;
};


#endif //JEDLIKGAME_WALL_H
