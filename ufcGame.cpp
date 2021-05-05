#include <iostream>
#include <string>
#include "characters.h"
#include <time.h>
using namespace std;

// player vs computer function
void Fight(BaseCharacter &player, BaseCharacter &computer){

    int h = player.getHealth();
    int s = player.getEnergy();
    int count=0;
    int currentDamage;
    int choice=0;
    srand(time(0));
    
    while( player.getHealth()>0 && computer.getHealth()>0 ){
        

        if(count==0){
            std::cout << endl << "You have come across " << computer.getName() << " what will you do select 1-2:" << endl;
            std::cout << "1. " << player.getSkill1Name() << endl;
            std::cout << "2. " << player.getSkill2Name() << endl;
            std::cin >> choice;
        }
        else{
            std::cout << computer.getName()  << " dealt " << currentDamage << " damage what will you do select 1-2:" << endl;
            std::cout << "1. " << player.getSkill1Name() << endl;
            std::cout << "2. " << player.getSkill2Name() << endl;
            std::cin >> choice;
        }


        if(choice==1){
            computer.setHealth(computer.getHealth()-player.attack1());
            std::cout << "You dealt " << player.attack1() << " damage." << endl; 
            player.setEnergy(player.getEnergy(),player.getEnergyCost1());
        }
        else{
            computer.setHealth(computer.getHealth()-player.attack2());
            std::cout << "You dealt " << player.attack2() << " damage." << endl;  
            player.setEnergy(player.getEnergy(),player.getEnergyCost2());                     
        }

        if(rand()%2==0){
            player.setHealth(player.getHealth()-computer.attack1());
            currentDamage = computer.attack1();
            computer.setEnergy(computer.getEnergy(),computer.getEnergyCost1());
        }   
        else{
            player.setHealth(player.getHealth()-computer.attack2());
            currentDamage = computer.attack2();
            computer.setEnergy(computer.getEnergy(),computer.getEnergyCost2());
        } 

        std::cout << endl << player.getName() << " health: " << player.getHealth() << ", stamina: " << player.getEnergy() << endl;
        std::cout << computer.getName() << " health: " << computer.getHealth() << ", stamina: " << computer.getEnergy() << endl << endl;

        if(player.getHealth()<=0){
            std::cout << "You are dead. GAME OVER" << endl;           
        }     
        else if(computer.getHealth()<=0){
            std::cout << "You have defeated " << computer.getName() << " congratulations" << endl;
            player.setHealth(h);
            player.setEnergyToDefault(s);
        }

        ++count;        
    }

} 

// player vs player function
void PvP(BaseCharacter *p1, BaseCharacter *p2){

    int count=0;
    int currentDamage;
    int currentDamage2;
    int choice=0;
    int choice2=0;
    
    while( p1->getHealth()>0 && p2->getHealth()>0 ){
        
        std::cin.clear();
        std::cin.sync();

        if(count==0){
            std::cout << endl << "Player 1, it is your turn what will you do!" << endl;
            std::cout << "1. " << p1->getSkill1Name() << endl;
            std::cout << "2. " << p1->getSkill2Name() << endl;
            std::cin >> choice;
        }
        else{
            std::cout << p1->getName() << " it is your turn what will you do select 1-2:" << endl;
            std::cout << "1. " << p1->getSkill1Name() << endl;
            std::cout << "2. " << p1->getSkill2Name() << endl;
            std::cin >> choice;
        }

        if(choice==1){
            p2->setHealth((p2->getHealth())-(p1->attack1()));
            std::cout << p1->getName() << " dealt " << p1->attack1() << " damage." << endl; 
            p1->setEnergy(p1->getEnergy(),p1->getEnergyCost1());
            currentDamage = p1->attack1();
        }
        else{
            p2->setHealth((p2->getHealth())-(p1->attack2()));
            std::cout << p1->getName() << " dealt " << p1->attack2() << " damage." << endl;  
            p1->setEnergy(p1->getEnergy(),p1->getEnergyCost2()); 
            currentDamage = p1->attack2();                    
        }

        std::cout << p2->getName() << " it is your turn what will you do select 1-2:" << endl;
        std::cout << "1. " << p2->getSkill1Name() << endl;
        std::cout << "2. " << p2->getSkill2Name() << endl;
        std::cin >> choice2;


        if(choice2==1){
            p1->setHealth((p1->getHealth())-(p1->attack1()));
            std::cout << p2->getName()<< " dealt " << p2->attack1() << " damage." << endl; 
            p2->setEnergy(p2->getEnergy(),p2->getEnergyCost1());
            currentDamage2 = p2->attack1();
        }
        else{
            p1->setHealth(p1->getHealth()-p2->attack2());
            std::cout << p2->getName() << " dealt " << p2->attack2() << " damage." << endl;  
            p2->setEnergy(p2->getEnergy(),p2->getEnergyCost2());    
            currentDamage2 = p2->attack2();                 
        }

        std::cout << endl << p1->getName() << " health: " << p1->getHealth() << ", " << p1->getEnergyName() << ": " << p1->getEnergy() << endl;
        std::cout << p2->getName() << " health: " << p2->getHealth() << ", " << p2->getEnergyName() << ": " << p2->getEnergy() << endl << endl;

        if(p1->getHealth()<=0){
            std::cout << p2->getName() << " is the winner" << endl;     
        }     
        else if(p2->getHealth()<=0){
            std::cout << p1->getName() << " is the winner" << endl;
        }

        ++count;        
    }

}

