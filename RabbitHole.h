#ifndef RABBIT_HOLE_H_
#define RABBIT_HOLE_H_

#include <iostream>
#include "Threat.h"

using namespace std;

class RabbitHole : public Threat{
	private:
		int depth;
		string topic;
			
	public:
		RabbitHole(int depth, string topic, int damage) : Threat(damage) {
			this->depth = depth;
			this->topic = topic;
			this->setDescrip("Thoroghness and Kowledge of what's happening around you are amazing qualities. Don't get Left Out, Check This Out! It might yet help you in your quest...");
		}

		RabbitHole(int round) {
			this->depth = round * 2;
			this->topic = "default";
			this->setDescrip("Thoroghness and Kowledge of what's happening around you are amazing qualities. Don't get Left Out, Check This Out!");
			this->setDamage((depth * 2) / 3);
		}

		int getDepth() {
			return depth;
		}

		void setDepth(int dep) {
			depth = dep;
		}

		string getTopic() {
			return topic;
		}

		void setTopic(string top) {
			topic = top;
		}
};

#endif
