#include <iostream>
#include<string>
#include"player.h"
using namespace std;
void player::setName(string name) {
	this->name=name;
}
void player::setHp(int hp) {
	this->hp = hp;
}
void player::setAtk(int atk) {
	this->atk = atk;
}
int player::getHp() {
	return hp;
}
int player::getAtk() {
	return atk;
}
std::string player::getName() {
	return name;
}
bool player::pyAlive() {
	return this->hp > 0;
}