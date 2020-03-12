//
// Created by samue on 12/03/2020.
//

#ifndef PROGETTO_ENTITY_H
#define PROGETTO_ENTITY_H


#include <SFML/Graphics.hpp>
#include "Struttura.h"

class Entity
{
public:
    Entity() {};
    ~Entity() {};

    virtual const Parameters* getParameters() const
    {
        return &parameters;
    };

private:
    static const Parameters parameters;

public:
    int posX = 0;
    int posY = 0;
};

#endif //PROGETTO_ENTITY_H
