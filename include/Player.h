#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

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
    Player();
    Player(string name, string gender, int ranking, PlayerStats stats, string racket, string outfit);

    // Getters
    string getName() const;
    string getGender() const;
    int getRanking() const;
    int getMatchesWon() const;
    int getMatchesLost() const;
    int getMatchesPlayed() const;
    PlayerStats getStats() const;
    string getRacket() const;
    string getOutfit() const;

    // Setters
    void setRanking(int ranking);
    void setRacket(string racket);
    void setOutfit(string outfit);

    // Mutators
    void recordMatchResult(bool won); // Win/Lose
    void applyFatigue(int amount); // Lowers speed and slows hits as a result of stamina being consumed
    void recover(); // Recovers stamina
    void display() const; // Dislays all player info 

private:
    string name;
    string gender;
    int ranking;
    int matchesWon;
    int matchesLost;
    int matchesPlayed;
    PlayerStats stats;
    string racket;
    string outfit;
};

#endif
