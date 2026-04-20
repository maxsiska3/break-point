#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/*
 * Player — An ADT representing a tennis player with attributes, stats,
 * match history, and court position.
 *
 * Tracks name, gender, ranking, match record, equipment, and skill stats
 * (serve, forehand, backhand, speed, stamina). Supports fatigue/recovery
 * mechanics and SFML court positioning via x, y coordinates.
 */
class Player
{
public:
    struct PlayerStats
    {
        int serve;
        int forehand;
        int backhand;
        int speed;
        int stamina;
    };

    // Constructors

    // Initializes a Player with default values
    Player();

    // Initializes a Player with the given name, gender, and stats
    Player(std::string name, std::string gender, PlayerStats stats);

    // Getters

    // Returns the player's name
    std::string getName() const;

    // Returns the player's gender
    std::string getGender() const;

    // Returns the player's current ranking
    int getRanking() const;

    // Returns the number of matches won
    int getMatchesWon() const;

    // Returns the number of matches lost
    int getMatchesLost() const;

    // Returns the total number of matches played
    int getMatchesPlayed() const;

    // Returns the player's stats struct
    PlayerStats getStats() const;

    // Returns the player's racket
    std::string getRacket() const;

    // Returns the player's outfit
    std::string getOutfit() const;

    // Returns the player's x position on the court
    float getX() const;

    // Returns the player's y position on the court
    float getY() const;

    // Setters

    // Sets the player's ranking
    void setRanking(int ranking);

    // Sets the player's racket
    void setRacket(std::string racket);

    // Sets the player's outfit
    void setOutfit(std::string outfit);

    // Mutators

    // Updates wins or losses and increments matches played after a match ends
    void recordMatchResult(bool won);

    // Reduces stamina by the given amount to simulate fatigue
    void applyFatigue(int amount);

    // Restores stamina to full after rest
    void recover();

    // Prints all player info to the console
    void display() const;

    // Moves the player on the court by the given delta
    void move(float dx, float dy);

private:
    float x;
    float y;
    std::string name;
    std::string gender;
    int ranking;
    int matchesWon;
    int matchesLost;
    int matchesPlayed;
    PlayerStats stats;
    std::string racket;
    std::string outfit;
};

#endif
