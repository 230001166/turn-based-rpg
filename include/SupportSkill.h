#ifndef SUPPORTSKILL_H
#define SUPPORTSKILL_H

#include "Skill.h"

class SupportSkill : public Skill
{
    public:

        SupportSkill();
        virtual ~SupportSkill();

        std::string buffType = "Guard";

        virtual void use (Entity &attacker, Entity &defender);

        virtual std::string returnType ();

    protected:

    private:
};

#endif // SUPPORTSKILL_H
