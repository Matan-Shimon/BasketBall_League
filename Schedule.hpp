//
// Created by matan on 18/06/2022.
//

#ifndef BASKETBALL_SCHEDULE_H
#define BASKETBALL_SCHEDULE_H

#include "League.hpp"
#include "Game.hpp"
#include "string"
#include "iostream"
#include "unordered_map"
#include "Game.hpp"

class Schedule {
private:
    League league;
    unordered_map<int, vector<string>> schedule;
public:
    Schedule();
    Schedule(League league);
    void set_schedule();
    void run_games();
    void play_game(Team& home_team, Team& away_team);
};


#endif //BASKETBALL_SCHEDULE_H
