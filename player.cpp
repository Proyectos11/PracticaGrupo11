#include "player.hpp"
//Pablo de la Iglesia
Player::Player(int playerId, int currentClubId, string firstName, string lastName, string name, int lastSeason, 
	string countryOfBirth, Date dateOfBirth, string position, string subPosition, string currentClubName, 
	float marketValue, float higuestMarketValue){
	this->playerId=playerId;
	this->currentClubId=currentClubId;
	this->firstName=firstName;
	this->lastName=lastName;
	this->name=name;
	this->lastSeason=lastSeason;
	this->countryOfBirth=countryOfBirth;
	this->dateOfBirth=dateOfBirth;
	this->position=position;
	this->subPosition=subPosition;
	this->currentClubName=currentClubName;
	this->marketValue=marketValue;
	this->higuestMarketValue=higuestMarketValue;
}
//Pablo de la Iglesia
int Player::getCurrentClubId(){
	return currentClubId;
}
//Pablo de la Iglesia
string Player::getName(){
	return name;
}
//Pablo de la Iglesia
float Player::getMarketValue(){
	return marketValue;
}
//Pablo de la Iglesia
int Player::getLastSeason(){
	return lastSeason;
}
//Pablo de la Iglesia
string Player::toString(){
    return "hola";
}
//Pablo de la Iglesia
int Player::getPlayerId(){
	return playerId;
}
//Pablo de la Iglesia
string Player::getPosition(){
	return position;
}
//Pablo de la Iglesia
string Player::getSubPosition(){
	return subPosition;
}
//Pablo de la Iglesia
int Player::getAge(){
	return 2024-dateOfBirth.year;
}