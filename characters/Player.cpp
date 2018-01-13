#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "../headers/Player.h"
#include "../headers/WorldUtils.h"

using  namespace sf;
using namespace std;


Player::Player(std::string name,std::string textName) {
    cout<<"Hello my name is "<<name<<endl;
    this->name=name;
    this->textName=textName;
    //this->setGameRunning(false);
}
void Player::loadTexture() {
    texture.loadFromFile("textures/"+textName+".png");
    sprite=Sprite(texture);
    sprite.scale(0.35f,0.35f);
    //sprite.setPosition(0,0);
}

void Player::setGameRunning(bool state) {
    isGameRunning=state;
}

bool Player::getGameRunning() const {
    std::cout << "Game is " << (isGameRunning ? "not" : "" ) << " running" << std::endl;
    return isGameRunning;
}

void Player::render(sf::RenderWindow &window) {
    window.draw(sprite);
    //cout<<"Render"<<endl;
}
void Player::update(list<std::shared_ptr<WorldObject>> &worldObjects) {
   /* if(Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::D)) {
        sprite.setPosition(sprite.getPosition().x + speed.x, sprite.getPosition().y);
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::A)){
        sprite.setPosition(sprite.getPosition().x-speed.x,sprite.getPosition().y);
    }*/
    if(Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Space)){

        speed.y=speed.y-3;

    }
    /*if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
        sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y+speed.y);
    }*/
    list<shared_ptr<WorldObject>> possibleTrips=WorldUtils::getObjectsUnderCoord(this->sprite.getGlobalBounds().top-this->sprite.getGlobalBounds().height,worldObjects);
    bool collide=false;
    if(possibleTrips.size()>0)
    for(auto it=possibleTrips.begin();it!=possibleTrips.end();++it){

       WorldObject* object=it->get();
        if(object->isSolidForPlayer()&&object->doesRectCollide(this->sprite.getGlobalBounds()))
            collide= true;
    }
    // collide=true;
    if(getGameRunning()) {
        if (!collide)
            speed.y = speed.y + 1;
        else {
            float damage = fabs(speed.y);
            speed.y = 0;
        }
    }
    this->sprite.setPosition(speed.x + sprite.getPosition().x, speed.y + sprite.getPosition().y);

}

