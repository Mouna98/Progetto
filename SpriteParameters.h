//
// Created by samue on 12/03/2020.
//

#ifndef PROGETTO_SPRITEPARAMETERS_H
#define PROGETTO_SPRITEPARAMETERS_H


#include <SFML/Graphics.hpp>

#include <iostream>

struct SpriteParameters
{
public:
    SpriteParameters(const std::string &path, const int& width, const int& height, const int& lastIdleCol = 0, const int& lastJumpCol = 0) : path(path),
                                                                                                                                             width(width), height(height), lastIdleCol(lastIdleCol), lastJumpCol(lastJumpCol) {};

    const std::string path;

    // sprite height and width and rows
    const int width;
    const int height;

    // values used to choose the right column in the spritesheet
    const int lastIdleCol;
    const int lastJumpCol;
};


#endif //PROGETTO_SPRITEPARAMETERS_H
