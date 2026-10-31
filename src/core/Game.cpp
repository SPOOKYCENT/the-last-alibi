#include <iostream>
#include "core/Game.h"
#include "terminal/Terminal.h"

using namespace std;

void Game::showTitleScreen()
{
    Terminal::clearScreen();
    cout << Terminal::Color::RED
         << Terminal::Color::BOLD
         << "The Last Alibi"
         << Terminal::Color::RESET
         << "\n";
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
        Terminal::clearScreen();
        cout << Terminal::Color::CYAN
             << Terminal::Color::BOLD
             << Terminal::Color::UNDERLINE
             << "Main Menu:\n"
             << Terminal::Color::RESET;

        cout << "1. New Game\n";
        cout << "2. Continue\n";
        cout << "3. Settings\n";
        cout << "4. Exit\n";

        int choice;
        cout << Terminal::Color::MAGENTA;
        cin >> choice;
        cout << Terminal::Color::RESET;

        switch (choice)
        {
        case 1:
            newGame();
            break;
        case 2:
            continueGame();
            break;
        case 3:
            openSettings();
            break;
        case 4:
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
    showTitleScreen();
    showMainMenu();
}