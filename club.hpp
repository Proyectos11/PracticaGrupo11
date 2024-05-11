#ifndef CLUB_HPP
#define CLUB_HPP
#include <iostream>
#include <vector>
#include "player.hpp"
using namespace std;
class Club{
    private:
        int clubId;
        string domesticCompetitionId;
        string clubName;
        int squadSize;
        float averageAge;
        string stadiumName;
        string coachName;
        vector<Player> players;
        int numberOfPlayers;
        string lineup;
    public:
        Club(int clubId,string domesticCompetitionId,
            string clubName,int squadSize,float averageAge,string stadiumName);
        void setPlayers(vector<Player> players2);
        void showBestPlayers();
        void sortPlayers();
        string getCoachName();
        float getAverageAge();
        string getClubName();
		vector<Player> getPlayers();
};
#endif