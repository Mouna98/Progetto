//
// Created by Mouna Erraji on 06/03/2020.
//

#ifndef PROGETTO_GAMECHARACTER_H
#define PROGETTO_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>


class GameCharacter {
    GameCharacter(){
        //Default
    }

public:
    GameCharacter(std::string imgDirectory){
        if(!pTexture.loadFromFile(imgDirectory)){
            std::cerr << "Error\n";
        }
        pSprite.setTexture(pTexture);
    }

    void moveGameCharacter(char direction, float moveSpeed){
        if(direction == 'u'){
            pSprite.move(0, -moveSpeed);
        }else if(direction == 'd'){
            pSprite.move(0, moveSpeed);
        }else if(direction == 'l'){
            pSprite.move(-moveSpeed, 0);
        }else if(direction == 'r'){
            pSprite.move(moveSpeed, 0);
        }
    }

    void drawGameCharacter(sf::RenderWindow &window){
        window.draw(pSprite);
    }

private:
    sf::Texture pTexture;
    sf::Sprite pSprite;
};





#endif //PROGETTO_GAMECHARACTER_H
