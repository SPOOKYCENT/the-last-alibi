#pragma once

#include <string>
#include "minigames/MinigameResult.h"

using namespace std;

namespace Minigames
{
    struct MinigameConfig
    {
        string id;
        string name;
    };

    class Minigame
    {
    protected:
        MinigameConfig config;
        explicit Minigame(const MinigameConfig &config) : config(move(config)) {}

    public:
        virtual ~Minigame() = default;
        virtual string getId() const
        {
            return config.id;
        }
        virtual string getName() const
        {
            return config.name;
        }
        virtual MinigameResult play() = 0;
    };
}