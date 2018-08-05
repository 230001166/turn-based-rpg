#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Skill;

struct Entity
{

    std::string name;

    int Health = 23;
    int MaxHealth = 23;

    int Stamina = 10;
    int MaxStamina = 10;

    int Mana = 0;
    int MaxMana = 0;

    int Level = 1;
    int Experience = 2;

    int Strength = 3;

    int Defense = 0;

    int Agility = 1;

    int Intelligence = 2;

    int Willpower;

    int Evasion = 10;

    std::vector <Skill* > moveset;



    bool isGuarding = false;

};

#endif // ENTITY_H
