#include "Player.hpp"
#include <iostream>

int main(){


	Player grant("Grant");

	grant.setRank(5);
	grant.setWins(10);
	grant.setLosses(11);

	std::cout<< "Grant's rank: "<< grant.getRank()<< std::endl;
	std::cout<< "Grant's wins: "<< grant.getWins()<< std::endl;
	std::cout<< "Grant's losses: "<< grant.getLosses()<< std::endl;

	std::cout<< "Grant to string:"<<grant.toString(grant);


}