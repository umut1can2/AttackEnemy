#include "Player.h"

Player::Player(int qMaxHit, int wMaxHit, int eMaxHit,bool def) {
    srand(time(NULL));
    this->qHit = qMaxHit;
    this->wHit = wMaxHit;
    this->eHit = eMaxHit;
    this->def = def;
}

int Player::useQ() {
    int damage = 0;
    if (def == true)
    {
        int d = rand() % qHit + 1;
        d = d / 2;
        damage = rand() % qHit + 1;
        damage = damage - d;
    }
    else if (def == false)
    {
        damage = rand() % qHit + 1;
    }

    return damage;
}

int Player::useW() {
    int damage = 0;

    if (def == true)
    {
        int d = rand() % wHit + 1;

        d = d / 2;
        damage = rand() % wHit + 1;
        damage = damage - d;
    }
    else if (def == false)
    {
        damage = rand() % wHit + 1;
    }

    return damage;
}

int Player::useE()
{
    int damage = 0;

    if (def == true)
    {
        int d = rand() % eHit + 1;
        d = d / 2;
        damage = rand() % eHit + 1;
        damage = damage - d;
    }
    else if (def == false)
    {
        damage = rand() % eHit + 1;
    }

    return damage;
}

int Player::gDamage(int dam) {
    this->healt = this->healt - dam;
    if (healt <= 0)
    {
        this->checkLive = false;
        this->healt = 0;
    }else if(healt >= 1)
    {
        this->checkLive = true;
    }
}

int Player::getHealt() {
    return this->healt;
}

bool Player::live() {
    if (checkLive == true)
    {
        return true;
    }
    else if(checkLive == false)
    {
        return false;
    }
}

int Player::cricticDamage(int useHealt) {
    int cDamage=0;
    int dmg = this->healt - useHealt;
    if(dmg <= 0)
    {
        return 0;
    }
    if(dmg >= 1)
    {
        cDamage = rand() % useHealt + 30;
        this->healt = this->healt - useHealt;
    }
    if (healt <= 0)
    {
        this->checkLive = false;
        this->healt = 0;
    }else if(healt >= 1)
    {
        this->checkLive = true;
    }

    return cDamage;
}