//
// Created by Mouna Erraji on 07/03/2020.
//

#include "Animation.h"

Animation::Animation(std::vector<sf::IntRect>& frames, sf::Sprite* sprite, const SpriteParameters* spriteParam, const float& animationTime) :
        frames(frames), sprite(sprite), spriteParam(spriteParam), currentFrame(0)
{
    frameCounter = -1;

    for (const auto &framIterator : frames)
    {
        frameCounter++;
    }

    frameTime = animationTime / frameCounter;
}

void Animation::play()
{
    if (elapsedTime.asSeconds() >= frameTime)
    {
        sprite->setTextureRect(frames[currentFrame]);
        currentFrame++;

        if (currentFrame >= frameCounter)
            currentFrame = 0;
    }

    elapsedTime -= sf::seconds(frameTime);
}

void Animation::checkTime()
{
    if (elapsedTime.asSeconds() >= frameTime)
        elapsedTime -= sf::seconds(frameTime);

    restartClock();
}