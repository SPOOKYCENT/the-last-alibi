#include <string>

using namespace std;

namespace Terminal
{

    namespace Color
    {
        const string RESET = "\033[0m";
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string YELLOW = "\033[33m";
        const string BLUE = "\033[34m";
        const string MAGENTA = "\033[35m";
        const string CYAN = "\033[36m";
        const string WHITE = "\033[37m";
        const string GRAY = "\033[90m";
        const string BLACK = "\033[30m";
        const string BOLD = "\033[1m";
        const string UNDERLINE = "\033[4m";
    }

    void printLine(const string &text);
    void printTitle(const string &title);
    void pause();
    void divider();
    void clearScreen();

}