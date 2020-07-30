//
// Created by samue on 12/03/2020.
//

#include "Entity.h"

Entity::Entity(std::string texturePath, sf::Vector2u imageCount, sf::Vector2f position, float switchTime, float speed, float jumpHeight) : animation(texturePath, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    loadTexture(texturePath);
    body.setSize(sf::Vector2f(57.0f, 55.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position.x, position.y);
    body.setTexture(&texture);
}

void Entity::update(float deltaTime)
{
    velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
    }

    velocity.y += 981.0f * deltaTime;

    if (velocity.x == 0)
        row = 0;
    else
    {
        row = 1;

        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Entity::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Entity::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //collision on the left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //collision on the right
        velocity.x = 0.0f;
    }

    if (direction.y < 0.0f)
    {
        //collision on the bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        //collision on the top
        velocity.y = 0.0f;
    }
}

void Entity::loadTexture(std::string path)
{
    texture.loadFromFile(path);
}