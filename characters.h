#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class BaseCharacter{
    string name;
    int health;
    int level;
    
    int skill1Power;
    string skill1Name;
    
    int skill2Power;
    string skill2Name;
    
    int energyCost1;
    int energyCost2;;
    int energyLeft;
    string energyName;

    public:
        BaseCharacter();
        BaseCharacter( string n, int h, int l, string sN1, int a1, string sN2, int a2 , string eN, int e, int e1, int e2 ) {name = n; health = h; level = l; skill1Name = sN1; skill1Power = a1; skill2Name = sN2; skill2Power = a2; energyName = eN, energyLeft = e; energyCost1 = e1; energyCost2 =e2; }
        BaseCharacter( string n, int h, int l, string sN1, int a1, string sN2, int a2 ) {name = n; health = h; level = l; skill1Name = sN1; skill1Power = a1; skill2Name = sN2; skill2Power = a2; }

        void setName(string n) {name=n;}
        string getName() {return name;}
        void setHealth( int h ) { health = h; }
        int getHealth() { return health; }
        void setLevel( int l ) { level = l; }
        int getLevel() {return level; }
        
        void setAttack1(int a1) {skill1Power=a1;}
        int attack1() {return skill1Power;}
        void setAttack1Name(string n1) {skill1Name = n1;}
        string getSkill1Name() {return skill1Name;}

        void setAttack2(int a2) {skill2Power=a2;}
        int attack2() {return skill2Power;}
        
        void setAttack2Name(string n2) {skill2Name = n2;}
        string getSkill2Name() {return skill2Name;}

        void setEnergyIncrease(int a) {energyLeft = energyLeft+5;}
        void setEnergy( int e, int eC) {energyLeft = e - eC; }
        int getEnergy() {return energyLeft;}
        void setEnergyToDefault(int e) {energyLeft=e;}

        void setEnergyCost1(int A) { energyCost1 = A/4 ;}
        int getEnergyCost1() {return energyCost1;}

        void setEnergyCost2(int A) { energyCost2 = A/4 ;}
        int getEnergyCost2() {return energyCost2;}

        string getEnergyName() {return energyName;}

        void printStats() {cout << "Health: " << getHealth() << endl << "Level: " << getLevel() << endl << "Skill 1 is: " << getSkill1Name() << " with " << attack1() << " damage, "<< endl << "Skill 2 is: " << getSkill2Name() << " with " << attack2() << " damage" << endl;}

};

class Chemist : public BaseCharacter{

    public:
        Chemist(string n, int h, int l, string sN1, int s1, string sN2, int s2, string eN, int e, int e1, int e2) : BaseCharacter(n, h, l, sN1, s1, sN2, s2, eN, e, e1 , e2) {;}

};

class Warrior : public BaseCharacter{

    public:
        Warrior(string n, int h, int l, string sN1, int s1, string sN2, int s2, string eN, int e, int e1, int e2) : BaseCharacter(n, h, l, sN1, s1, sN2, s2, eN, e, e1 , e2) {;}

};

class Wizard : public BaseCharacter{

    public:
        Wizard(string n, int h, int l, string sN1, int s1, string sN2, int s2, string eN, int e, int e1, int e2) : BaseCharacter(n, h, l, sN1, s1, sN2, s2, eN, e, e1 , e2) {;}

};

class Alien : public BaseCharacter{
    string skill3Name = "Healing Power"; 
    int skill3 = 20;

    public:
        Alien( string n, int h, int l, string sN1, int s1, string sN2, int s2, int s3 ) : BaseCharacter(n, h, l, sN1, s1, sN2, s2) {skill3 = s3;}
        string getSkill3Name() {return skill3Name;}
        int getSkill3() {return skill3;}

};

#endif