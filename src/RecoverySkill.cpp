#include "RecoverySkill.h"

RecoverySkill::RecoverySkill()
{
    //ctor
}

void RecoverySkill::use (Entity &attacker, Entity &defender) {

    defender.Health += this->HealthRecovery; limitInteger (defender.Health, defender.MaxHealth);

    defender.Stamina += this->StaminaRecovery; limitInteger (defender.Stamina, defender.MaxStamina);

    defender.Mana += this->StaminaRecovery; limitInteger (defender.Mana, defender.MaxMana);

}

void RecoverySkill::limitInteger (int &number, int limit) {

    if (number > limit) {

        number = limit;

    }

}

std::string RecoverySkill::returnType () {

    return "RECOVERY";

}
