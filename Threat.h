#ifndef THREAT_H_
#define THREAT_H_

#include <iostream>
#include "NPC.h"

using namespace std;

class Threat : public NPC{
private:
	int damage;
	string description = "Dangerous";

public:
	Threat() {
		damage = 0;
	}

	Threat(int damage) {
		this->damage = damage;
	}

	int getDamage() {
		return damage;
	}

	void setDamage(int dmg) {
		damage = dmg;
	}

	string getDescrip() {
		return description;
	}

	void setDescrip(string desc) {
		description = desc;
	}

};

#endif
