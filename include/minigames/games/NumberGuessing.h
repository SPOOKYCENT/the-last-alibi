#pragma once

#include "minigames/Minigame.h"

namespace Minigames
{
    struct NumberGuessingConfig : public MinigameConfig
    {
        int minNumber = 1;
        int maxNumber = 100;
        int maxAttempts = 10;
    };

    class NumberGuessing : public Minigame
    {
    private:
        NumberGuessingConfig config;

    public:
        explicit NumberGuessing(NumberGuessingConfig config);
        MinigameResult play() override;
    };
}