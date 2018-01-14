//
// Created by laci200270 on 2017.12.29..
//

#include <iostream>
#include "../headers/World.h"

World::World(Player player) : player(player) {
    this->player=player;
}
void World::render(sf::RenderWindow &window) {
    for (auto&& object : worldObjects)
        object->render(window);
    player.render(window);

}
void World::loadTextures()  {
    for (auto&& object : worldObjects)
        object->loadTexture();

}void World::tick()  {
    for (auto&& object : worldObjects) object->update();
    player.update(worldObjects);

}


void World::addObject(WorldObject* object) {

    worldObjects.emplace_back(object);
}
void World::addObject(std::shared_ptr<WorldObject> object) {

    worldObjects.emplace_back(object);
}
