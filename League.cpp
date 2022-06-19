//
// Created by matan on 18/06/2022.
//

#include "League.hpp"
League::League(){}
League::League(std::vector<Team*> teams): teams(teams){}
void League::set_teams(std::vector<Team*> teams){
    this->teams = teams;
}
std::vector<Team*> League::get_teams(){
    return this->teams;
}
void League::calculate_table() {
    for (unsigned int i = 0; i < this->teams.size(); ++i) {
        unsigned int index = 0;
        Team* team = this->teams.at(i);
        for (unsigned int j = 0; j < this->table.size(); ++j) {
            if (team->get_num_of_wins() < this->table.at(j)->get_num_of_wins()) {
                index++;
            }
            else {
                if (team->get_num_of_wins() == this->table.at(j)->get_num_of_wins()) {
                    if (team->get_num_of_wins_with_points() < this->table.at(j)->get_num_of_wins_with_points()) {
                        index++;
                    }
                }
            }
        }
        auto it_pos = this->table.begin()+index;
        this->table.insert(it_pos, team);
    }
}
void League::present_league_table(){
    this->calculate_table();
    for (unsigned int i = 0; i < this->table.size(); ++i) {
        Team* team = this->table.at(i);
        cout << to_string(i+1)+": "+team->getName()+", W: "+ to_string(team->get_num_of_wins())+", L: "
        +to_string(team->get_num_of_losses())+" Basket diff: "+to_string(team->get_points()) << endl;
    }
}
void League::present_league_stats(int top_teams) {
    cout << "Top "+ to_string(top_teams)+" teams:" << endl;
    for (unsigned int i = 0; i < top_teams; ++i) {
        Team* team = this->table.at(i);
        cout << to_string(i+1)+": "+team->getName()+", W: "+ to_string(team->get_num_of_wins())+", L: "
                +to_string(team->get_num_of_losses())+" Basket diff: "+to_string(team->get_points()) << endl;
    }

    int win_streak_index = 0, lose_streak_index = 0;
    int max_win_streak = 0, max_lose_streak = 0;
    int max_home_win = 0, max_away_win = 0;
    int max_home_index = 0, max_away_index = 0;
    vector<int> positive_points;
    for (unsigned int i = 0; i < this->table.size(); ++i) {
        Team* team = this->table.at(i);
        if (team->get_max_win_streak() > max_win_streak) {
            max_win_streak = team->get_max_win_streak();
            win_streak_index = i;
        }
        if (team->get_max_lose_streak() > max_lose_streak) {
            max_lose_streak = team->get_max_lose_streak();
            lose_streak_index = i;
        }
        if (team->get_points() > 0) {
            positive_points.push_back(i);
        }
        if (team->get_home_wins() > max_home_win) {
            max_home_win = team->get_home_wins();
            max_home_index = i;
        }
        if (team->get_away_wins() > max_away_win) {
            max_away_win = team->get_away_wins();
            max_away_index = i;
        }
    }
    cout << "Max win streak: "+ to_string(max_win_streak)+" by the "+this->table.at(win_streak_index)->getName() << endl;
    cout << "Max win streak: "+ to_string(max_lose_streak)+" by the "+this->table.at(lose_streak_index)->getName() << endl;

    cout << "There are " << positive_points.size() << " teams that managed to have positive total points" << endl;
    for (int i = 0; i < positive_points.size(); ++i) {
        Team* team = this->table.at(positive_points.at(i));
        cout << team->getName() +" managed to have "+to_string(team->get_points()) << endl;
    }

    cout << this->table.at(max_home_index)->getName()<< " has the highest home wins with " << max_home_win << " wins" << endl;
    cout << this->table.at(max_away_index)->getName()<< " has the highest away wins with " << max_away_win << " wins" << endl;
}