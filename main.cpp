#include <iostream>
#include "structs.h"
#include "Player.h"
#include "Enemy.h"

#define _ENEMY_HEALT_ 50
#define _Q_HIT_ 30
#define _W_HIT_ 50
#define _E_HIT_ 70



using namespace std;
int menu(Player &player,Enemy &enemy){
    string monsterName = enemy.getEnemyName();
    char modeType;
    cout << "\nYapabileceklerin\nQ'yu kullan<q>\nW'yu kullan<w>\nE'yi kullan<e>\nSecimin<q-w-e>:";
    cin >> modeType;
    int q,w,e,enemyDamage;
    if(modeType == 'q' || modeType == 'Q'){
        q = player.useQ();
        enemy.gDamage(q);
        enemyDamage = enemy.damageHard();
        player.gDamage(enemyDamage);
        cout << "\n"<< monsterName << "'a " << q << " hasar verdin!!" << endl;
        if (enemy.live() == false){
            cout << monsterName <<" OLDU!\n" << endl;
            return 0;
        }
        else if (enemy.live() == true)
        {
            cout << "Verdigin Hasar Yeterli Olmadi!!\n"<< monsterName << "'un Cani :" << enemy.getHealt() << endl;            cout << "Sira " << monsterName << "'ta!\nSana Saldırıyor ve " << enemyDamage << " hasar veriyor!\nSenin Canin : " << player.getHealt() << endl;
            if (player.live() == false)
            {
                cout << monsterName <<" Seni Hakladi!\n";
                return 0;
            }
            menu(player,enemy);
        }
    }
    else if (modeType == 'w' || modeType == 'W')
    {
        w = player.useW();
        enemy.gDamage(w);
        enemyDamage = enemy.damageHard();
        player.gDamage(enemyDamage);
        cout << "\n"<< monsterName << "'a " << w << " hasar verdin!!" << endl;
        if (enemy.live() == false){
            cout << monsterName <<" OLDU!\n" << endl;
            return 0;
        }
        else if (enemy.live() == true)
        {
            cout << "Verdigin Hasar Yeterli Olmadi!!\n"<< monsterName << "'un Cani :" << enemy.getHealt() << endl;            cout << "Sira " << monsterName << "'ta!\nSana Saldırıyor ve " << enemyDamage << " hasar veriyor!\nSenin Canin : " << player.getHealt() << endl;
            if (player.live() == false)
            {
                cout << monsterName << " Seni Hakladi!\n";
                return 0;
            }
            menu(player,enemy);

        }

    }
    else if (modeType == 'e' || modeType == 'E')
    {
        e = player.useE();
        enemy.gDamage(e);
        enemyDamage = enemy.damageHard();
        player.gDamage(enemyDamage);
        cout << "\n"<< monsterName << "'a " << e << " hasar verdin!!" << endl;
        if (enemy.live() == false){
            cout << monsterName <<" OLDU!\n" << endl;
            return 0;
        }
        else if (enemy.live() == true)
        {
            cout << "Verdigin Hasar Yeterli Olmadi!!\n"<< monsterName << "'un Cani :" << enemy.getHealt() << endl;
            cout << "Sira " << monsterName << "'ta!\nSana Saldırıyor ve " << enemyDamage << " hasar veriyor!\nSenin Canin : " << player.getHealt() << endl;

            if (player.live() == false)
            {
                cout << monsterName << " Seni Hakladi!\n";
                return 0;
            }
            menu(player,enemy);
        }

    }
    else {
        cout << "Ne Yapmaya Calisiyorsun !" << monsterName << " sana saldiriyor!!";
        menu(player,enemy);
    }
}

int main() {
    Grott boo;
    Player myPlayer(boo.qHit,boo.wHit,boo.eHit, true);
    Enemy myEnemy(boo.healt,boo.name);
    string monsterName = boo.name;
    cout << "Ormanin Karanliginda Ilerliyordun aniden onune kornuc bir " << monsterName << " cikti..\n\n";
    menu(myPlayer,myEnemy);



    return 0;
}