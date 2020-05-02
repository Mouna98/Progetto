//
// Created by samue on 12/03/2020.
//

#ifndef PROGETTO_ENTITY_H
#define PROGETTO_ENTITY_H


#include <SFML/Graphics.hpp>
#include "SpriteParameters.h"
#include "gameValues.h"
#include "AnimationManager.h"

class Entity
{
public:
    Entity(const float& posX, const float& posY);
    ~Entity() {};

    void setUpAnimations(const SpriteParameters *parameters);

    void animate();

    void setState(EntityState state) {
        Entity::state = state;
    }

    const SpriteParameters* getParameters() const {
        return &entityParameters;
    }

    const sf::Sprite& getSprite() const {
        return sprite;
    }

private:
    void loadTexture(const std::string& stringPath);

    void initializeSprite(const float& posX, const float& posY);

private:
    sf::Texture texture;
    sf::Sprite sprite;

    EntityState state;

    static const SpriteParameters entityParameters;

    AnimationManager animationManager;
};

#endif //PROGETTO_ENTITY_H
