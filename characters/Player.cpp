#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "../headers/Player.h"
#include "../headers/WorldUtils.h"
#include "../headers/GameManager.h"
#include "../headers/configs.h"

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
    sprite.scale(5,5);
    sprite.setPosition(WIDTH*SCALING_W/2,HEIGHT*SCALING_H/2);

}


void Player::render(sf::RenderWindow &window) {
    window.draw(sprite);
    FloatRect floatRect=sprite.getGlobalBounds();
    RectangleShape rectangleShape(Vector2f(floatRect.width,floatRect.height));
    rectangleShape.move(floatRect.left,floatRect.top);
    rectangleShape.setFillColor(Color::Transparent);
    rectangleShape.setOutlineColor(Color::Red);
    rectangleShape.setOutlineThickness(15);
    window.draw(rectangleShape);

}
void Player::update(list<std::shared_ptr<WorldObject>> &worldObjects) {


        if(Keyboard::isKeyPressed(Keyboard::Space)){
            if(!lastTimePressed)
                speed.y=speed.y-15;
            lastTimePressed=true;
        }
        else
            lastTimePressed=false;


    list<shared_ptr<WorldObject>> possibleTrips=WorldUtils::getObjectsUnderCoord(this->sprite.getGlobalBounds().top-this->sprite.getGlobalBounds().height,worldObjects);
    bool collide=false;
    if(possibleTrips.size()>0)
    for(auto it=possibleTrips.begin();it!=possibleTrips.end();++it){

       WorldObject* object=it->get();
        if(object->isSolidForPlayer()&&object->doesRectCollide(this->sprite.getGlobalBounds()))
            collide= true;
    }
    // collide=true;
    speed.x=MOVINGSPEEDX;
    if(GameManager::getGameRunning()) {
        if (!collide)
            speed.y = speed.y + 0.25f;
        else {
            float damage = fabs(speed.y);
            speed.y = 0;
        }
    }
    this->sprite.setPosition(speed.x + sprite.getPosition().x, speed.y + sprite.getPosition().y);

}

