//
// Created by Mouna Erraji on 07/03/2020.
//

#ifndef PROGETTO_ANIMATION_H
#define PROGETTO_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation() {};

    void update(int row, float deltaTime, bool faceRight);

public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

};


#endif //PROGETTO_ANIMATION_H
