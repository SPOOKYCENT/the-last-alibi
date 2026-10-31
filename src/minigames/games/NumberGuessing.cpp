#include <iostream>
#include <random>
#include <limits>
#include "minigames/games/NumberGuessing.h"
#include "terminal/Terminal.h"
#include "terminal/InputHandler.h"

using namespace std;

namespace Minigames
{
    NumberGuessing::NumberGuessing(NumberGuessingConfig config) : Minigame(config), config(move(config)) {}

    MinigameResult NumberGuessing::play()
    {
        static mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(config.minNumber, config.maxNumber);

        const int targetNumber = dist(rng);

        int guess;
        int attempts = 0;

        Terminal::clearScreen();
        Terminal::printTitle("Number Guessing Game");
        cout << "Guess the number between " << config.minNumber << " and " << config.maxNumber << ". You have " << config.maxAttempts << " attempts.\n";

        while (attempts < config.maxAttempts)
        {
            cout << "Attempt " << (attempts + 1) << ": ";
            guess = InputHandler::getInt(config.minNumber, config.maxNumber);

            attempts++;

            if (guess < targetNumber)
            {
                cout << Terminal::Color::GRAY << "Too low! Try again.\n"
                     << Terminal::Color::RESET;
            }
            else if (guess > targetNumber)
            {
                cout << Terminal::Color::GRAY << "Too high! Try again.\n"
                     << Terminal::Color::RESET;
            }
            else
            {
                cout << "Congratulations! You've guessed the number!\n";
                return {MinigameStatus::WIN, 100, attempts, "You guessed the number!"};
            }
        }
        cout << Terminal::Color::RED << "Sorry, you've used all your attempts. The number was " << targetNumber << ".\n"
             << Terminal::Color::RESET;
        return {MinigameStatus::LOSE, 0, attempts, "You failed to guess the number."};
    }
}