//
// Created by samue on 02/05/2020.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite* sprite, const SpriteParameters* parameters) : parameters(parameters), sprite(sprite) {};

void AnimationManager::createAnimation(const EntityState& state)
{
    std::vector<sf::IntRect> frames;

    switch (state)
    {
        case EntityState::IDLE:
            for (auto currentSprite = 0; currentSprite <= parameters->lastIdleCol; currentSprite++)
                frames.emplace_back(sf::IntRect(currentSprite * parameters->width, parameters->height, parameters->width, parameters->height));

            animations.emplace(EntityState::IDLE, Animation(frames, sprite, parameters, 1.0f));
            break;

        case EntityState::JUMPING:
            for (auto currentSprite = 0; currentSprite <= parameters->lastJumpCol; currentSprite++)
                frames.emplace_back(sf::IntRect(currentSprite * parameters->width, parameters->height, parameters->width, parameters->height));

            animations.emplace(EntityState::JUMPING, Animation(frames, sprite, parameters, 1.0f));
            break;

    }
}

void AnimationManager::checkAnimationState()
{
    for (auto& animation : animations) {
        animation.second.checkTime();
    }
}