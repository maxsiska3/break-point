# Break Point

A tennis game module built in C++ with SFML graphics, developed as part of the AIWars game project for COP4530 Data Structures at Florida State University.

## Overview

Break Point simulates a single-elimination tennis tournament. Players compete in matches that are tracked in real time, with ball physics, player movement, and a full bracket system all working together.

## Project Structure

```
include/
├── Player.h        — ADT class representing a tennis player
├── Tournament.h    — ADT binary tree representing a single-elimination bracket
├── Match.h         — ADT queue representing a live match score tracker
├── BallPhysics.h   — ADT struct representing ball position, velocity, and spin
└── GameLoop.h      — Ties everything together with SFML graphics

src/
├── Player.cpp
├── Tournament.cpp
├── Match.cpp
├── BallPhysics.cpp
├── GameLoop.cpp
└── main.cpp
```

## Modules

### Player
Represents a tennis player with attributes like name, gender, ranking, stats (serve, forehand, backhand, speed, stamina), racket, outfit, and court position. Tracks match history and supports fatigue/recovery mechanics.

### Tournament
A binary tree where each node represents a match. Leaves are first-round matchups and the root is the championship match. Winners advance up the tree until a champion is crowned.

### Match
A queue-based score tracker that manages the flow of a live match, including sets, games, and points.

### BallPhysics
Handles ball position, velocity, and spin calculations during a rally.

### GameLoop
Integrates all modules and drives the SFML rendering loop.

## Dependencies

- C++17
- [SFML](https://www.sfml-dev.org/)

## Course

COP4530 — Data Structures and Algorithms, Florida State University
