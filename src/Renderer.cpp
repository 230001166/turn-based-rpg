#include "Renderer.h"
#include <iostream>

Renderer::Renderer()
{
    //ctor
}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::render (tileMap tilemap, Entity player, int playerX, int playerY) {

    for (int i = 0; i < tilemap.TILEMAP_LENGTH; i++) {

        for (int j = 0; j < tilemap.TILEMAP_LENGTH; j++) {

            if (playerX == j && playerY == i) {

                std::cout << "@";

            } else {

                std::cout << tilemap.tileCharacters [tilemap.tilemapArray [j + tilemap.TILEMAP_LENGTH * i]];

            }

        }

        std::cout << "\n";

    }

    std::cout << "XP  [";

    double barsToFill = (double) player.Experience / ((double)(player.Level * player.Level * player.Level) + (player.Level * player.Level * 6)) * 10;

    for (int i = 0; i < barsToFill; i++) {

        std::cout << "=";

    }

    for (int i = 0; i < 10-barsToFill; i++) {

        std::cout << " ";

    }

    std::cout << "]\n" << std::endl;

}
