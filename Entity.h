//
// Created by samue on 12/03/2020.
//

#ifndef PROGETTO_ENTITY_H
#define PROGETTO_ENTITY_H


#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Collider.h"

class Entity
{
public:
    Entity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeght);
    ~Entity() {};

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void onCollision(sf::Vector2f direction);

    Collider getCollider()
    {
        return Collider(body);
    }

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
};

#endif //PROGETTO_ENTITY_H
