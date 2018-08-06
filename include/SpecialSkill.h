#ifndef SPECIALSKILL_H
#define SPECIALSKILL_H

#include "Skill.h"

class SpecialSkill : public Skill
{
    public:
        SpecialSkill();
        virtual ~SpecialSkill();

        virtual void use (Entity &attacker, Entity &defender);

        virtual std::string returnType ();

        std::string specialType = "Guard Break";

    protected:

    private:

        int returnPhysicalAttackDamage (Entity &attacker, Entity &defender);

};

#endif // SPECIALSKILL_H
