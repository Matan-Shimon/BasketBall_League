//
// Created by matan on 31/05/2022.
//

#include "Team.hpp"
Team::Team(){
    this->name = nullptr;
    this->talent = 0;
    this->total_home_games = 0;
    this->total_home_wins = 0;
    this->total_away_games = 0;
    this->total_away_wins = 0;
    this->points = 0;
    this->winning_streak = 0;
    this->losing_streak = 0;
}
Team::Team(string const & name, int const & talent){
    this->name = name;
    this->talent = talent;
    this->total_home_games = 0;
    this->total_home_wins = 0;
    this->total_away_games = 0;
    this->total_away_wins = 0;
    this->points = 0;
    this->winning_streak = 0;
    this->losing_streak = 0;
}
void Team::setName(string const & name){
    this->name = name;
}
void Team::setTalent(int const & talent){
    this->talent = talent;
}
const int Team::getTalent() const{
    return this->talent;
}

void Team::add_stat(bool home, bool win){
    if (home == true) {
        if (win == true) {
            this->total_home_wins++;
        }
        this->total_home_games++;
    }
    else {
        if (win == true) {
            this->total_away_wins++;
        }
        this->total_away_games++;
    }
}
string Team::getName(){
    return this->name;
}
void Team::add_points(int diff){
    this->points += diff;
}
int Team::get_num_of_wins(){
    return this->total_home_wins+this->total_away_wins;
}
int Team::get_num_of_losses(){
    return this->total_home_games+this->total_away_games-this->get_num_of_wins();
}
int Team::get_num_of_wins_with_points(){
    return get_num_of_wins()+this->points;
}
int Team::get_points() {
    return this->points;
}
int& Team::get_win_streak(){
    return this->winning_streak;
}
int& Team::get_lose_streak(){
    return this->losing_streak;
}
int& Team::get_max_win_streak(){
    return this->max_win_streak;
}
int& Team::get_max_lose_streak(){
    return this->max_lose_streak;
}
int Team::get_home_wins(){
    return this->total_home_wins;
}
int Team::get_away_wins(){
    return this->total_away_wins;
}