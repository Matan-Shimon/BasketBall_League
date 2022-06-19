//
// Created by matan on 31/05/2022.
//

#include "Game.hpp"
#include "random"
Game::Game(Team& home_team, Team& away_team): home_team(home_team), away_team(away_team){
    this->home_score = 0;
    this->away_score = 0;
    this->game_started = false;
}

void Game::set_scores() {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    normal_distribution<double> home_options(75, 20);
    normal_distribution<double> away_options(70, 20);
    this->home_score = home_options(generator) + this->home_team.getTalent();
    this->away_score = away_options(generator) + this->away_team.getTalent();
    if (this->home_score == this->away_score) {
        this->set_scores();
    }
    this->update_teams_stats();
    this->print_game();
}

void Game::update_teams_stats() {
    if (this->game_started) {
        if (this->home_score > this->away_score) {
            this->home_team.add_stat(true, true);
            this->home_team.get_win_streak()++;
            this->home_team.get_lose_streak() = 0;
            if (this->home_team.get_win_streak() > this->home_team.get_max_win_streak()) {
                this->home_team.get_max_win_streak() = this->home_team.get_win_streak();
            }
            this->away_team.add_stat(false, false);
            this->away_team.get_win_streak() = 0;
            this->away_team.get_lose_streak()++;
            if (this->away_team.get_lose_streak() > this->away_team.get_max_lose_streak()) {
                this->away_team.get_max_lose_streak() = this->away_team.get_lose_streak();
            }
        }
        else {
            this->home_team.add_stat(true, false);
            this->home_team.get_win_streak() = 0;
            this->home_team.get_lose_streak()++;
            if (this->home_team.get_lose_streak() > this->home_team.get_max_lose_streak()) {
                this->home_team.get_max_lose_streak() = this->home_team.get_lose_streak();
            }
            this->away_team.add_stat(false, true);
            this->away_team.get_win_streak()++;
            this->away_team.get_lose_streak() = 0;
            if (this->away_team.get_win_streak() > this->away_team.get_max_win_streak()) {
                this->away_team.get_max_win_streak() = this->away_team.get_win_streak();
            }
        }
        this->home_team.add_points(this->home_score-this->away_score);
        this->away_team.add_points(this->away_score-this->home_score);
    }
    else {
        throw invalid_argument("Game hasn't started");
    }
}
void Game::print_game() {
    cout << this->home_team.getName()+" "+ to_string(this->home_score)+" : "+ to_string(this->away_score)+" "+this->away_team.getName() << endl;
}