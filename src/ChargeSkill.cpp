#include "ChargeSkill.h"

ChargeSkill::ChargeSkill()
{
    //ctor
}

ChargeSkill::ChargeSkill (int chargeTurns)
{

    this->turnsToCharge = chargeTurns;

}

void ChargeSkill::use (Entity &attacker, Entity &defender) {

    if (this->turnsSpentCharging == this->turnsToCharge) {

        int randomNumber = rand () % 99 + 1;

        attacker.Stamina -= this->StaminaCost;

        if (randomNumber <= defender.Evasion) {

            std::cout << attacker.name << "'s attack missed!" << std::endl;

        } else {

            int attackValue = attacker.Strength * (double) attacker.Stamina / attacker.MaxStamina;
            int defenseValue = defender.Defense * (double) defender.Stamina / defender.MaxStamina;

            int damage = 0;

            if (attackValue - defenseValue + 2 > 0) {

                damage = (attackValue - defenseValue + 2) * (attackValue - defenseValue + 2) * this->PowerMultipler;

                if (defender.isGuarding) {

                    damage *= 0.5;

                }

            } else {

                damage = 1;

            }

            std::cout << attacker.name << " dealt " << damage << " damage to " << defender.name << "!" << std::endl;

            defender.Health -= damage;

        }

        turnsSpentCharging = 0;

    } else {

        turnsSpentCharging ++;
        std::cout << attacker.name << " is charging up for an attack!" << std::endl;

    }

}

std::string ChargeSkill::returnType () {

    return "CHARGE";

}
