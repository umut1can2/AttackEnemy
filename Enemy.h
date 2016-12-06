#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string>
class Enemy {
private:
    int healt;
    int lastDamage;
    bool checkLive = true;
    std::string enemyName;
public:
    Enemy(int healt,std::string enemyName);
    void gDamage(int dam);
    int getHealt();
    bool live();
    int damageHard();
    int damageNormal();
    int damageEasy();
    int getLastDamage();
    std::string getEnemyName();
};



