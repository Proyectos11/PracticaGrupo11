#ifndef GAMELINEUP_HPP
#define GAMELINEUP_HPP
#include "date.hpp"
using namespace std;
class GameLineup{
    private:
        int gameLineupsId;
        Date date;
        int gameId;
        int playerId;
        int clubId;
        string playerName;
        string type;
        string position;
        int number;
    public:
        void loadData();
};
#endif