// player leveling up function only for story mode
void LevelUp(BaseCharacter &player, BaseCharacter &computer){

    player.setLevel(player.getLevel()+1);
    
    int choice;

    while(choice<1 || choice>4){
        std::cout << endl << "What would you like to upgrade: " << endl;
        std::cout << "1. Health" << endl;
        std::cout << "2. " << player.getEnergyName() << endl;
        std::cout << "3. " << player.getSkill1Name() << endl;
        std::cout << "4. " << player.getSkill2Name() << endl;
        std::cin >> choice;
    }

    if(choice==1)
        player.setHealth(player.getHealth()+5);
    else if(choice==2)
        player.setEnergyIncrease(player.getEnergy()+5);
    else if(choice==3){
        player.setAttack1(player.attack1()+5);
        player.setEnergyCost1(player.attack1()/3);
    }
    else if(choice==4){
        player.setAttack2(player.attack2()+5);
        player.setEnergyCost2(player.attack2()/3);
    }

}

// last fight in story mode only
void BossFight(BaseCharacter &player, Alien &computer){
    
    int count=0;
    int count2=0;
    int currentDamage;
    int choice=0;
    srand(time(0));
    
    while( player.getHealth()>0 && computer.getHealth()>0 ){
        

        if(count==0){
            std::cout << "You have come across " << computer.getName() << " what will you do select 1-2:" << endl;
            std::cout << "1. " << player.getSkill1Name() << endl;
            std::cout << "2. " << player.getSkill2Name() << endl;
            std::cin >> choice;
        }
        else{
            std::cout << computer.getName()  << " dealt " << currentDamage << " damage what will you do select 1-2:" << endl;
            std::cout << "1. " << player.getSkill1Name() << endl;
            std::cout << "2. " << player.getSkill2Name() << endl;
            std::cin >> choice;
        }


        if(choice==1){
            computer.setHealth(computer.getHealth()-player.attack1());
            std::cout << "You dealt " << player.attack1() << " damage." << endl; 
            player.setEnergy(player.getEnergy(),player.getEnergyCost1());
        }
        else{
            computer.setHealth(computer.getHealth()-player.attack2());
            std::cout << "You dealt " << player.attack2() << " damage." << endl;  
            player.setEnergy(player.getEnergy(),player.getEnergyCost2());                     
        }

        if(rand()%2==0){
            player.setHealth(player.getHealth()-computer.attack1());
            currentDamage = computer.attack1();
            computer.setEnergy(computer.getEnergy(),computer.getEnergyCost1());
        }   
        else if(rand()%2==1){
            player.setHealth(player.getHealth()-computer.attack2());
            currentDamage = computer.attack2();
            computer.setEnergy(computer.getEnergy(),computer.getEnergyCost2());
        } 
        else if(computer.getHealth()<20 && count2<1){
            computer.setHealth(computer.getHealth()+computer.getSkill3());
            std::cout << endl << computer.getName() << " used his " << computer.getSkill3Name() << endl;
        }

        std::cout << endl << player.getName() << " health: " << player.getHealth() << endl;
        std::cout << computer.getName() << " health: " << computer.getHealth() << ", stamina: " << computer.getEnergy() << endl << endl;

        if(player.getHealth()<=0){
            std::cout << "You are dead. GAME OVER" << endl;           
        }     
        else if(computer.getHealth()<=0){
            std::cout << "You have defeated " << computer.getName() << " congratulations" << endl;
        }

        ++count;        
    }

}

