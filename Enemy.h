#include <stdlib.h>
#include <time.h>
class Enemy {
private:
    int healt;
    int lastDamage;
    bool checkLive = true;
public:
    Enemy(int healt);
    void gDamage(int dam);
    int getHealt();
    bool live();
    int damageHard();
    int damageNormal();
    int damageEasy();
    int getLastDamage();
};



