#ifndef MODULECLUBS_HPP
#define MODULECLUBS_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "club.hpp"
#include "player.hpp"
#include "gameLineup.hpp"
using namespace std;
//Pablo de la Iglesia
class ModuleClubs{
    private:
        vector<gameLineup> lineups;
        vector<Player> players;
	    vector<Club> clubs;
    public:
        ModuleClubs();
        Date convertString(string word2);
        void clubsMenu();
        void clubByName();
        void generalClubsMenu();
        void showClubsByLeagues();
        void sortClubs();
};
#endif