#pragma once

class Game
{
private:
    bool running;
    void showTitleScreen();
    void newGame();
    void continueGame();
    void openSettings();
    void showMainMenu();

public:
    Game() : running(true) {}
    void run();
};