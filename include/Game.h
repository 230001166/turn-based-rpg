#ifndef GAME_H
#define GAME_H

#include "Skill.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void battle (Entity &player, Entity &opponent);

        Entity createEntityFromID (int entityID);

    protected:

    private:

        void displayEntityStats (Entity &target);

        void displayEntityMoveset (Entity &target);
};

#endif // GAME_H
