#include <iostream>
#include "core/Game.h"
#include "terminal/Terminal.h"
#include "terminal/InputHandler.h"

using namespace std;

void Game::showTitleScreen()
{
    Terminal::clearScreen();
    Terminal::printTitle("The Last Alibi");
}

void Game::newGame()
{
    Terminal::clearScreen();
    cout << "Starting a new game...\n";
}

void Game::continueGame()
{
    Terminal::clearScreen();
    cout << "Continuing the game...\n";
}

void Game::openSettings()
{
    Terminal::clearScreen();
    cout << "Opening settings...\n";
}

void Game::showMainMenu()
{
    while (running)
    {
        showTitleScreen();
        int choice = InputHandler::selectMenu(
            "Main Menu",
            {"New Game", "Continue", "Settings", "Exit"});

        switch (choice)
        {
        case 0:
            newGame();
            break;
        case 1:
            continueGame();
            break;
        case 2:
            openSettings();
            break;
        case 3:
            running = false;
            Terminal::clearScreen();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}

void Game::run()
{
    showMainMenu();
}