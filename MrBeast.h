#ifndef MR_BEAST_H_
#define MR_BEAST_H_

#include <iostream>
#include <cstdlib>
#include "Threat.h"

using namespace std;

class MrBeast : public Threat {
    private:
        int bar;
    public:
        MrBeast(int round){
            bar = rand() % 10;
            this->setDescrip("Mr. Beast is a famous YouTuber. Probably the most popular in the Metaverse.");
            this->setDamage(round * 100);
        }

        int getBar() {
            return bar;
        }

        bool tryEscape(){
            int num = rand() % 5;
            if(num < bar)
                return false; 
            return true;
        }
};

#endif