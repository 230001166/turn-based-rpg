#include "ChargeSkill.h"
#include "SupportSkill.h"
#include "RecoverySkill.h"
#include "SpecialSkill.h"
#include "Game.h"

#include <iostream>

using namespace std;

Game game;

int main()
{

    srand (time (NULL));

    Entity player; Entity test; player.name = "Dinke"; test = game.createEntityFromID (1);

    Skill tempSkill;

    Skill *light_attack = &tempSkill;

    light_attack->Name = "Light Attack";
    light_attack->StaminaCost = 1;

    test.moveset.push_back (light_attack);

    ChargeSkill tempSkill2 (1); tempSkill2.Name = "Pounce"; tempSkill2.StaminaCost = 3;

    Skill *pounce = &tempSkill2;

    RecoverySkill rest; rest.StaminaRecovery = 3; rest.Name = "Rest";

    Skill *recovery_rest = &rest;

    test.moveset.push_back (recovery_rest);

    SupportSkill guard; guard.StaminaCost = 2; guard.Name = "Guard";

    Skill *support_guard = &guard;

    SpecialSkill gBreak; gBreak.StaminaCost = 4; gBreak.Name = "Guard Break";

    Skill *guard_break = &gBreak;

    player.moveset.push_back (light_attack);
    player.moveset.push_back (pounce);
    player.moveset.push_back (recovery_rest);
    player.moveset.push_back (support_guard);
    player.moveset.push_back (guard_break);

    game.loop (player);

    std::cin.get ();

    return 0;

}
