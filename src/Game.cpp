#include "Game.h"
#include "ChargeSkill.h"
#include "SupportSkill.h"
#include "RecoverySkill.h"
#include "SpecialSkill.h"
#include "Renderer.h"

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

                temp.Experience = 3;

            } break;

        default: {

            } break;

    }

    return temp;

}

void Game::loop (Entity &player) {

    while (player.Health > 0) {

        renderer.render (tilemap, player, playerXPosition, playerYPosition);

        char input;

        std::cin >> input;

        if (input == 'a' || input == 'A') {

            if (playerCanMoveToTile (tilemap, -1, 0)) { playerXPosition--; }

        }

        if (input == 'w' || input == 'W') {

            if (playerCanMoveToTile (tilemap, 0, -1)) { playerYPosition--; }

        }

        if (input == 's' || input == 'S') {

            if (playerCanMoveToTile (tilemap, 0, 1)) { playerYPosition++; }

        }

        if (input == 'd' || input == 'D') {

            if (playerCanMoveToTile (tilemap, 1, 0)) { playerXPosition++; }

        }

        if (input == 's') {

            displayDetailedEntityStats (player);

        }

        int randomNumber = rand () % 99 + 1;

        if (randomNumber <= 15) {

            Entity test; test = createEntityFromID (1);

            Skill tempSkill;

            Skill *light_attack = &tempSkill;

            light_attack->Name = "Light Attack";
            light_attack->StaminaCost = 1;

            test.moveset.push_back (light_attack);

            RecoverySkill rest; rest.StaminaRecovery = 3; rest.Name = "Rest";

            Skill *recovery_rest = &rest;

            test.moveset.push_back (recovery_rest);

            battle (player, test);

        }

    }

}

bool Game::playerCanMoveToTile (tileMap &tilemap, int xOffset, int yOffset) {

    if (playerXPosition + xOffset >= 0 && playerXPosition + xOffset <= tilemap.TILEMAP_LENGTH-1
     && playerYPosition + yOffset >= 0 && playerYPosition + yOffset <= tilemap.TILEMAP_LENGTH-1) {

        return true;

     }

     return false;

}

void Game::displayDetailedEntityStats (Entity &target) {

    displayEntityStats (target);

    std::cout << "STRENGTH " << target.Strength << std::endl;
    std::cout << "DEFENSE " << target.Defense << std::endl;
    std::cout << "AGILITY " << target.Agility << std::endl;
    std::cout << "INTELLIGENCE " << target.Intelligence << std::endl;
    std::cout << "WILLPOWER " << target.Willpower << std::endl;
    std::cout << "EVASION " << target.Evasion << "%" << std::endl;
    std::cout << "EXPERIENCE POINTS " << target.Experience << std::endl;

}

void Game::battle (Entity &player, Entity &opponent) {

    while (player.Health > 0 && opponent.Health > 0) {

        displayEntityStats (player);

        std::cout << "\nVs. " << opponent.name << " "; displayEntityHealthBar (opponent);

        displayEntityMoveset (player);

        int choice = 0; char temp_char;

        std::cin >> temp_char; choice = temp_char - '0';

        if (choice >= 1 && choice <= player.moveset.size ()) {

            if (player.isGuarding) { opponent.isGuarding = false; }

            if (player.moveset [choice-1]->returnType() != "SUPPORT" && player.moveset [choice-1]->returnType() != "RECOVERY") {

                player.moveset [choice-1]->use (player, opponent);

            } else {

                player.moveset [choice-1]->use (player, player);

            }

        }

        if (opponent.isGuarding) { opponent.isGuarding = false; }

        if (opponent.Stamina >= opponent.moveset [0]->StaminaCost) { opponent.moveset [0]->use (opponent, player); } else {

            opponent.moveset [1]->use (opponent, opponent);

        }
    }

    if (player.Health > 0) {

        std::cout << "You won!" << std::endl;

        player.Experience += opponent.Experience;

        if (player.Experience >= (player.Level * player.Level * player.Level) + (player.Level * player.Level * 6)) {

            std::cout << "Level up!" << std::endl;

            player.Level++;

            player.MaxHealth += rand () % 7 + 1;

            player.MaxStamina += rand () % 5 + 2;

        }

        player.Health = player.MaxHealth;

        player.Stamina = player.MaxStamina;

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
