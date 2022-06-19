//
// Created by matan on 18/06/2022.
//

#ifndef BASKETBALL_LEAGUE_H
#define BASKETBALL_LEAGUE_H
#include "vector"
#include "Team.hpp"
class League {
private:
    std::vector<Team*> teams;
    std::vector<Team*> table;
public:
    League();
    League(std::vector<Team*> teams);
    void set_teams(std::vector<Team*> teams);
    std::vector<Team*> get_teams();
    void calculate_table();
    void present_league_table();
    void present_league_stats(int top_teams);
};


#endif //BASKETBALL_LEAGUE_H
