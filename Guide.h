#ifndef Guide_H_
#define Guide_H_

#include <iostream>
#include "NPC.h"

using namespace std;

class Guide : public NPC {
private:
    int level;
public:
    Guide(string name, int level) : NPC(name) {
        setLevel(level);
    }

    Guide() : NPC(){
        setRole("Default Role");
        setLevel(1);
    }

    int getLevel() {
        return level;
    }

    void setLevel(int level) {
        this->level = level;
    }

};

#endif
