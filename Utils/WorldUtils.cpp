//
// Created by laci200270 on 2017.12.31..
//

#include "../headers/WorldUtils.h"

list<shared_ptr<WorldObject>>
WorldUtils::getObjectsUnderCoord(float height, list<std::shared_ptr<WorldObject>> &objects) {

    list<shared_ptr<WorldObject>> returnableObjects = list<shared_ptr<WorldObject>>();
    for (auto &&it = objects.begin(); it != objects.end(); ++it) {
        WorldObject *object = it->get();
        if (object->getBoundingBox().top < height)
            returnableObjects.push_back(*it);

    }
    return returnableObjects;
}