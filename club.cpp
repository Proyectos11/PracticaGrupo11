#include "club.hpp"
Club::Club(int clubId,string domesticCompetitionId,
        string clubName,int squadSize,float averageAge,string stadiumName){
    this->clubId=clubId;
	this->domesticCompetitionId=domesticCompetitionId;
	this->clubName=clubName;
	this->squadSize=squadSize;
	this->averageAge=averageAge;
	this->stadiumName=stadiumName;
	numberOfPlayers=0;
    }
void Club::setPlayers(vector<Player> players2){
	for(int i=0;i<players2.size();i++){
		int a=players2.at(i).getCurrentClubId();
        if(a==clubId && players2.at(i).getLastSeason()){
            players.push_back(players2.at(i));
            numberOfPlayers++;
        }
    }
    cout<<"Number of players: "<<numberOfPlayers<<", Squad Size: "<<squadSize<<endl;
    //for(int i=0;i<players.size();i++){
    //	cout<<i+1<<"."<<players.at(i).getName()<<" "<<players.at(i).getLastSeason()<<endl;
	//}
}
void Club::showBestPlayers(){
    //Player bestPlayers[10];
    //for(int i=0;i<numberOfPlayers;i++){
    //    if(i<10){
    //        bestPlayers[i]=players[i];
    //    }
    //    else{
            //Comprobar cual es el de minimo precio y compararlo
    //    }

    //}
}
void Club::sortPlayers(){
	int election;
    float minimum,maximum;
    cout<<"SORT PLAYERS"<<endl<<"-----------"<<endl;
    cout<<"1.Nationality"<<endl<<"2.Market Value"<<"3.";
    cin>>election;
    switch(election){
        case 1:
        case 2:
            cout<<"Introduce the minimum market value: ";
            cin>>minimum;
            cout<<"Introduce the maximum market value: ";
            cin>>maximum;
            cout<<"Players with market Value between "<<minimum<<"$ and "<<maximum<<"$: ";
            for(int i=0;i<numberOfPlayers;i++){
                if(minimum<players[i].getMarketValue()<maximum ){
                    cout<<players[i].toString()<<endl;
                }
            }
            break;

    }
}
string Club::getCoachName(){
	return coachName;
}
float Club::getAverageAge(){
	return averageAge;
}
string Club::getClubName(){
	return clubName;
}
vector<Player> Club::getPlayers(){
	return players;
}