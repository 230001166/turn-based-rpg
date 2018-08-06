#include "SpecialSkill.h"

SpecialSkill::SpecialSkill()
{
    //ctor
}

SpecialSkill::~SpecialSkill()
{
    //dtor
}

void SpecialSkill::use (Entity &attacker, Entity &defender) {

    attacker.Stamina -= this->StaminaCost;

    if (specialType == "Guard Break") {

        int randomNumber = rand () % 99 + 1;

        attacker.Stamina -= this->StaminaCost;

        int damage = returnPhysicalAttackDamage (attacker, defender);

        if (defender.isGuarding) { damage *= 5; }

        if (randomNumber <= defender.Evasion) {

            std::cout << attacker.name << "'s attack missed!" << std::endl;

        } else {

            std::cout << attacker.name << " used Guard Break!!" << std::endl;

            std::cout << attacker.name << " dealt " << damage << " damage to " << defender.name << "!" << std::endl;

            defender.Health -= damage;

        }


    }

}

int SpecialSkill::returnPhysicalAttackDamage (Entity &attacker, Entity &defender) {

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

    return damage;

}

std::string SpecialSkill::returnType () {

    return "SPECIAL";

}
