#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Player.h"
#include "NPC.h"
#include "MrBeast.h"
#include "RabbitHole.h"
#include "GreatVines.h"
#include "SilverPhish.h"

using namespace std;

Player* player = new Player();

void divide() {
	cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

bool choice() {
	cout << " (Yes/No)" << endl;

	string resp; getline(cin, resp);

	if (resp == "Save") {
		player->saveData();
		cout << "\tProgress Saved. Now please choose Yes or No..." << endl;
		getline(cin, resp);
	}

	if (resp != "Yes") return false;

	return true;
}

void intro() {
	string name, password;

	cout << "\tWelcome Player! What is your name?" << endl;
	getline(cin, name);

	cout << "\tPlease set a passoword " << name << endl;
	getline(cin, password);

	player = new Player(name, password);
}

void info() {
	cout << "\tPlease read the following before continuing..." << endl;
	cout << endl << "\tDisclaimer: The following, though may be reminiscent of real life people or things are not. This is purely a work of fiction." << endl;

	cout << endl << "\tThe Metaverse is a dangerous place. Filled with deadly distractions and hidden glitches. Invisible to the naked Oculus, these threats could crash your session, or worse destroy your whole profile. Can you traverse the dangerous trails of the Metaverse to order Panda Express in time to feed your metamate." << endl;

	cout << endl << "\tYour round indicates how close you are to Panda Express. You win when you reach round 12." << endl;

	cout << endl << "\tYour battery round, is analogous to your life. It starts at 30 decreases every round and if defeated by a threat. You can recharge your device but your metamate will still grow hungry. Note that running out of battery will delete all your unsaved data." << endl;
	
	cout << endl << "\tYour metamate's hunger starts at 0 and goes till 10." << endl;

	cout << endl << "\tIf you don't reach round 12 before your metamate's hunger reaches 10, you loose." << endl;

	cout << endl << "\tYou may choose to save your progress before the battery runs out, but that costs battery too." << endl;

	cout << endl << "\tYou will have to interact with various phenomenon in the metaverse, some will help you reach your destination more quickly, but some will delay you and will cause you to loose battery." << endl;

	cout << endl << "\tMay the odds be ever in your favor." << endl;

}	

void clear() {
	ofstream file;
	file.open("Data.csv");
	file << "";
	file.close();
}

bool checkBattery() {
	if (!player->isAlive()) {
		delete player;
		divide();
		cout << "Battery has run out!";
		divide();
		return false;
	}

	if (player->getBattery() <= 8)
		cout << "Low Battery!" << endl;

	return true;
}

void dialogue(NPC& guy) {
	cout << "Hello good sir, I am " << guy.getName() << " What is yours?" << endl;
	string name; getline(cin, name);

	cout << "I am a " << guy.getRole() << ". ";

	if (guy.getRole() == "Guide") {
		cout << "Would like to know a secret passage to Panda?";
		if (!choice()) return;

		cout << "Okay then..." << endl;
		int num = rand() % 3;
		while (num-- > 0) player->incRound();
	}
}

bool odds(int i, int j) {
	int num = rand() % j;
	if (num > j - i)
		return true;
	return false;
}

void gameplay() {
	cout << "Are you ready?";
	if(!choice()) return;
	

	for (; checkBattery(); player->incRound(), player->incHunger(), player->decBattery(2)) {
		divide();
		player->print();
		cout << "When asked a Yes or No question, Typing in \"Save\" will save your progress" << endl;
		cout << "Your User Name is: " << player->getUserName() << endl;
		cout << endl;

		int interaction = rand()%5;
		Threat* hole = new Threat();
		bool normalThreat = false;

		if (player->getRound() >= 12) {
			divide();
			cout << endl << "Wait! There it is! Panda Express!!! You've found!" << endl << endl;
			cout << "YOU'VE WON!!!!" << endl;
			divide();
			return;
		}

		if (player->getMetamateHunger() >= 10) {
			divide();
			cout << endl << "Oh Shoot, I think your metamate just died..." << endl << endl;
			cout << "F" << endl;
			divide();
			return;
		}

		switch (interaction) {
			case 0: // NPC
				{
					NPC* guide = new NPC("Marcos", "Guide", player->getRound());
					dialogue(*guide);
				}
				break;
			case 1: // RabbitHole
				{
					hole = new RabbitHole(player->getRound());
					normalThreat = true;
				}
				break;
			case 2: // GreatVines
				{
					hole = new GreatVines(player->getRound());
					normalThreat = true;
				}
				break;
			case 3: // SilverPhish
				{
					hole = new SilverPhish(player->getRound());
					normalThreat = true;
				}
				break;
			case 4: // MrBeast
				{
					MrBeast* beast = new MrBeast(player->getRound());
					cout << beast->getDescrip();
					cout << " Would you like to go deeper?";
					if (!choice()) continue;
					bool escape = beast->tryEscape();
					if (escape) {
						cout << "You've escaped Mr. Beast! No Way!" << endl;
						continue;
					}
					else {
						cout << endl << "Oh oh, You've been devovoured by Mr. Beast! GAME OVER" << endl;
						player->decBattery(beast->getDamage());
						return;
					}
				}
				break;
		}

		if (normalThreat) {
			cout << hole->getDescrip();
			cout << " Would you like to go deeper?";
			if (!choice()) continue;
			bool escape = odds(12 - player->getRound(), 12); //1 in 4
			if (escape) {
				cout << "You've escaped the threat! Nice!" << endl;
				player->incBattery();
				continue;
			}
			else {
				cout << endl << "Oh oh, you got distracted!" << endl;
				player->decBattery(hole->getDamage());
			}
		}
	}


}

int main() {

		divide();
	intro(); 
		divide();
	info();
		divide();
	gameplay();
		divide();

	//clear(); // For Tests
	return 0;
}