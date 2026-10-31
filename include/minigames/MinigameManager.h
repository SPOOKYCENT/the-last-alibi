#pragma once

#include <string>
#include "minigames/MinigameRegistry.h"

using namespace std;

namespace Minigames
{
    class MinigameManager
    {
    private:
        MinigameRegistry registry;

    public:
        explicit MinigameManager(MinigameRegistry &registry);
        MinigameResult play(const string &id);
    };
}