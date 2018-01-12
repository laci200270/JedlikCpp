//
// Created by laci200270 on 2017.12.30..
//

#ifndef JEDLIKGAME_WORLDOBJECT_H
#define JEDLIKGAME_WORLDOBJECT_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

 class WorldObject {
public:
        virtual bool doesRectCollide(const Rect<float> &rectangle){};
        virtual Rect<float> getBoundingBox(){};
        virtual void update(){};
        virtual void loadTexture(){};
        virtual void render(RenderWindow &window){} ;
        virtual bool isSolidForPlayer(){ return true;};
        virtual bool isSolidForObject(WorldObject object){};
};


#endif //JEDLIKGAME_WORLDOBJECT_H
