#pragma once

#include <string>
#include <vector>

namespace InputHandler
{
    void continuePrompt();
    int getInt(int min, int max);
    int selectMenu(
        const string &heading,
        const vector<string> &options);
}