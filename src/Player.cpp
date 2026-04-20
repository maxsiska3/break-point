#include "../include/Player.h"
#include <iostream>
using namespace std;

// Constructors
Player::Player()
{
    name          = "Unknown";
    gender        = "Unknown";
    ranking       = 0;
    matchesWon    = 0;
    matchesLost   = 0;
    matchesPlayed = 0;
    racket        = "Default Racket";
    outfit        = "Default Outfit";
    x             = 0.0;
    y             = 0.0;
    stats.serve    = 50;
    stats.forehand = 50;
    stats.backhand = 50;
    stats.speed    = 50;
    stats.stamina  = 100;
}

Player::Player(string n, string g, PlayerStats s)
{
    name = n;
    gender = g;
    stats = s;
    ranking       = 0;
    matchesWon    = 0;
    matchesLost   = 0;
    matchesPlayed = 0;
    racket        = "Default Racket";
    outfit        = "Default Outfit";
    x             = 0.0;
    y             = 0.0;
}

// Getters
string Player::getName() const
{
    return name;
}

string Player::getGender() const
{
    return gender;
}

int Player::getRanking() const
{
    return ranking;
}

int Player::getMatchesWon() const
{
    return matchesWon;
}

int Player::getMatchesLost() const
{
    return matchesLost;
}

int Player::getMatchesPlayed() const
{
    return matchesPlayed;
}

Player::PlayerStats Player::getStats() const
{
    return stats;
}

string Player::getRacket() const
{
    return racket;
}

string Player::getOutfit() const
{
    return outfit;
}

float Player::getX() const
{
    return x;
}

float Player::getY() const
{
    return y;
}

// Setters
void Player::setRanking(int rank)
{
    ranking = rank;
}

void Player::setRacket(string rac)
{
    racket = rac;
}

void Player::setOutfit(string out)
{
    outfit = out;
}

// Mutators
void Player::recordMatchResult(bool won)
{
    if (won)
        matchesWon++;
    else
        matchesLost++;
    matchesPlayed++;
}

void Player::applyFatigue(int amount)
{
    stats.stamina -= amount;
    if (stats.stamina < 0)
        stats.stamina = 0;
}

void Player::recover()
{
    stats.stamina = 100;
}

void Player::display() const
{
    cout << "Name: "          << name          << endl;
    cout << "Gender: "        << gender        << endl;
    cout << "Ranking: "       << ranking       << endl;
    cout << "Matches Won: "   << matchesWon    << endl;
    cout << "Matches Lost: "  << matchesLost   << endl;
    cout << "Matches Played: "<< matchesPlayed << endl;
    cout << "Racket: "        << racket        << endl;
    cout << "Outfit: "        << outfit        << endl;
    cout << "Position: ("     << x << ", " << y << ")" << endl;
    cout << "Stats:"                           << endl;
    cout << "  Serve: "       << stats.serve    << endl;
    cout << "  Forehand: "    << stats.forehand << endl;
    cout << "  Backhand: "    << stats.backhand << endl;
    cout << "  Speed: "       << stats.speed    << endl;
    cout << "  Stamina: "     << stats.stamina  << endl;
}

void Player::move(float dx, float dy)
{
    x += dx;
    y += dy;
}

