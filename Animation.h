//
// Created by Mouna Erraji on 07/03/2020.
//

#ifndef PROGETTO_ANIMATION_H
#define PROGETTO_ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation() {};
    Animation(sf::Texture texture, int spriteWidth, int spriteHeight, float switchTime, int spriteCounter)
    {
        this->spriteCounter = spriteCounter;
        this->switchTime = switchTime;
        spriteRect = sf::IntRect(0, 0, spriteWidth, spriteHeight);
        sprite = sf::Sprite(texture, spriteRect);
    };

    ~Animation() {};

    void update()
    {
        sf::Clock clock;
        if (clock.getElapsedTime().asSeconds() > switchTime)
        {
            if (spriteRect.left == spriteCounter * spriteRect.width)
                spriteRect.left = 0;
            else
                spriteRect.left += spriteRect.width;

            sprite.setTextureRect(spriteRect);
        }
        clock.restart();
    };

public:
    float switchTime;
    int spriteCounter;

    sf::IntRect spriteRect;
    sf::Sprite sprite;
};


#endif //PROGETTO_ANIMATION_H
