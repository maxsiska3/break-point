#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <string>
#include "Player.h"

/*
 * Leaderboard — An ADT that tracks and ranks player results across boss fights
 * using a sorted vector ordered by wins descending.
 *
 * After each BossFight ends, results are recorded here. The leaderboard keeps
 * one entry per player and re-sorts on every update so the top player is always
 * at index 0. Supports display, lookup, and full reset between tournaments.
 */
class Leaderboard
{
public:
    struct Entry
    {
        std::string playerName;
        int wins;
        int losses;
        int ranking;

        Entry(std::string name, int wins, int losses, int ranking)
            : playerName(name), wins(wins), losses(losses), ranking(ranking) {}
    };

    // Constructors

    // Initializes an empty leaderboard
    Leaderboard();

    // Mutators

    // Adds or updates a player's entry based on a fight result
    void recordResult(Player* p, bool won);

    // Removes all entries from the leaderboard
    void reset();

    // Getters

    // Returns the entry at the top of the leaderboard (most wins)
    Entry getTopEntry() const;

    // Returns the entry for the given player name, or nullptr if not found
    Entry* getEntry(std::string playerName);

    // Returns the full sorted leaderboard as a vector
    std::vector<Entry> getEntries() const;

    // Returns the number of entries on the leaderboard
    int getSize() const;

    // Utility

    // Prints the full leaderboard to the console
    void display() const;

private:
    std::vector<Entry> entries;

    // Re-sorts entries by wins descending after each update
    void sort();
};

#endif
