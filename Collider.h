//
// Created by samue on 19/06/2020.
//

#ifndef PROGETTO_COLLIDER_H
#define PROGETTO_COLLIDER_H


#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider(sf::RectangleShape& body) : body(body) {};
    ~Collider() {};

public:
    bool checkCollision(Collider other, sf::Vector2f& direction, float push);

    sf::Vector2f getPosition()
    {
        return body.getPosition();
    }

    sf::Vector2f getHalfSize()
    {
        return body.getSize() / 2.0f;
    }

    void move(float dx, float dy)
    {
        body.move(dx, dy);
    }

private:
    sf::RectangleShape& body;
};


#endif //PROGETTO_COLLIDER_H
