//
// Created by samue on 02/05/2020.
//

#ifndef PROGETTO_ANIMATIONMANAGER_H
#define PROGETTO_ANIMATIONMANAGER_H


#include <SFML/Graphics.hpp>
#include <map>
#include "SpriteParameters.h"
#include "gameValues.h"
#include "Animation.h"

class AnimationManager
{
public:
    AnimationManager(sf::Sprite* sprite, const SpriteParameters* parameters);
    ~AnimationManager() {};

    void createAnimation(const EntityState& state);

    void play(const EntityState& state)
    {
        animations.find(state)->second.play();
    };

    void resetAnimation(const EntityState& state) {
        animations.find(state)->second.setCurrentFrame(0);
    };

    void checkAnimationState();

private:
    std::map<EntityState, Animation> animations;
    const SpriteParameters* parameters;
    sf::Sprite* sprite;
};


#endif //PROGETTO_ANIMATIONMANAGER_H
