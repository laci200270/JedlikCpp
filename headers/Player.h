//
// Created by laci200270 on 2017.12.28..
//

#ifndef JEDLIKGAME_PLAYER_H
#define JEDLIKGAME_PLAYER_H
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <asio/detail/shared_ptr.hpp>
#include "WorldObject.h"

using namespace std;
class Player {
     std::string name;
     std::string textName;
     sf::Texture texture;
     sf::Sprite sprite;
     bool isGameRunning=false;
 public:
     Player(std::string name,std::string textName);
     void update(list<shared_ptr<WorldObject>> &objects);
     void loadTexture();
     void render(sf::RenderWindow &window);
     Vector2f speed =Vector2<float >();
     void setGameRunning(bool state);
     bool getGameRunning() const;

};


#endif //JEDLIKGAME_PLAYER_H
