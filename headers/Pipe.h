//
// Created by laci200270 on 2018.01.13..
//

#ifndef JEDLIKGAME_PIPE_H
#define JEDLIKGAME_PIPE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "WorldObject.h"

class Pipe : public WorldObject {
protected:
    int size;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    void update() override;

    void loadTexture() override;

    void render(sf::RenderWindow &window) override;

    bool doesRectCollide(const sf::Rect<float> &rectangle);

    sf::Rect<float> getBoundingBox() override;

    void move(sf::Vector2f &coords) override;

    void move(float x, float y) override;

    void flip();
};


#endif //JEDLIKGAME_PIPE_H
