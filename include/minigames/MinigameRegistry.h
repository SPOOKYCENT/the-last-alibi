#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "minigames/Minigame.h"

using namespace std;

namespace Minigames
{
    class MinigameRegistry
    {
    private:
        unordered_map<string, unique_ptr<Minigame>> minigames;

    public:
        bool registerMinigame(unique_ptr<Minigame> minigame);
        Minigame *getMinigame(const string &id);
        vector<string> getAllMinigameIds() const;
    };
}