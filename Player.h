#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Player{
    private:
        string name;
        string userName;
        int round;
        int battery;
        int metamateHunger;
    public:
        Player() {
            name = "Default";
            userName = "Default";
            round = 0;
            battery = 30;
            metamateHunger = 0;
        }
        Player(string name, string password){
            this->name = name;
            if(password == "")
                genUserName();
            this->userName = name + password;
            round = 0;
            battery = 30;
            metamateHunger = 0;

            if (!loadData()) saveData();
        }

        bool operator!=(Player& obj) {
            bool yes = false;
            if (name != obj.getName()) yes = true;
            if(userName != obj.getUserName()) yes = true;
            if(round != obj.getRound()) yes = true;
            if(battery != obj.getBattery()) yes = true;
            if(metamateHunger != obj.getMetamateHunger()) yes = true;

            return yes;
        }

        string getName(){
            return name;
        }

        void setName(string n){
            name = n;
        }

        void genUserName(){
            string password;
            cout << "Please type in a 4 digit combination for the userName" << endl;
            userName = name+password;
        }

        string getUserName() {
            return userName;
        }

        int getRound(){
            return round;
        }

        void setRound(int lvl){
            round = lvl;
        }

        void incRound() {
            setRound(getRound() + 1);
        }

        int getBattery(){
            return battery;
        }

        void incBattery() {
            battery = (getBattery() + 1);
        }

        void decBattery(int dmg){
            battery -= dmg;
        }

        bool isAlive() {
            if (battery > 0)
                return true;
            return false;
        }

        int getMetamateHunger() {
            return metamateHunger;
        }

        void setMetamateHunger(int hunger) {
            metamateHunger = hunger;
        }

        void incHunger() {
            setMetamateHunger(getMetamateHunger() + 1);
        }

        int getCharger(int chrg){
            metamateHunger += 15;
            battery += 15;
        }

        void saveData(){
            fstream out("Data.csv", fstream::app);

            out << userName << "," << name << "," << round << "," << battery << "," << metamateHunger << "," << endl;

            out.close();
        }

        bool loadData(){
            ifstream inp;
            inp.open("Data.csv");

            Player copy = *this;

            string line, word;
            while (getline(inp, line)) {
                stringstream str(line);
                string userN; getline(str, userN, ',');
                if (userN == userName) {
                    getline(str, name, ',');
                    getline(str, word, ','); round = stoi(word);
                    getline(str, word, ','); battery = stoi(word);
                    getline(str, word, ','); metamateHunger = stoi(word);
                }
            }

            if (*this != copy)
                return true;

            inp.close();
            return false;
        }

        void print() {
            cout << "\tROUND: " << getRound() << endl;
            cout << "\tBattery: " << getBattery() << endl;
            cout << "\tMetamate Hunger: " << getMetamateHunger() << endl;
        }
};

#endif