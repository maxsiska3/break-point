#ifndef MATCH_H
#define MATCH_H

#include <queue>
#include <vector>
#include <utility>
#include <string>

class Player;

enum class CourtSide
{
    DEUCE,
    ADVANTAGE
};

/*
 * Match — A state machine that processes a queue of Point outcomes to advance
 * score through the tennis scoring hierarchy: points → games → sets → tiebreaks.
 * 
 * Points are enqueued as they occur, then processed sequentially. Each point
 * may trigger a game win, which may trigger a set win, which may end the match.
 * Tiebreaks are automatically entered at 6-6 in any set.
 */
class Match
{
public:
    enum class PointOutcome
    {
        ACE,
        WINNER,
        FORCED_ERROR,
        UNFORCED_ERROR,
        DOUBLE_FAULT,
        LET
    };

    struct Point
    {
        PointOutcome outcome;
        int winner;
        CourtSide side;
    };

    enum class MatchState
    {
        IN_PROGRESS,
        PLAYER1_WINS,
        PLAYER2_WINS
    };

    // Constructors

    // Initializes an empty match with no players
    Match();

    // Initializes a match between two players with specified number of sets (3 or 5)
    Match(Player* p1, Player* p2, int numSets);

    // Getters

    // Returns pointer to player 1
    Player* getPlayer1() const;

    // Returns pointer to player 2
    Player* getPlayer2() const;

    // Returns player 1's current point score in the active game
    int getPlayer1Points() const;

    // Returns player 2's current point score in the active game
    int getPlayer2Points() const;

    // Returns player 1's game count for the specified set index
    int getPlayer1Games(int set) const;

    // Returns player 2's game count for the specified set index
    int getPlayer2Games(int set) const;

    // Returns total sets won by player 1
    int getPlayer1Sets() const;

    // Returns total sets won by player 2
    int getPlayer2Sets() const;

    // Returns the current set index (0-based)
    int getCurrentSet() const;

    // Returns true if the current game is a tiebreak
    bool isTiebreak() const;

    // Returns tiebreak score as (player1 points, player2 points)
    std::pair<int, int> getTiebreakScore() const;

    // Returns the current match state (in progress or winner)
    MatchState getState() const;

    // Returns pointer to the winning player, or nullptr if match ongoing
    Player* getWinner() const;

    // Returns pointer to the player currently serving
    Player* getServer() const;

    // Returns human-readable score string (e.g., "30-15" or "6-4, 3-2")
    std::string getScoreString() const;

    // Mutators

    // Adds a point outcome to the processing queue
    void enqueuePoint(Point p);

    // Processes the next point from the queue and updates match state
    void processNextPoint();

    // Processes all queued points until the queue is empty
    void processAllPoints();

    // Resets the match to initial state with score 0-0
    void reset();

    // Prints the current match state to stdout
    void display() const;

private:
    Player* player1;
    Player* player2;
    std::queue<Point> pointQueue;

    int player1Points;
    int player2Points;
    std::vector<std::pair<int, int>> gamesPerSet;

    int player1Sets;
    int player2Sets;

    int currentSet;
    int setsToWin;
    bool inTiebreak;
    int tiebreakPoints[2];
    MatchState state;
    Player* server;

    // Increments point score for the given player (0 or 1); handles 0→15→30→40
    // progression and deuce/advantage logic; calls awardGame() when game is won
    void awardPoint(int player);

    // Increments game score for the given player in the current set; checks for
    // 6-6 tiebreak entry; calls awardSet() when set is won (6 games, win by 2)
    void awardGame(int player);

    // Increments set score for the given player; advances currentSet or ends
    // the match when a player reaches setsToWin
    void awardSet(int player);

    // Checks if current game scores require entering tiebreak (6-6)
    void checkTiebreak();

    // Alternates the serving player
    void switchServer();

    // Converts numeric point values to tennis notation ("0", "15", "30", "40", "Ad")
    std::string pointToString(int points, int opponentPoints) const;
};

#endif
