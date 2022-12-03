#ifndef GREAT_VINES_H_
#define GREAT_VINES_H_

#include <iostream>
#include "Threat.h"

using namespace std;

class GreatVines : public Threat{
    private:
        string type;
        string location;

    public:
        GreatVines(string type, string location, int damage) : Threat(damage) {
            this->type = type;
            this->location = location;
            this->setDescrip("Vine is back. Although most people thought that mainstream social media like Instagram, TicTok, and Reddit had destroyed Vine, it has come back with funnier content and a ferocious community.");
        }

        GreatVines(int round) {
            this->type = "Meme";
            this->location = "Vine";
            this->setDescrip("Vine is back. Although most people thought that mainstream social media like Instagram, TicTok, and Reddit had destroyed Vine, it has come back with funnier content and a ferocious community.");
            this->setDamage(round * 3);
        }

        string getType(){
            return type;
        }

        void setType(string type){
            this->type = type;
        }

        string getLoction(){
            return location;
        }

        void setLocation(string location){
            this->location = location;
        }
};

#endif