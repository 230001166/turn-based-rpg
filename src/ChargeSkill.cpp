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

            int attackValue = (attacker.Strength * (attacker.Stamina / attacker.MaxStamina) * 1.5);
            int defenseValue = (defender.Defense * (defender.Stamina / defender.MaxStamina));

            int damage = 0;

            if (attackValue - defenseValue + 1 > 0) {

                damage = (attackValue - defenseValue + 1) * (attackValue - defenseValue + 1) * this->PowerMultipler;

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

    std::cout << this->turnsToCharge << std::endl;

}

std::string ChargeSkill::returnType () {

    return "CHARGE";

}
