#include <iostream>
#include "terminal/Terminal.h"

using namespace std;

void Terminal::printLine(const string &text)
{
    cout << text << endl;
}

void Terminal::printTitle(const string &title)
{
    cout << endl
         << Color::RED
         << Color::BOLD
         << "============================================\n"
         << "              " << title << "\n"
         << "============================================\n\n"
         << Color::RESET;
}

void Terminal::inputLine()
{
    cout << endl;
    cout << Color::GRAY
         << "> "
         << Color::RESET
         << flush;
}

void Terminal::pause()
{
    cout << Color::YELLOW
         << "Press Enter to continue..."
         << Color::RESET;
    cin.ignore();
}

void Terminal::divider()
{
    cout << Color::GRAY
         << "--------------------------------------------\n"
         << Color::RESET;
}

void Terminal::clearScreen()
{
    cout << "\033[2J\033[H" << flush;
}