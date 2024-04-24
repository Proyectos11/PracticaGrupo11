#ifndef CLUB_HPP
#define CLUB_HPP
#include "player.hpp"
#include "gameLineup.hpp"
using namespace std;
class Club{
    private:
        int clubId;
        int domesticCompetitionId;
        string clubName;
        int squadSize;
        float averageAge;
        string stadiumName;
        string coachAnme;
        Player players[];
        int numberOfPlayers;
        string lineup;
    public:
        Club(int clubId,domesticCompetitionId,string clubName,squadSize,averageAge)
        void setPlayers(Player players2[],int numberPlayers);
        void showBestPlayers();
        void sortPlayers();
        string getCoachName();
        float getAverageAge();
        void setLineup(gameLineup gameLineups[]);
        void loadData();
};
#endif