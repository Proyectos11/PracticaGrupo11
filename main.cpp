#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "club.hpp"
#include "player.hpp"
using namespace std;
void cargaDatos(vector<Club> &clubs, vector<Player> &players);

int main(){
    vector<Player> players;
	vector<Club> clubs;
    cargaDatos(clubs,players);
    for(int i=0;i<clubs.size();i++){
    	clubs.at(i).setPlayers(players);
		if(clubs.at(i).getClubName()=="Real Madrid Club"){
			cout<<"Real Madrid: "<<endl;
			for(int j=0;j<clubs.at(i).getPlayers().size();j++){
				cout<<clubs.at(i).getPlayers().at(j).getName()<<endl;
			}
		}	
	}
}
void cargaDatos(vector<Club> &clubs, vector<Player> &players){
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
	for(int i=1;i<30513;i++){
		//int playerId, int currentClubId, string firstName, string lastName, string name, int lastSeason, string countryOfBirth, Date dateOfBirth, string position, string subPosition,
		// string currentClubName, float marketValue, float higuestMarketValue
		
		//cout<<"Guardando fila"<<i<<endl;
		//cout<<"Player Id: "<<datos_csv.at(24*i)<<" Current Club Id: "<<datos_csv.at(29+24*(i-1))<<" First Name: "<<datos_csv.at(25+(24*(i-1)))<<" Last name: "<<datos_csv.at(26+(24*(i-1)))<<" Name: "<<datos_csv.at(27+(24*(i-1)))<<endl;
		//cout<<"Last Season: "<<datos_csv.at(28+(24*(i-1)))<<" Country Of Birth: "<<datos_csv.at(31+(24*(i-1)))<<" Date of Birth: "<<datos_csv.at(34+(24*(i-1)))<<" Position: "<<datos_csv.at(36+(24*(i-1)))<<endl;
		//cout<<"SubPosition: "<<datos_csv.at(35+(24*(i-1)))<<" Current Club Name: "<<datos_csv.at(44+(24*(i-1)))<<" MarketValue: "<<datos_csv.at(45+(24*(i-1)))<<" Highest Market Value: "<<datos_csv.at(46+(24*(i-1)))<<endl;
		Date dateOfBirth;
		string dateBirth=datos_csv.at(34+(24*(i-1)));
		stringstream strstr(dateBirth);
		string word="  ";
		int z=0;
		while(getline(strstr,word,'-')){
			if(z==0){
				dateOfBirth.year=stoi(word);
			}
			else if(z==1){
				dateOfBirth.month=stoi(word);
			}
			else{
				dateOfBirth.day=stoi(word);
			}
			z++;
		}
		string marketValue, higuestMarketValue;
		marketValue=datos_csv.at(45+(24*(i-1)));
		higuestMarketValue=datos_csv.at(46+(24*(i-1)));
		if(marketValue==""){
			marketValue="0";
		}
		if(higuestMarketValue==""){
			higuestMarketValue="0";
		}
		Player player(stoi(datos_csv.at(24*i)),stoi(datos_csv.at(29+(24*(i-1)))),datos_csv.at(25+(24*(i-1))),datos_csv.at(26+(24*(i-1))),datos_csv.at(27+(24*(i-1))),stoi(datos_csv.at(28+(24*(i-1)))),datos_csv.at(31+(24*(i-1))),dateOfBirth,datos_csv.at(36+(24*(i-1))),datos_csv.at(35+(24*(i-1))),datos_csv.at(44+(24*(i-1))),stoi(marketValue),stoi(higuestMarketValue));
		players.push_back(player);	
	}
}