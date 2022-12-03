#ifndef NPC_H_
#define NPC_H_

#include <iostream>

using namespace std;

class NPC{
    private: 
        string name;
        string role;
        int level;
    public:
        NPC(string name, string role, int level) {
            setName(name);
            setRole(role);
            setLevel(level);
        }

        NPC() {
            setName("Default NPC");
            setRole("Default Role");
            setLevel(1);
        }

        string getName() {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }

        string getRole() {
            return role;
        }

        void setRole(string role) {
            this->role = role;
        }

        int getLevel() {
            return level;
        }

        void setLevel(int level) {
            this->level = level;
        }

};

#endif
