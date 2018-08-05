#ifndef RECOVERYSKILL_H
#define RECOVERYSKILL_H

#include "Skill.h"

class RecoverySkill : public Skill
{
    public:

        RecoverySkill();

        virtual void use (Entity &attacker, Entity &defender);

        virtual std::string returnType ();

        int HealthRecovery = 0;

        int StaminaRecovery = 0;

        int ManaRecovery = 0;

    protected:

    private:

        void limitInteger (int &number, int limit);
};

#endif // RECOVERYSKILL_H
