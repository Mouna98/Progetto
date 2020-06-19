//
// Created by samue on 19/06/2020.
//

#ifndef PROGETTO_PLATFORM_H
#define PROGETTO_PLATFORM_H


#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform
{
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform() {};

    void draw(sf::RenderWindow& window);

    Collider getCollider()
    {
        return Collider(body);
    }

private:
    sf::RectangleShape body;
};


#endif //PROGETTO_PLATFORM_H
