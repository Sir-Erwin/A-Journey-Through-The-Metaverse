#ifndef SILVER_FISH_H_
#define SILVER_FISH_H_

#include <iostream>
#include <cstdlib>
#include "Threat.h"

using namespace std;

class SilverPhish : public Threat{
	private:
		int level;
		int speed;

	public:
		SilverPhish(int round) {
			this->level = round;
			this->speed = round % 5;
			this->setDamage(level + speed);
			this->setDescrip("The world is a nasty place... But you can help fix it! From exiled Nigerian princes to high tech solutions to solving the water crisis in Wakanda, People Need YOUR Help!");
		}

		int getLevel() {
			return level;
		}

		void setLevel(int lvl) {
			level = lvl;
		}

		int getSpeed() {
			return speed;
		}

		void setSpeed(int spd) {
			speed = spd;
		}

};

#endif
