#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "date.hpp"
using namespace std;
class Player{
    private:
        int playerId;
        int currentClubId;
        string firstName;
        string lastName;
        string name;
        int lastSeason;
        string countryOfBirth;
        Date dateOfBirth;
        string position;
        string subPosition;
        string currentClubName;
        float marketValue;
        float higuestMarketValue;
    public:
        int getCurrentClubId();
        void loadData();

};
#endif