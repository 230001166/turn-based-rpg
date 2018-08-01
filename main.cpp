#include "ChargeSkill.h"
#include "Entity.h"

#include <iostream>

using namespace std;

int main()
{

    srand (time (NULL));

    Entity player; Entity test; player.name = "Dinke"; player.Strength = 4; test.name = "Juju";
    Skill light_attacke;
    Skill *light_attack = &light_attacke;
    ChargeSkill charge_attacke (1); charge_attacke.Name = "Pounce";
    Skill *charge_attack = &charge_attacke;

    player.moveset.push_back (light_attack); test.moveset.push_back (light_attack);
    player.moveset.push_back (charge_attack);

    while (player.Health > 0 && test.Health > 0) {

        std::cout << player.Health << " vs. " << test.Health << std::endl;
        std::cout << player.Stamina << " vs. " << test.Stamina << std::endl;

        for (int i = 0; i < player.moveset.size (); i++ ) {


            std::cout << "[" << i << "] - " << player.moveset [i]->Name << " " << player.moveset [i]->returnType () << std::endl;

            player.moveset [i]->use (player, test);

            test.moveset [0]->use (test, player);

        }

        char oof;
        std::cin >> oof;

    }

    return 0;

}
