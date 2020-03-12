//
// Created by Mouna Erraji on 06/03/2020.
//

#include "GameCharacter.h"

const Parameters GameCharacter::gameCharacterParameters(128, 128, 14, 0.2f, "Files/GameCharacterIdle.png");

const Parameters* GameCharacter::getParameters() const
{
    return &gameCharacterParameters;
}
