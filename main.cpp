#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameCharacter.h"
#include "Animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Progetto", sf::Style::Close | sf::Style::Titlebar);

    /* sf::Texture pTexture;
    pTexture.loadFromFile("Files/GameCharacterIdle.png");

    sf::IntRect rectSourceSprite(0, 0, 128, 128);
    sf::Sprite sprite(pTexture, rectSourceSprite); */

    GameCharacter player;
    Animation playerAnimation(player.getParameters()->texture, player.getParameters()->spriteWidth, player.getParameters()->spriteHeight,
                              player.getParameters()->switchTime, player.getParameters()->spriteCounter);

    // sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        playerAnimation.update();
        /* if (clock.getElapsedTime().asSeconds() > 0.2)
        {
            if (rectSourceSprite.left == 1664)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 128;

            sprite.setTextureRect(rectSourceSprite);
            //playerAnimation.update();
            clock.restart();
        } */

        window.clear();
        window.draw(playerAnimation.sprite);
        //window.draw(sprite);
        window.display();
    }

    return 0;
}
