#include <string>
#include <stdlib.h>
#include <time.h>

class Player {
private:
    int qHit,wHit,eHit;
    bool def = false;
    int healt = 100;
    bool checkLive;
public:
    Player(int qMaxHit,int wMaxHit,int eMaxHit,bool def);
    int useQ();
    int useW();
    int useE();
    int gDamage(int dam);
    int getHealt();
    bool live();
};
