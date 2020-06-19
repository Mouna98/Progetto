//
// Created by samue on 19/06/2020.
//

#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setTexture(texture);
    body.setPosition(position);

}

void Platform::draw(sf::RenderWindow& window)
{
    window.draw(body);
}
