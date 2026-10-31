#include "minigames/MinigameManager.h"

namespace Minigames
{
    MinigameManager::MinigameManager(MinigameRegistry &registry) : registry(registry) {}

    MinigameResult MinigameManager::play(const string &id)
    {
        Minigame *minigame = registry.getMinigame(id);
        if (minigame)
            return minigame->play();
        return {MinigameStatus::LOSE, 0, 0, "Minigame not found."};
    }
}