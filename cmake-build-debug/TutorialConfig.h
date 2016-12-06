#include <string>
#include <stdlib.h>
#include <time.h>

class Player {
private:
    int qHit,wHit,eHit;
    bool def = false;
public:
    Player(int qMaxHit,int wMaxHit,int eMaxHit,bool def);
    int useQ();
    int useW();
    int useE();
};
