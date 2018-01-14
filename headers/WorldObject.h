//
// Created by laci200270 on 2017.12.30..
//

#ifndef JEDLIKGAME_WORLDOBJECT_H
#define JEDLIKGAME_WORLDOBJECT_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class WorldObject {
public:
    virtual bool doesRectCollide(const sf::Rect<float> &rectangle) {};

    virtual sf::Rect<float> getBoundingBox() {};

    virtual void update() {};

    virtual void loadTexture() {};

    virtual void render(sf::RenderWindow &window) {};

    virtual bool isSolidForPlayer() { return true; };

    virtual bool isSolidForObject(WorldObject object) {};

    virtual void move(sf::Vector2f &coords) {};

    virtual void move(float x, float y) {};
};


#endif //JEDLIKGAME_WORLDOBJECT_H
