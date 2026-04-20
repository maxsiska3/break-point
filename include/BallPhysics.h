#ifndef BALLPHYSICS_H
#define BALLPHYSICS_H

enum class CourtSide;

/*
 * BallPhysics — A live, court-aware physics object that tracks ball position,
 * velocity, and spin on a singles tennis court.
 *
 * All operations are O(1), making this the least expensive ADT in the system.
 * Position uses 3D coordinates (x along baseline, y along sideline, z for height).
 * Court boundaries and net collisions are checked against standard singles dimensions.
 */
class BallPhysics
{
public:
    struct Vector3
    {
        float x;
        float y;
        float z;

        Vector3() : x(0), y(0), z(0) {}
        Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    };

    enum class SpinType
    {
        TOPSPIN,
        SLICE,
        FLAT
    };

    enum class BallStatus
    {
        IN_PLAY,
        OUT_OF_BOUNDS,
        NET,
        BOUNCED,
        HELD
    };

    // Court dimensions (singles, in meters)
    static constexpr float COURT_LENGTH = 23.77f;
    static constexpr float COURT_WIDTH = 8.23f;
    static constexpr float NET_HEIGHT = 0.914f;
    static constexpr float SERVICE_LINE = 6.40f;

    // Physics constants
    static constexpr float GRAVITY = 9.81f;
    static constexpr float AIR_RESISTANCE = 0.05f;
    static constexpr float BOUNCE_DAMPING = 0.75f;
    static constexpr float SPIN_EFFECT = 0.02f;

    // Constructors

    // Initializes ball at origin with zero velocity and FLAT spin
    BallPhysics();

    // Initializes ball at given position and velocity with FLAT spin
    BallPhysics(Vector3 pos, Vector3 vel);

    // Getters

    // Returns the ball's x-coordinate (along baseline)
    float getX() const;

    // Returns the ball's y-coordinate (along sideline)
    float getY() const;

    // Returns the ball's z-coordinate (height above court)
    float getZ() const;

    // Returns the ball's 3D position vector
    Vector3 getPosition() const;

    // Returns the ball's 3D velocity vector
    Vector3 getVelocity() const;

    // Returns the ball's current spin type
    SpinType getSpin() const;

    // Returns the ball's current status
    BallStatus getStatus() const;

    // Returns the number of times the ball has bounced
    int getBounceCount() const;

    // Returns true if the ball status is IN_PLAY
    bool isInPlay() const;

    // Returns which side of the court the ball is on based on x-position
    CourtSide landingSide() const;

    // Setters

    // Sets the ball's position to the given vector
    void setPosition(Vector3 pos);

    // Sets the ball's velocity to the given vector
    void setVelocity(Vector3 vel);

    // Sets the ball's spin type
    void setSpin(SpinType s);

    // Sets the ball's status
    void setStatus(BallStatus s);

    // Physics updates

    // Advances the ball's physics simulation by deltaTime seconds
    void update(float deltaTime);

    // Applies gravitational acceleration to velocity
    void applyGravity(float deltaTime);

    // Applies air resistance deceleration to velocity
    void applyAirResistance(float deltaTime);

    // Modifies trajectory based on current spin type
    void applySpinEffect(float deltaTime);

    // Court interactions

    // Returns true if the ball is within court boundaries
    bool checkBounds() const;

    // Returns true if the ball has crossed the net plane below net height
    bool checkNet() const;

    // Handles court surface bounce, reversing z-velocity with damping
    void bounce();

    // Sets status to NET and zeroes velocity
    void hitNet();

    // Utility

    // Resets ball to origin with zero velocity and IN_PLAY status
    void reset();

    // Initializes ball for a serve with given position, velocity, and spin
    void serve(Vector3 startPos, Vector3 startVel, SpinType startSpin);

    // Updates ball velocity and spin after a player hit
    void hit(Vector3 newVel, SpinType newSpin);

    // Prints current ball state to stdout
    void display() const;

private:
    Vector3 position;
    Vector3 velocity;
    SpinType spin;
    BallStatus status;
    int bounceCount;
};

#endif
