#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <QString>
/*----------------------------------------
	Author: Grant Harris
	CIS 330; Group Project
	Created Feb 12, 2014
//----------------------------------------*/

class Player
{

	public:
		Player();
		Player(std::string playerName);
		~Player();
		//void printStats();
		void setWins(int x);
		void setLosses(int x);
		void setRank(int x);
		void setSecs(int x);
		void setMins(int x);
		int getMins();
		int getSecs();
		std::string getName();
		void setName(std::string);
		int getTimePlayed();
		int getWins();
		int getLosses();
		int getRank();
        QString toQString();

		std::string toString(Player playerName);
	private:
		int timePlayed, wins, losses, rank, mins, secs;
		std::string name;
};


#endif
