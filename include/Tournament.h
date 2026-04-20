#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Player.h"

/*
 * Tournament — An ADT binary tree representing a single-elimination bracket
 * where each node is a match.
 *
 * Leaves hold the first-round matchups and winners advance up toward the root.
 * The root node holds the champion once all matches are played.
 */
class Tournament
{
public:
    struct BinaryNode
    {
        Player* winner;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode() : winner(nullptr), left(nullptr), right(nullptr) {}
    };

    // Constructors

    // Initializes an empty tournament
    Tournament();

    // Mutators

    // Adds a player to the next open spot in the bracket
    void addPlayer(Player p);

    // Moves the winner of a match up to the parent node
    void advanceWinner(Player winner);

    // Prints the full bracket to the console
    void display() const;

    // Clears the tree and resets the tournament
    void reset();

    // Getters

    // Returns the winner stored at the root node
    Player* getChampion() const;

private:
    BinaryNode* root;
    std::string tournamentName;
    int numPlayers;
};

#endif
