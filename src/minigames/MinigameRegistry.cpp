#include <utility>
#include <string>
#include "minigames/MinigameRegistry.h"

using namespace std;

namespace Minigames
{
    bool MinigameRegistry::registerMinigame(unique_ptr<Minigame> minigame)
    {
        if (!minigame)
            return false;
        string id = minigame->getId();
        if (id.empty() or minigames.find(id) != minigames.end())
            return false;

        minigames.emplace(id, move(minigame));
        return true;
    }

    Minigame *MinigameRegistry::getMinigame(const string &id)
    {
        auto it = minigames.find(id);
        if (it == minigames.end())
            return nullptr;
        return it->second.get();
    }

    vector<string> MinigameRegistry::getAllMinigameIds() const
    {
        vector<string> ids;
        ids.reserve(minigames.size());
        for (const auto &[id, game] : minigames)
            ids.push_back(id);
        return ids;
    }
}