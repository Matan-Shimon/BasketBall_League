//
// Created by matan on 18/06/2022.
//

#include "Schedule.hpp"
#include <random>
#include "set"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
Schedule::Schedule(){}
Schedule::Schedule(League league) : league(league) {}
void Schedule::set_schedule() {
    int teams_len = this->league.get_teams().size();
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    for (unsigned int i = 0; i < teams_len; ++i) {
        set<int> check;
        std::uniform_int_distribution<> distr(0, teams_len-1);
        while (this->schedule.at(i).size() != 10) {
            int home = distr(gen);
            int away = distr(gen);
            int len = check.size();
            check.insert(home);
            check.insert(away);
            string home_team = this->league.get_teams().at(home)->getName();
            string away_team = this->league.get_teams().at(away)->getName();
            bool add = true;
            for (unsigned int k = 0; k < this->schedule.size(); ++k) {
                for (unsigned int l = 0; l < this->schedule.at(k).size(); ++l) {
                    if (this->schedule.at(k).at(l) == home_team+":"+away_team) {
                        add = false;
                    }
                }
            }
            if (add) {
                if (len == check.size()) {
                    this->schedule.at(i).push_back(home_team+":"+away_team);
                }
            }
        }
    }
}
void Schedule::run_games(){
    for (unsigned int i = 0; i < this->schedule.size(); ++i) {
        for (unsigned int j = 0; j < this->schedule.at(i).size(); ++j) {
            std::string strData = this->schedule.at(i).at(j);
            const char separator = ':';
            std::vector<string> outputArray;
            std::stringstream streamData(strData);
            std::string val;
            while (std::getline(streamData, val, separator)) {
                outputArray.push_back(val);
            }
            string home_name = outputArray.at(0);
            string away_name = outputArray.at(1);
            unsigned int home_index = 0;
            unsigned int away_index = 0;
            for (unsigned int k = 0; k < this->league.get_teams().size(); ++k) {
                if (this->league.get_teams().at(k)->getName() == home_name) {
                    home_index = k;
                }
                if (this->league.get_teams().at(k)->getName() == away_name) {
                    away_index = k;
                }
            }
            this->play_game(*this->league.get_teams().at(home_index), *this->league.get_teams().at(away_index));
        }
    }
}
void Schedule::play_game(Team& home_team, Team& away_team){
    Game game(home_team, away_team);
    game.set_scores();
    game.update_teams_stats();
}