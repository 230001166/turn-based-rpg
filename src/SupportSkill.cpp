#include "SupportSkill.h"

SupportSkill::SupportSkill()
{
    //ctor
}

SupportSkill::~SupportSkill()
{
    //dtor
}

void SupportSkill::use (Entity &attacker, Entity &defender) {

    attacker.Stamina -= this->StaminaCost;

    if (buffType == "Guard") {

        defender.isGuarding = true;


    }

}

std::string SupportSkill::returnType () {

    return "SUPPORT";

}
