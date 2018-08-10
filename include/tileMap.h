#ifndef TILEMAP_H
#define TILEMAP_H
#include <string>
#include <stdlib.h>

class tileMap
{

    public:

        tileMap() {

            for (int i = 0; i < TILEMAP_LENGTH * TILEMAP_LENGTH; i++) {

                int randomNumber = rand () % 99 + 1;

                if (randomNumber <= 15) {

                    tilemapArray [i] = 1;

                } else if (randomNumber <= 25) {

                    tilemapArray [i] = 2;

                } else {

                    tilemapArray [i] = 0;

                }

            }

        }

        virtual ~tileMap() {}

        const static int TILEMAP_LENGTH = 16;

        int tilemapArray [TILEMAP_LENGTH * TILEMAP_LENGTH];

        char tileCharacters [3] = {' ', '`', ';'};

    protected:
};

#endif // TILEMAP_H
