#ifndef CHARGESKILL_H
#define CHARGESKILL_H

#include "Skill.h"

class ChargeSkill : public Skill
{
    public:
        ChargeSkill ();

        ChargeSkill (int chargeTurns);

        virtual void use (Entity &attacker, Entity &defender);

        virtual std::string returnType ();

    protected:

    private:

        int turnsToCharge = 1;

        int turnsSpentCharging = 0;
};

#endif // CHARGESKILL_H