// pre boss fight 
void preBoss(){
    cout << endl << "You have defeated all the most powerful people on earth, you will now ascend and face the strongest being in the universe: " << endl;
}

// end of game text
void EOG(){

    std::cout << endl << "You have completed your quest, you are legendary" << endl;

}

int main(){
    
    // computer opponenets
    Warrior fighter1("Alexander The Great", 50, 1, "Axe", 13, "Sword", 8, "Stamina", 50, 10/3, 13/3);
    Chemist fighter2("Robert Boyle", 60, 2,"Flame Thrower", 12, "Bioweapon", 10, "Stamina", 60,12/3,10/3);
    Wizard fighter3("Voldermont", 70, 3, "Ligthing Spell", 14, "Healing Spell", 10, "Mana", 70,14/3,10/3);
    Alien fighter4("King Vito Supreme Leader of the Algol Solar System", 80, 4,"Particle Gun", 20, "Laser Attack", 18 ,20);

    int choice0 = 0;

    // while loop to keep game going
    while(choice0 !=3){    

        std::cout << endl << "Welcome to the Universe Fighting Championship: " << endl;
        std::cout << "Select what game mode you would like to play 1-2: " << endl;
        std::cout << "Arena mode, player vs player" << endl;
        std::cout << "Story mode, for a magical single player experience" << endl;
        std::cin >> choice0;

        // arena mode
        if(choice0==1){
        
            BaseCharacter *player[2];

            std::cout << endl << "Welcome to Arena mode: " << endl;
            std::cout << "Player one build:" << endl;

            int characterChoice=0;
            int count1=0;

            while(characterChoice==0){
                if(count1!=0)
                    std::cout << "You must select a character using 1-3:" << endl;
                
                std::cout << "Select Your Character 1-3" << endl;
                std::cout << "1. Chemist - Strong fire and bioweapon attacks but low health" << endl;
                std::cout << "2. Warrior - High health and great attacks but relies on stamina" << endl;
                std::cout << "3. Wizard - Lightning attacks and poision attacks but relies on mana" << endl;
                std::cin >> characterChoice;
                if( characterChoice<1 || characterChoice>3 ){
                    ++count1;
                    characterChoice = 0; 
                }
            }

            string characterName;

            std::cin.clear();
            std::cin.sync();

            int choice[2];
            int count2=0;
            int power[2];
            string weapons[3] = {"Bow and Arrow", "Sword", "Axe"};

            if(characterChoice==1){
                std::cout << endl << "Enter the name of your Chemist: " << endl; 
                std::getline(std::cin,characterName);
                player[0] = new Chemist(characterName, 50, 1, "Flame Thrower", 10, "Bioweapon", 13,"Stamina", 60, 10/3, 13/3);
                std::cout << "You have created your character. Here are your stats: " << endl << endl;
                player[0]->printStats();
            }
            else if(characterChoice==2){
                std::cout << "Enter the name of your Warrior: " << endl;
                std::getline(std::cin,characterName);
                
                while( choice[0]<1 || choice[0]>3 || choice[1]<1 || choice[1]>3){       

                    if(count2!=0)
                        std::cout << endl << "Must select a number 1-3" << endl;

                    std::cout << "Select which weapon you do want to use 1-3:" << endl;
                    std::cout << "1. Bow and Arrow - Does low damage but expends low stamina: " << endl;
                    std::cout << "2. Sword - Does high damage but expends high stamina: " << endl;
                    std::cout << "3. Axe - Does higher damage but expends higher stamina:" << endl;
                    std::cin >> choice[0] >> choice[1];
                
                }

                for(int i=0; i<2; i++){
                    if(choice[i]==1)
                        power[i] = 6;
                    else if(choice[i]==2)
                        power[i] = 9;
                    else
                        power[i] = 13;
                }
                
                std::cin.clear();
                std::cin.sync();

                player[0] = new Warrior( characterName, 70, 1, weapons[choice[0]-1], power[0], weapons[choice[1]-1], power[1], "Stamina", 50, power[0]/3,power[1]/3);
                std::cout << endl << "You have created your character. Here are your stats: " << endl;   
                player[0]->printStats();
                cout << player[0]->getEnergyName() << ": " << player[0]->getEnergy() << endl;
                
            }
            else{
                std::cout << "Enter the name of your Wizard: " << endl;
                std::getline(std::cin,characterName);
                player[0] = new Wizard(characterName, 65, 1, "Ligthning Spell", 12, "Poison Spell", 10, "Mana", 65, 12/3, 10/3);
                std::cout << "You have created your character. Here are your stats: " << endl;
                player[0]->printStats();
                std::cout << "Mana: " << player[0]->getEnergy() << endl;
            }
        
            std::cout << endl << "Player 2 build:" << endl;
            int characterChoice2=0;
            int count3=0;

            while(characterChoice2==0){
                if(count3!=0)
                    std::cout << "You must select a character using 1-3:" << endl;
                
                std::cout << "Select Your Character 1-3" << endl;
                std::cout << "1. Chemist - Strong fire and bioweapon attacks but low health" << endl;
                std::cout << "2. Warrior - High health and great attacks but relies on stamina" << endl;
                std::cout << "3. Wizard - Lightning attacks and poision attacks but relies on mana" << endl;
                std::cin >> characterChoice2;
                if( characterChoice2<1 || characterChoice2>3 ){
                    ++count3;
                    characterChoice2 = 0; 
                }
            }

            string characterName2;

            std::cin.clear();
            std::cin.sync();

            int choice2[2];
            int count4=0;
            int power2[2];
            string weapons2[3] = {"Bow and Arrow", "Sword", "Axe"};

            if(characterChoice2==1){
                std::cout << endl << "Enter the name of your Chemist: " << endl; 
                std::getline(std::cin,characterName2);
                player[1] = new Chemist(characterName2, 50, 1, "Flame Thrower", 10, "Bioweapon", 13,"Stamina", 60, 10/3, 13/3);
                std::cout << "You have created your character. Here are your stats: " << endl << endl;
                player[1]->printStats();
            }
            else if(characterChoice2==2){
                std::cout << "Enter the name of your Warrior: " << endl;
                std::getline(std::cin,characterName2);
                
                while( choice2[0]<1 || choice2[0]>3 || choice2[1]<1 || choice2[1]>3){       

                    if(count4!=0)
                        std::cout << endl << "Must select a number 1-3" << endl;

                    std::cout << "Select which weapon you do want to use 1-3:" << endl;
                    std::cout << "1. Bow and Arrow - Does low damage but expends low stamina: " << endl;
                    std::cout << "2. Sword - Does high damage but expends high stamina: " << endl;
                    std::cout << "3. Axe - Does higher damage but expends higher stamina:" << endl;
                    std::cin >> choice2[0] >> choice2[1];
                
                }

                for(int i=0; i<2; i++){
                    if(choice2[i]==1)
                        power2[i] = 6;
                    else if(choice2[i]==2)
                        power2[i] = 9;
                    else
                        power2[i] = 13;
                }
                
                std::cin.clear();
                std::cin.sync();

                player[1] = new Warrior( characterName2, 70, 1, weapons2[choice2[0]-1], power2[0], weapons2[choice2[1]-1], power2[1], "Stamina", 50, power2[0]/3,power2[1]/3);
                std::cout << endl << "You have created your character. Here are your stats: " << endl;   
                player[1]->printStats();
                cout << "Stamina: " << player[1]->getEnergy() << endl;
            }
            else{
                std::cout << "Enter the name of your Wizard: " << endl;
                std::getline(std::cin,characterName2);
                player[1] = new Wizard(characterName2, 65, 1, "Ligthning Spell", 12, "Poison Spell", 10, "Mana", 65, 12/3, 10/3);
                std::cout << "You have created your character. Here are your stats: " << endl;
                player[1]->printStats();
                std::cout << "Mana: " << player[1]->getEnergy() << endl;
            }

            PvP(player[0], player[1]);

        }
        // story mode 
        else if(choice0==2){
            int characterChoice=0;
            int count1=0;

            std::cout << endl << "Welcome to the Universe Fighting Championship" << endl;
            std::cout << "Your objective is to become the strongest being in the universe" << endl << endl;

            while(characterChoice==0){
                if(count1!=0)
                    std::cout << "You must select a character using 1-3:" << endl;
                
                std::cout << "Select Your Character 1-3" << endl;
                std::cout << "1. Chemist - Strong fire and bioweapon attacks but low health" << endl;
                std::cout << "2. Warrior - High health and great attacks but relies on stamina" << endl;
                std::cout << "3. Wizard - Lightning attacks and poision attacks but relies on mana" << endl;
                std::cin >> characterChoice;
                if( characterChoice<1 || characterChoice>3 ){
                    ++count1;
                    characterChoice = 0; 
                }
            }

            string characterName;

            std::cin.clear();
            std::cin.sync();

            int choice[2];
            int count2=0;
            int power[2];
            string weapons[3] = {"Bow and Arrow", "Sword", "Axe"};

            if(characterChoice==1){
                std::cout << endl << "Enter the name of your Chemist: " << endl; 
                std::getline(std::cin,characterName);
                Chemist player(characterName, 50, 1, "Flame Thrower", 10, "Bioweapon", 13,"Stamina", 60, 10/3, 13/3);
                std::cout << "You have created your character. Here are your stats: " << endl << endl;
                player.printStats();
                std::cout << endl << "Begining of story mode: " << endl;
                std::cout << "You are a ambitous graduate student with a need to be great. So you set out to become the strongest being in the world!" << endl << endl;
                Fight(player,fighter1);
                LevelUp(player,fighter1);
                Fight(player, fighter2);
                LevelUp(player, fighter2);
                Fight(player, fighter3);
                preBoss();
                LevelUp(player, fighter3);
                BossFight(player, fighter4);
                EOG();
            }
            else if(characterChoice==2){
                std::cout << "Enter the name of your Warrior: " << endl;
                std::getline(std::cin,characterName);
                
                while( choice[0]<1 || choice[0]>3 || choice[1]<1 || choice[1]>3){       

                    if(count2!=0)
                        std::cout << endl << "Must select a number 1-3" << endl;

                    std::cout << "Select which weapon you do want to use 1-3:" << endl;
                    std::cout << "1. Bow and Arrow - Does low damage but expends low stamina: " << endl;
                    std::cout << "2. Sword - Does high damage but expends high stamina: " << endl;
                    std::cout << "3. Axe - Does higher damage but expends higher stamina:" << endl;
                    std::cin >> choice[0] >> choice[1];
                
                }

                for(int i=0; i<2; i++){
                    if(choice[i]==1)
                        power[i] = 6;
                    else if(choice[i]==2)
                        power[i] = 9;
                    else
                        power[i] = 13;
                }
                
                std::cin.clear();
                std::cin.sync();

                Warrior player( characterName, 70, 1, weapons[choice[0]-1], power[0], weapons[choice[1]-1], power[1], "Stamina", 50, power[0]/3,power[1]/3);
                std::cout << endl << "You have created your character. Here are your stats: " << endl;   
                player.printStats();
                cout << "Stamina: " << player.getEnergy() << endl;
                
                std::cout << endl << "Beginning of story mode:" << endl;
                std::cout << "You are a cage fighter who no longer finds pleasure in combat sports. You know must go beyond that, your thirst for blood must be satisfied" << endl;
                
                Fight(player,fighter1);
                LevelUp(player,fighter1);
                Fight(player, fighter2);
                LevelUp(player, fighter2);
                Fight(player, fighter3);
                preBoss();
                LevelUp(player, fighter3);
                BossFight(player, fighter4);
                EOG();
            }
            else{
                std::cout << "Enter the name of your Wizard: " << endl;
                std::getline(std::cin,characterName);
                Wizard player(characterName, 65, 1, "Ligthning Spell", 12, "Poison Spell", 10, "Mana", 65, 12/3, 10/3);
                std::cout << "You have created your character. Here are your stats: " << endl;
                player.printStats();
                std::cout << "Mana: " << player.getEnergy() << endl;

                std::cout << endl << "Begining of story mode:" << endl;
                std::cout << "You have mastered witchcraft and now you are ready to show your skills!" << endl;

                Fight(player,fighter1);
                LevelUp(player,fighter1);
                Fight(player, fighter2);
                LevelUp(player, fighter2);
                Fight(player, fighter3);
                preBoss();
                LevelUp(player, fighter3);
                BossFight(player, fighter4);
                EOG();
            }
        }
    
        // end game menu
        std::cout << endl << "Would you like to play again 1-3 ?" << endl;
        std::cout << "Arena mode, player vs player or player vs computer" << endl;
        std::cout << "Story mode, for a magical single player experience" << endl;
        std::cout << "End game" << endl;
        std::cin >> choice0;
    }
    return 0;
}