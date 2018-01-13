//
// Created by laci200270 on 2017.12.29..
//

#ifndef JEDLIKGAME_WORLD_H
#define JEDLIKGAME_WORLD_H


#include "Player.h"
#include "WorldObject.h"
#include <list>
#include <memory>
class World {
    std::list<std::shared_ptr<WorldObject>> worldObjects;
public:
    Player player;
    World(Player player);
    void render(sf::RenderWindow &window);
    void tick();
    void loadTextures();
    void addObject(WorldObject* object);
};


#endif //JEDLIKGAME_WORLD_H
