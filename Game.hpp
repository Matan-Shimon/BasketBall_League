//
// Created by matan on 31/05/2022.
//
#pragma once
#include "iostream"
#include "Team.hpp"
using namespace std;

class Game {
private:
    Team& home_team;
    Team& away_team;
    int home_score;
    int away_score;
    bool game_started;
public:
    Game(Team& team1, Team& team2);
    void set_scores();
    void update_teams_stats();
    void print_game();
};