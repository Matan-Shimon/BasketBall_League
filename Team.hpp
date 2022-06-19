//
// Created by matan on 31/05/2022.
//
#pragma once
#include "iostream"
using namespace std;

class Team {
private:
    string name;
    int talent;
    int total_home_games;
    int total_home_wins;
    int total_away_games;
    int total_away_wins;
    int points;
    int winning_streak;
    int losing_streak;
    int max_win_streak;
    int max_lose_streak;
public:
    Team();
    Team(string const & name, int const & talent);
    void setName(string const & name);
    void setTalent(int const & talent);
    const int getTalent() const;
    void add_stat(bool home, bool win);
    string getName();
    void add_points(int diff);
    int get_num_of_wins();
    int get_num_of_losses();
    int get_num_of_wins_with_points();
    int get_points();
    int& get_win_streak();
    int& get_lose_streak();
    int& get_max_win_streak();
    int& get_max_lose_streak();
    int get_home_wins();
    int get_away_wins();
};