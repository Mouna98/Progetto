#include <iostream>

/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "unit_test/lib/GameCharacter.h"
#include "unit_test/Animation.h"


int main() {
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width/2)-755, (sf::VideoMode::getDesktopMode().height/2)-390);

    window.create(sf::VideoMode(1500, 700), "SFML", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

   GameCharacter myGameCharacter("GameCharacter.png");

    auto pTexture;
    Animation animation(&pTexture, sf::Vector2u(1, 6), 0.3f );

   float deltaTime= 0.0f;
   sf::Clock clock;


    //Main Loop:
    while(window.isOpen()){

        deltaTime = clock.restart().asSeconds();

        sf::Event Event;

        //Event Loop:
        while(window.pollEvent(Event)){
            switch(Event.type){

                case sf::Event::Closed:
                    window.close();
                default:
                    break;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                myGameCharacter.moveGameCharacter('u', 6.0);
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                myGameCharacter.moveGameCharacter('d', 6.0);
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                myGameCharacter.moveGameCharacter('l', 6.0);
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                myGameCharacter.moveGameCharacter('r', 6.0);
            }

        }

        animation.Update(0, deltaTime);
        //myGameCharacter.setTextureRect(animation.uvRect);

        window.clear();
        myGameCharacter.drawGameCharacter(window);
        window.display();
    }
}

