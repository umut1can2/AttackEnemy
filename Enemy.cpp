//
// Created by ticop on 06.12.2016.
//

#include "Enemy.h"

Enemy::Enemy(int healt,std::string enemyName) {

    this->healt = healt;
    this->enemyName = enemyName;
}

void Enemy::gDamage(int dam) {
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

int Enemy::getHealt() {
    return this->healt;
}

bool Enemy::live() {
    if (checkLive == true)
    {
        return true;
    }
    else if(checkLive == false)
    {
        return false;
    }
}

int Enemy::damageEasy() {
    srand( time(NULL) );

    lastDamage = rand() % 15 + 1;
    return lastDamage;
}

int Enemy::damageNormal() {
    srand( time(NULL) );
    lastDamage = rand() % 25 + 1;
    return lastDamage;
}

int Enemy::damageHard() {
    srand( time(NULL) );

    lastDamage = rand() % 40 + 1;
    return lastDamage;
}

int Enemy::getLastDamage() {
    return lastDamage;
}

std::string Enemy::getEnemyName() {
    return this->enemyName;
}