#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Match.h"
#include "Tournament.h"
#include "BallPhysics.h"

using namespace std;

/*
 * GameLoop — The top-level controller that integrates all modules and drives
 * the SFML render/update loop for Break Point.
 *
 * Manages the window, game state, and coordinates between Player, Match,
 * Tournament, and BallPhysics each frame.
 */
class GameLoop
{
public:
    enum class GameState
    {
        MENU,
        TOURNAMENT,
        MATCH,
        GAME_OVER
    };

    // Initializes the window, all modules, and sets state to MENU
    GameLoop();

    // Runs the main loop until the window is closed
    void run();

    // Handles SFML window events (close, keyboard, mouse)
    void handleEvents();

    // Updates game logic for the current frame
    void update(float deltaTime);

    // Renders the current frame to the window
    void render();

    // Loads players into the tournament bracket
    void loadTournament();

    // Starts a match between two players
    void startMatch(Player* p1, Player* p2);

    // Called when a match ends — advances winner and checks if tournament is over
    void onMatchEnd();

    // Returns the current game state
    GameState getState() const;

private:
    sf::RenderWindow window;
    GameState state;

    Tournament tournament;
    Match currentMatch;
    BallPhysics ball;

    float deltaTime;
};

#endif
