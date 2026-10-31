#pragma once

#include <string>

using namespace std;

namespace Minigames
{
    enum class MinigameStatus
    {
        WIN,
        LOSE,
        DRAW
    };

    struct MinigameResult
    {
        MinigameStatus status;
        int score = 0;
        int attemptsUsed = 0;
        string message;
    };
}