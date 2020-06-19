#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Platform.h"

int main ()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Project", sf::Style::Close | sf::Style::Resize);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Files/Sprites/mage.png");

    Entity player(&playerTexture, sf::Vector2u(14, 2), 0.1f, 100.0f, 100);

    std::vector<Platform> platforms;
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.f), sf::Vector2f(500.0f, 500.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.f), sf::Vector2f(12.0f, 12.0f)));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;

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

        player.update(deltaTime);

        sf::Vector2f direction;
        for (Platform& platform : platforms)
        {
            if (platform.getCollider().checkCollision(player.getCollider(), direction, 1.0f))
                player.onCollision(direction);
        }

        window.clear();
        player.draw(window);
        for (Platform& platform : platforms)
            platform.draw(window);
        window.display();
    }

    return 0;
}
