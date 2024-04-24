#ifndef CLUBNAME_HPP
#define CLUBNAME_HPP
using namespace std;
class ClubGame{
    private:
        int gameId;
        int clubId;
        int ownGoals;
        int opponentId;
        int opponentGoals;
        string hosting;
        bool isWin;
    public:
        void loadData();
};
#endif