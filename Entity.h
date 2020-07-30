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
    Entity(std::string texturePath, sf::Vector2u imageCount, sf::Vector2f position, float switchTime, float speed, float jumpHeight);
    ~Entity() {};

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void onCollision(sf::Vector2f direction);
    void loadTexture(std::string path);

    Collider getCollider()
    {
        return Collider(body);
    }

private:
    sf::RectangleShape body;
    Animation animation;
    sf::Texture texture;
    unsigned int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
};

#endif //PROGETTO_ENTITY_H
