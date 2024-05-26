#include "gameLineup.hpp"
//Pablo de la Iglesia
gameLineup::gameLineup(string gameLineupId, Date date, int gameId, int playerId, int clubId, 
        string playerName, string type, string position, int number){
    this->gameLineupId=gameLineupId;
    this->date=date;
    this->gameId=gameId;
    this->playerId=playerId;
    this->clubId=clubId;
    this->playerName=playerName;
    this->type=type;
    this->position=position;
    this->number=number;
}
//Pablo de la Iglesia
int gameLineup::getClubId(){
    return clubId;
}
//Pablo de la Iglesia
string gameLineup::getPlayerName(){
    return playerName;
}
//Pablo de la Iglesia
int gameLineup::getGameId(){
    return gameId;
}
//Pablo de la Iglesia
string gameLineup::getPosition(){
    return position;
}
//Pablo de la Iglesia
string gameLineup::getType(){
    return type;
}
//Pablo de la Iglesia
Date gameLineup::getDate(){
    return date;
}
//Pablo de la Iglesia
int gameLineup::getPlayerId(){
    return playerId;
}
//Pablo de la Iglesia
string gameLineup::toString(){
    return to_string(number)+" "+playerName+" "+position;
}
//Pablo de la Iglesia
int gameLineup::getNumber(){
    return number;
}