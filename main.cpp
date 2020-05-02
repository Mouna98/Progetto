#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Progetto", sf::Style::Close | sf::Style::Titlebar);
    Entity player(206.0f, 206.0f);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        player.animate();

        window.clear();
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}
