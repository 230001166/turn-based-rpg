#ifndef GAME_H
#define GAME_H

#include "Skill.h"
#include "Renderer.h"
#include "tileMap.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void loop (Entity &player);

        void battle (Entity &player, Entity &opponent);

        Entity createEntityFromID (int entityID);

    protected:

    private:

        void displayEntityStats (Entity &target);

        void displayDetailedEntityStats (Entity &target);

        void displayEntityMoveset (Entity &target);

        void displayEntityHealthBar (Entity &target);

        bool playerCanMoveToTile (tileMap &tilemap, int xOffset, int yOffset);

        Renderer renderer;

        tileMap tilemap;

        int playerXPosition = 8;
        int playerYPosition = 8;
};

#endif // GAME_H
