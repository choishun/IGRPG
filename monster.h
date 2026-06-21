#pragma once
class monster{
private:
	int hp;
	int atk;
public:
	void setHp(int);
	void setAtk(int);
	int getHp();
	int getAtk();
	bool msAlive();
};