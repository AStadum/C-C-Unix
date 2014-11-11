#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
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
		void setName(std::string);
		void setSecs(int x);
		void setMins(int x);
		int getMins();
		int getSecs();
		std::string getName();
		int getWins();
		int getLosses();
		int getRank();

		std::string toString(Player playerName);
	private:
		int timePlayed, wins, losses, rank, mins, secs;
		std::string name;
};


#endif
