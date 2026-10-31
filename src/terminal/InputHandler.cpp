#include <iostream>
#include <limits>
#include <termios.h>
#include <unistd.h>
#include "terminal/Terminal.h"
#include "terminal/InputHandler.h"

using namespace std;

void InputHandler::continuePrompt()
{
    Terminal::inputLine();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

int InputHandler::getInt(int min, int max)
{
    Terminal::inputLine();
    termios oldt{}, newt{};
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string input;
    while (true)
    {
        char ch;
        if (read(STDIN_FILENO, &ch, 1) != 1)
            continue;

        if (ch == '\n' or ch == '\r')
        {
            if (input.empty())
                continue;

            try
            {
                int choice = stoi(input);
                if (choice >= min && choice <= max)
                {
                    cout << "\n";
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    return choice;
                }
            }
            catch (...)
            {
            }

            input.clear();
            continue;
        }

        if (ch == 127 or ch == '\b')
        {
            if (!input.empty())
            {
                input.pop_back();
                cout << "\b \b" << flush;
            }
            continue;
        }

        if (ch >= '0' and ch <= '9')
        {
            input += ch;
            cout << Terminal::Color::MAGENTA
                 << ch
                 << Terminal::Color::RESET
                 << flush;
        }
    }
}

int InputHandler::selectMenu(
    const string &heading,
    const vector<string> &options)
{
    if (options.empty())
        return -1;

    // Save terminal settings
    termios oldTerm{}, newTerm{};

    tcgetattr(STDIN_FILENO, &oldTerm);

    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ICANON | ECHO);
    newTerm.c_cc[VMIN] = 1;
    newTerm.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);

    int selected = 0;

    auto render = [&]()
    {
        Terminal::clearScreen();
        cout << Terminal::Color::CYAN
             << Terminal::Color::BOLD
             << heading
             << Terminal::Color::RESET
             << "\n\n";

        for (int i = 0; i < (int)options.size(); i++)
        {
            if (i == selected)
            {
                cout << Terminal::Color::YELLOW
                     << Terminal::Color::BOLD
                     << "> " << options[i]
                     << Terminal::Color::RESET;
            }
            else
            {
                cout << "  " << options[i];
            }

            cout << '\n';
        }

        cout << "\nUse UP/DOWN arrows and ENTER to select."
             << flush;
    };

    render();

    while (true)
    {
        char ch;

        if (read(STDIN_FILENO, &ch, 1) != 1)
            continue;

        // Arrow keys begin with ESC
        if (ch == '\033')
        {
            char seq[2];

            if (read(STDIN_FILENO, &seq[0], 1) != 1 ||
                read(STDIN_FILENO, &seq[1], 1) != 1)
                continue;

            if (seq[0] == '[')
            {
                if (seq[1] == 'A') // UP
                {
                    selected--;

                    if (selected < 0)
                        selected = options.size() - 1;
                }
                else if (seq[1] == 'B') // DOWN
                {
                    selected++;

                    if (selected >= (int)options.size())
                        selected = 0;
                }
            }

            render();
        }

        else if (ch == '\n' || ch == '\r')
        {
            tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm);
            cout << '\n';

            return selected;
        }
    }
}