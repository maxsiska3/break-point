#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Player.h"
using namespace std;

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

    Tournament();

    // Mutators
    void addPlayer(Player p); // Adds player to the tree
    void advanceWinner(Player winner); // Advances player up tree
    void display() const; // Displays bracket
    void reset(); // Clears tree

    Player* getChampion() const; // Returns the champion of tournament

private:
    BinaryNode* root;
    string tournamentName;
    int numPlayers;
};

#endif
