//
// Created by Mouna Erraji on 07/03/2020.
//

#ifndef PROGETTO_ANIMATION_H
#define PROGETTO_ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(std::vector<sf::IntRect>& frames, sf::Sprite* sprite, const SpriteParameters* spriteParam, const float& animationTime = 1.f);
    ~Animation() {};

    void play();

    void setCurrentFrame(int currentframe)
    {
        Animation::currentFrame = currentFrame;
    }

    void checkTime();

    void restartClock() {
        elapsedTime += clock.restart();
    }

private:
    std::vector<sf::IntRect> frames;
    sf::Sprite* sprite;
    const SpriteParameters* spriteParam;

    int currentFrame;
    int frameCounter;

    sf::Clock clock;
    sf::Time elapsedTime;
    float frameTime;
};


#endif //PROGETTO_ANIMATION_H
