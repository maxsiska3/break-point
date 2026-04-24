#ifndef BOSSFIGHT_H
#define BOSSFIGHT_H

#include <queue>
#include <string>
#include "Player.h"
#include "Match.h"

/*
 * BossFight — An ADT that manages the full lifecycle of a championship boss fight,
 * using a queue to transport players in and out of the match instance.
 *
 * Players are enqueued before the fight begins (transport in). Once two players
 * are loaded, the boss fight starts as a Match. When the match ends, the loser
 * is dequeued out (transport out) and the winner is flagged. The fight maps
 * directly to a tennis tiebreak — two players battling each other, not an NPC.
 */
class BossFight
{
public:
    enum class FightState
    {
        WAITING,      // Not enough players loaded yet
        READY,        // Two players loaded, fight not started
        IN_PROGRESS,  // Match is active
        COMPLETE      // Match has ended, winner decided
    };

    // Constructors

    // Initializes an empty boss fight with no players loaded
    BossFight();

    // Initializes a boss fight with a name and number of sets (3 or 5)
    BossFight(std::string name, int numSets);

    // Transport

    // Enqueues a player into the fight — "transport in"
    void transportIn(Player* p);

    // Dequeues the losing player out of the fight — "transport out"
    void transportOut();

    // Fight lifecycle

    // Starts the match once two players are loaded
    void startFight();

    // Ends the fight, records results, and triggers transport out
    void endFight();

    // Getters

    // Returns the current fight state
    FightState getState() const;

    // Returns the name of this boss fight instance
    std::string getName() const;

    // Returns a pointer to the winning player, or nullptr if not finished
    Player* getWinner() const;

    // Returns the number of players currently in the transport queue
    int getQueueSize() const;

    // Returns a reference to the underlying Match
    Match& getMatch();

    // Utility

    // Prints current fight status and match score to the console
    void display() const;

    // Resets the fight to initial state
    void reset();

private:
    std::string name;
    int numSets;
    FightState state;
    std::queue<Player*> transportQueue;
    Match match;
    Player* winner;
};

#endif
