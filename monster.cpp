#include<iostream>
#include "monster.h"
using namespace std;
void monster::setHp(int hp) {
	this->hp = hp;
}
void monster::setAtk(int atk) {
	this->atk = atk;
}
int monster::getHp() {
	return hp;
}
int monster::getAtk() {
	return atk;
}
bool monster::msAlive() {
	return this->hp > 0;
}
