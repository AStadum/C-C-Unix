#include "Player.h"
#include <iostream>
#include <string>
/*----------------------------------------
	Author: Grant Harris
	CIS 330; Group Project
	Created Feb 12, 2014
//----------------------------------------*/

Player::Player():
timePlayed(0), wins(0), losses(0), rank(0){

}

Player::Player(std::string playername):timePlayed(0), wins(0), losses(0), rank(0), name(playername){
	
}

std::string Player::toString(Player p){


	std::string stats = "";
	stats.append(p.getName());
	stats.append(" ");
	stats.append(std::to_string(p.getWins()));
	stats.append(" ");
	stats.append(std::to_string(p.getLosses()));
	return stats;
	
}
void Player::setWins(int input)
{
	wins = input;
}

void Player::setLosses(int input)
{
	losses = input;
}

void Player::setRank(int input)
{
	rank = input;
}
int Player::getSecs(){
	return secs;
}
int Player::getMins(){
	return mins;
}

void Player::setSecs(int seconds){
	secs = seconds;
}
void Player::setMins(int minutes){
	mins = minutes;
}

std::string Player::getName()
{
	return name;
}
void Player::setName(std::string input){

	name = input;
}

int Player::getWins()
{
	return wins;
}

int Player::getLosses()
{
	return losses;
}

int Player::getRank()
{
	return rank;
}
Player::~Player(){}