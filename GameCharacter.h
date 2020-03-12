//
// Created by Mouna Erraji on 06/03/2020.
//

#ifndef PROGETTO_GAMECHARACTER_H
#define PROGETTO_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class GameCharacter : public Entity
{
public:
    GameCharacter() {};
    ~GameCharacter() {};
    /* void moveGameCharacter(char direction, float moveSpeed)
    {
        if (direction == 'u') {
            sprite.move(0, -moveSpeed);
        }
        else if (direction == 'd') {
            sprite.move(0, moveSpeed);
        }
        else if (direction == 'l') {
            sprite.move(-moveSpeed, 0);
        }
        else if (direction == 'r') {
            sprite.move(moveSpeed, 0);
        }
    } */

    /* void drawGameCharacter(sf::RenderWindow& window)
    {
        window.draw(sprite);
    } */

    const Parameters* getParameters() const override;

private:
    static const Parameters gameCharacterParameters;
};





#endif //PROGETTO_GAMECHARACTER_H
