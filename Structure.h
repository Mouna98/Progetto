//
// Created by samue on 12/03/2020.
//

#ifndef PROGETTO_STRUCTURE_H
#define PROGETTO_STRUCTURE_H


#include <SFML/Graphics.hpp>

struct Parameters
{
    int spriteWidth;
    int spriteHeight;
    int spriteCounter;
    float switchTime;
    sf::Texture texture;

    Parameters() {};
    Parameters(int spriteWidth, int spriteHeight, int spriteCounter, float switchTime, std::string imgDirectory)
    {
        this->spriteWidth = spriteWidth;
        this->spriteHeight = spriteHeight;
        this->spriteCounter = spriteCounter;
        this->switchTime = switchTime;
        texture.loadFromFile(imgDirectory);
    };

    ~Parameters() {};
};


#endif //PROGETTO_STRUCTURE_H
