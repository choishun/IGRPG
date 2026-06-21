#pragma once
class player {
private:
	int hp=100;
	int atk=30;
	std::string name;
public:
	void setName(std::string);
	void setHp(int);
	void setAtk(int);
	int getHp();
	int getAtk();
	std::string getName();
	bool pyAlive();
};