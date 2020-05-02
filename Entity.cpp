//
// Created by samue on 12/03/2020.
//

#include "Entity.h"

#include "gameValues.h"

const SpriteParameters Entity::entityParameters("Files/Sprites/idle1.png", 128, 128);

Entity::Entity(const float& posX, const float& posY) : animationManager(&sprite, getParameters())
{
    setState(EntityState::IDLE);
    initializeSprite(posX, posY);
    setUpAnimations(getParameters());
}

void Entity::setUpAnimations(const SpriteParameters *parameters)
{
    animationManager = AnimationManager(&sprite, parameters);
    animationManager.createAnimation(EntityState::IDLE);
}

void Entity::animate()
{
    animationManager.play(state);
}

void Entity::loadTexture(const std::string& stringPath)
{
    if (!texture.loadFromFile(stringPath)) {
        std::cout << "Could not load texture from: " << stringPath << std::endl;
    }

    sprite = sf::Sprite(texture);
}

void Entity::initializeSprite(const float& posX, const float& posY)
{
    loadTexture(getParameters()->path);
    sprite.setTextureRect(sf::IntRect(0, 1, getParameters()->width, getParameters()->height));
    sprite.setOrigin(sprite.getTextureRect().width / 2., sprite.getTextureRect().height / 2.);
    sprite.setPosition(posX, posY);
}
