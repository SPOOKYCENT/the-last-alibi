#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "core/Game.h"
#include "terminal/Terminal.h"

using namespace std;

int main()
{
    try
    {
        Game game;
        game.run();
    }
    catch (const std::exception &e)
    {
        cerr << Terminal::Color::RED
             << "\nA fatal error occured: "
             << e.what()
             << Terminal::Color::RESET << "\n";

        return EXIT_FAILURE;
    }
    catch (...)
    {
        cerr << Terminal::Color::RED
             << "\nAn unknown fatal error occured."
             << Terminal::Color::RESET << "\n";

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}