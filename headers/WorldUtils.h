//
// Created by laci200270 on 2017.12.31..
//

#ifndef JEDLIKGAME_WORLDUTILS_H
#define JEDLIKGAME_WORLDUTILS_H


#include <list>
#include "WorldObject.h"
#include "World.h"

using namespace std;

class WorldUtils { ;

public:
    static list<shared_ptr<WorldObject>>
    getObjectsUnderCoord(float height, list<std::shared_ptr<WorldObject>> &worldObjects);
};


#endif //JEDLIKGAME_WORLDUTILS_H
