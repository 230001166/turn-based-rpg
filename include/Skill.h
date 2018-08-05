#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Entity.h"

class Skill
{

public:

    Skill () { };

    std::string Name = "Light Attack";

    int HealthCost = 0;

    int StaminaCost = 1;

    int ManaCost = 0;

    double PowerMultipler = 1.0;

    virtual void use (Entity &attacker, Entity &defender) {

        int randomNumber = rand () % 99 + 1;

        attacker.Stamina -= this->StaminaCost;

        if (randomNumber <= defender.Evasion) {

            std::cout << attacker.name << "'s attack missed!" << std::endl;

        } else {

            int attackValue = attacker.Strength * (double) attacker.Stamina / attacker.MaxStamina;
            int defenseValue = defender.Defense * (double) defender.Stamina / defender.MaxStamina;

            int damage = 0;

            if (attackValue - defenseValue + 1 > 0) {

                damage = (attackValue - defenseValue + 1) * (attackValue - defenseValue + 1) * this->PowerMultipler;

                if (defender.isGuarding) {

                    damage *= 0.5;

                }

            } else {

                damage = 1;

            }

            std::cout << attacker.name << " dealt " << damage << " damage to " << defender.name << "!" << std::endl;

            defender.Health -= damage;

        }
        // damage

    }

    virtual std::string returnType () { return "PHYSICAL"; }

};

#endif // SKILL_H
