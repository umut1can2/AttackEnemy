#include <iostream>
#include "structs.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;
int menu(Player &player,Enemy &enemy){
    bool checkCritic=false;
    string monsterName = enemy.getEnemyName();
    char modeType;

    cout << "\nYapabileceklerin\nQ'yu kullan<q>\nW'yu kullan<w>\nE'yi kullan<e>\nCritic'i kullan<c>\nSecimin<q-w-e-c>:";

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
    else if(modeType == 'c' || modeType == 'C' && checkCritic == false)
    {
        int can;
        cout << "Canin" << player.getHealt() << "\nKullanacagin Can Miktari:";
        cin >> can;
        e = player.cricticDamage(can);
        enemy.gDamage(e);
        enemyDamage = enemy.damageHard();
        player.gDamage(enemyDamage);
        checkCritic = true;
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
    Grott grott;
    Player myPlayer(30,25,45, false);
    Enemy myEnemy(grott.healt,grott.name);
    string monsterName = grott.name;
    cout << "Ormanin Karanliginda Ilerliyordun aniden onune kornuc bir " << monsterName << " cikti..\n\n";
    menu(myPlayer,myEnemy);

//    Boo boo;
//    Player m_player(15,20,58, false);
//    Enemy m_enemy(boo.healt,boo.name);
//    string mName = boo.name;
//    cout << "\nGrottu Oldrurdun ve canin yenilendi. Simdi Kosma vakti Hizli bir sekilde ilerledin ahhhh! karsina kocaman bir " << mName << " cikti..\n\n";
//    menu(m_player,m_enemy);

    return 0;
}