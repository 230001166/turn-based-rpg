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

        std::cout << "\nVs. " << opponent.name << " "; displayEntityHealthBar (opponent);

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

        if (opponent.Stamina >= opponent.moveset [0]->StaminaCost) { opponent.moveset [0]->use (opponent, player); } else {

            opponent.moveset [1]->use (opponent, opponent);

        }

        if (opponent.isGuarding) { opponent.isGuarding = false; }

        if (player.isGuarding) { opponent.isGuarding = false; }

    }

    if (player.Health > 0) {

        std::cout << "Yay! You won!" << std::endl;

    }

    if (player.Health <= 0 && opponent.Health > 0) {

        std::cout << "You died...Your opponent had " << opponent.Health << " HP left." << std::endl;

    }

}

void Game::displayEntityStats (Entity &target) {

    std::cout << "Lv. " << target.Level << " " << target.name << std::endl;
    std::cout << "HP " << target.Health << " /" << target.MaxHealth << std::endl;
    std::cout << "MP " << target.Mana << " /" << target.MaxMana << std::endl;
    std::cout << "STAMINA " << target.Stamina << " /" << target.MaxStamina << std::endl;
    std::cout << "======================" << std::endl;

}

void Game::displayEntityHealthBar (Entity &target) {

    std::cout << "[";

    double barsToFill = (double)target.Health / (double)target.MaxHealth * 20;

    for (int i = 0; i < barsToFill; i++) {

        std::cout << "=";

    }

    for (int i = 0; i < 20-barsToFill; i++) {

        std::cout << " ";

    }

    std::cout << "]\n" << std::endl;

}

void Game::displayEntityMoveset (Entity &target) {

    for (unsigned int i = 0; i < target.moveset.size (); i++) {

        std::cout << "[" << i+1 << "] - " << target.moveset [i]->Name << " | " << target.moveset [i]->returnType () << std::endl;

    }

    std::cout << "======================" << std::endl;

}
