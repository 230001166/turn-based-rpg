#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Skill;

struct Entity
{

    std::string name;

    int Health = 17;
    int MaxHealth = 17;

    int Stamina = 10;
    int MaxStamina = 10;

    int Mana = 0;
    int MaxMana = 0;

    int Level = 1;
    int Experience = 0;

    int Strength = 3;

    int Defense = 2;

    int Agility = 1;

    int Intelligence = 2;

    int Willpower;

    int Evasion = 10;

    std::vector <Skill* > moveset;

};

#endif // ENTITY_H
