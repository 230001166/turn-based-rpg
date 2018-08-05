#include "Game.h"
#include "ChargeSkill.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

Entity Game::createEntityFromID (int entityID) {

    Entity temp;

    switch (entityID) {

        case 1: {

                temp.name = "Slime";
                temp.Health = 26;
                temp.MaxHealth = 26;

                temp.Stamina = 14;
                temp.MaxStamina = 14;

                temp.Mana = 0;
                temp.MaxMana = 0;

                temp.Strength = 3;

                temp.Defense = 0;

                temp.Agility = 1;

                temp.Intelligence = 0;

                temp.Willpower = 0;

            } break;

        default: {

            } break;

    }

    return temp;

}

void Game::battle (Entity &player, Entity &opponent) {

    while (player.Health > 0 && opponent.Health > 0) {

        displayEntityStats (player);

        displayEntityMoveset (player);

        int choice = 0;

        std::cin >> choice;

        if (choice >= 1 && choice <= player.moveset.size ()) {

            if (player.moveset [choice-1]->returnType() != "SUPPORT" && player.moveset [choice-1]->returnType() != "RECOVERY") {

                player.moveset [choice-1]->use (player, opponent);

            } else {

                player.moveset [choice-1]->use (player, player);

            }

        }

        opponent.moveset [1]->use (opponent, player);

        if (opponent.isGuarding) { opponent.isGuarding = false; }

        if (player.isGuarding) { opponent.isGuarding = false; }

    }

}

void Game::displayEntityStats (Entity &target) {

    std::cout << "Lv. " << target.Level << " " << target.name << std::endl;
    std::cout << "HP " << target.Health << " /" << target.MaxHealth << std::endl;
    std::cout << "MP " << target.Mana << " /" << target.MaxMana << std::endl;
    std::cout << "STAMINA " << target.Stamina << " /" << target.MaxStamina << std::endl;
    std::cout << "======================" << std::endl;

}

void Game::displayEntityMoveset (Entity &target) {

    for (unsigned int i = 0; i < target.moveset.size (); i++) {

        std::cout << "[" << i+1 << "] - " << target.moveset [i]->Name << " | " << target.moveset [i]->returnType () << std::endl;

    }

    std::cout << "======================" << std::endl;

}
