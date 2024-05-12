#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "club.hpp"
#include "player.hpp"
#include "gameLineup.hpp"
using namespace std;
void cargaDatos(vector<Club> &clubs, vector<Player> &players, vector<gameLineup> &lineup);
Date convertString(string word);
int main(){
    vector<gameLineup> lineups;
    vector<Player> players;
	vector<Club> clubs;
    cargaDatos(clubs,players,lineups);
    for(int i=0;i<lineups.size();i++){
        if(lineups.at(i).getClubId()==418){
            cout<<lineups.at(i).getPlayerName()<<endl;
        }
    }
}
Date convertString(string word2){
    Date date;
    stringstream strstr(word2);
		string word="  ";
		int z=0;
	while(getline(strstr,word,'-')){
        if(z==0){
            date.year=stoi(word);
        }
        else if(z==1){
            date.month=stoi(word);
        }
        else{
            date.day=stoi(word);
        }
        z++;
    }
    return date;
}
void cargaDatos(vector<Club> &clubs, vector<Player> &players, vector<gameLineup> &lineups){
    ifstream infile("clubs.csv");
    string line = "   "; //comillas vacias para guardar las lineas
    vector<string> datos_csv;
    //while para ir guardando los datos
    while (getline(infile, line))
    {
        stringstream strstr(line);
        string word="  ";//tambien para recorrer
        while(getline(strstr,word,','))
        {
            //como le vamos ir agregando los datos
            datos_csv.push_back(word);
        }
    }
    string averageAge;
    cout<<"Empezamos a guardar clubs"<<endl;
    for(int i=1; i<427;i++)
    {
    	//cout<<"Guardando fila "<<i<<endl;
    	averageAge=datos_csv.at(23+17*(i-1));
    	if(averageAge==""){
    		averageAge="0";
		}
    	//cout<<"Club Id: "<<datos_csv.at(17*i)<<" Domestic Competition: "<<datos_csv.at(20+17*(i-1))<<" Club Name: "<<datos_csv.at(19+17*(i-1))<<endl<<" Squad Size: "<<datos_csv.at(22+17*(i-1))<<" Average Age: "<<datos_csv.at(23+17*(i-1))<<" Stadium name: "<<datos_csv.at(27+17*(i-1))<<endl;
    	Club club(stoi(datos_csv.at(17*i)),datos_csv.at(20+17*(i-1)),datos_csv.at(19+17*(i-1)),stoi(datos_csv.at(22+17*(i-1))),stoi(averageAge),datos_csv.at(27+17*(i-1)));
    	clubs.push_back(club);
    }
    infile.close();
    cout<<"Acabamos de guardar Clubs"<<endl;
    ifstream infile2("players.csv");
    line="  ";
    datos_csv.clear();
    while(getline(infile2,line)){
    	stringstream strstr(line);
    	string word="  ";
    	while(getline(strstr,word,',')){
    		datos_csv.push_back(word);
		}
	}
    cout<<"Empezamos a guardar players"<<endl;
	for(int i=1;i<30513;i++){
		//int playerId, int currentClubId, string firstName, string lastName, string name, int lastSeason, string countryOfBirth, Date dateOfBirth, string position, string subPosition,
		// string currentClubName, float marketValue, float higuestMarketValue
		
		//cout<<"Guardando fila"<<i<<endl;
		//cout<<"Player Id: "<<datos_csv.at(24*i)<<" Current Club Id: "<<datos_csv.at(29+24*(i-1))<<" First Name: "<<datos_csv.at(25+(24*(i-1)))<<" Last name: "<<datos_csv.at(26+(24*(i-1)))<<" Name: "<<datos_csv.at(27+(24*(i-1)))<<endl;
		//cout<<"Last Season: "<<datos_csv.at(28+(24*(i-1)))<<" Country Of Birth: "<<datos_csv.at(31+(24*(i-1)))<<" Date of Birth: "<<datos_csv.at(34+(24*(i-1)))<<" Position: "<<datos_csv.at(36+(24*(i-1)))<<endl;
		//cout<<"SubPosition: "<<datos_csv.at(35+(24*(i-1)))<<" Current Club Name: "<<datos_csv.at(44+(24*(i-1)))<<" MarketValue: "<<datos_csv.at(45+(24*(i-1)))<<" Highest Market Value: "<<datos_csv.at(46+(24*(i-1)))<<endl;		
		string marketValue, higuestMarketValue;
		marketValue=datos_csv.at(45+(24*(i-1)));
		higuestMarketValue=datos_csv.at(46+(24*(i-1)));
		if(marketValue==""){
			marketValue="0";
		}
		if(higuestMarketValue==""){
			higuestMarketValue="0";
		}
		Player player(stoi(datos_csv.at(24*i)),stoi(datos_csv.at(29+(24*(i-1)))),
            datos_csv.at(25+(24*(i-1))),datos_csv.at(26+(24*(i-1))),datos_csv.at(27+(24*(i-1))),
            stoi(datos_csv.at(28+(24*(i-1)))),datos_csv.at(31+(24*(i-1))),convertString(datos_csv.at(34+(24*(i-1)))),
            datos_csv.at(36+(24*(i-1))),datos_csv.at(35+(24*(i-1))),datos_csv.at(44+(24*(i-1))),
            stoi(marketValue),stoi(higuestMarketValue));
		players.push_back(player);	
	}
    infile2.close();
    cout<<"Acabamos de guardar players"<<endl;
    ifstream infile3("game_lineups.csv");
    line="  ";
    datos_csv.clear();
    while(getline(infile3,line)){
    	stringstream strstr(line);
    	string word="  ";
    	while(getline(strstr,word,',')){
    		datos_csv.push_back(word);
		}
	}
    cout<<"Empezamos a guardar Lineups"<<endl;
    //2145223
    string number;
    for(int i=1;i<2145223;i++){
        //cout<<"Linea "<<i<<endl;
        /**
         * string gameLineupsId, Date date, int gameId, int playerId, int clubId, 
            string playerName, string type, string position, int number
        */
        //cout<<"String ID: "<<datos_csv.at(10*i)<<" Date: "<<datos_csv.at(11+10*(i-1));
        //cout<<" Int gameID: "<<datos_csv.at(12+10*(i-1))<<endl<<" Int playerId: "<<datos_csv.at(13+10*(i-1));
        //cout<<" Int clubId: "<<datos_csv.at(14+10*(i-1))<<" String playerName: "<<datos_csv.at(15+10*(i-1))<<endl;
        //cout<<"String type: "<<datos_csv.at(16+10*(i-1))<<" String position: "<<datos_csv.at(17+10*(i-1));
        //cout<<" Int number: "<<datos_csv.at(18+10*(i-1))<<endl;
        number=datos_csv.at(18+10*(i-1));
        if(number=="-"){
            number="0";
        }
        gameLineup lineup(datos_csv.at(10*i),convertString(datos_csv.at(11+10*(i-1))),stoi(datos_csv.at(12+10*(i-1))),
            stoi(datos_csv.at(13+10*(i-1))),stoi(datos_csv.at(14+10*(i-1))),
            datos_csv.at(15+10*(i-1)),datos_csv.at(16+10*(i-1)),datos_csv.at(17+10*(i-1)),
            stoi(number));
        lineups.push_back(lineup);
    }
    infile3.close();
    cout<<"Acabamos de guardar Lineups"<<endl;
}