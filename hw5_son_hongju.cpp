#include "linkedlist_son.hpp"
#include "zombie_son.cpp"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

using std::cout;
using std::endl;


class Conga {
private:
    LinkedList<Zombie> congaLine; // Linked list to represent the conga line

public:
    Conga();

    void engine_action(Zombie randomZomb);
    void caboose_action(Zombie randomZomb);
    void jump_in_action(Zombie randomZomb);
    void everyone_out_action(Zombie randomZomb);
    void you_out_action(Zombie randomZomb);
    void brains_action(Zombie randomZomb);
    void rainbow_action(Zombie randomZomb);
    void friends_action(Zombie randomZomb);

    void runCongaParty(int numRounds);
};

Conga::Conga() {}

void Conga::engine_action(Zombie randomZomb) {
    congaLine.AddToFront(randomZomb);
}

void Conga::caboose_action(Zombie randomZomb) {
    congaLine.AddToEnd(randomZomb);
}

void Conga::jump_in_action(Zombie randomZomb) {
    int index = rand() % (congaLine.Length()+1);
    congaLine.AddAtIndex(randomZomb, index);
}

void Conga::everyone_out_action(Zombie randomZomb) {
    congaLine.RemoveAllOf(randomZomb);
}

void Conga::you_out_action(Zombie randomZomb) {
    congaLine.RemoveTheFirst(randomZomb);
}

void Conga::brains_action(Zombie randomZomb) {
    engine_action(randomZomb);
    caboose_action(randomZomb);
    int middleIndex = congaLine.Length() / 2;
    congaLine.AddAtIndex(randomZomb, middleIndex);
}

void Conga::rainbow_action(Zombie randomZomb) {
    engine_action(randomZomb);
    caboose_action(Zombie('R'));
    caboose_action(Zombie('Y'));
    caboose_action(Zombie('G'));
    caboose_action(Zombie('B'));
    caboose_action(Zombie('C'));
    caboose_action(Zombie('M'));
}

void Conga::friends_action(Zombie randomZomb) {
    Node<Zombie>* zombieNode = congaLine.Find(randomZomb);
    if (zombieNode != nullptr) {
        int flip = rand() % 2;
        if (flip == 0) {
            congaLine.AddBefore(zombieNode, randomZomb);
        } else {
            congaLine.AddAfter(zombieNode, randomZomb);
        }
    } else {
        caboose_action(randomZomb);
    }
}

void Conga::runCongaParty(int numRounds){

    Zombie randomZomb = Zombie();

    rainbow_action(randomZomb.getType());
    brains_action(randomZomb.getType());
    brains_action(randomZomb.getType());
    brains_action(randomZomb.getType());



    for (int round = 0; round < numRounds; round++) {
        if (round % 5 == 0) {
            congaLine.RemoveFromFront();
            congaLine.RemoveFromEnd();
        }
        std::cout << "Round: " << round << std::endl;
        std::cout << "Size: " << congaLine.Length() << " :: ";
        congaLine.PrintList();

        Zombie randomZomb;
        int action = rand() % 8;
        switch (action) {
            case 0:
                engine_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Engine!" << std::endl;
                break;
            case 1:
                caboose_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Caboose!" << std::endl;
                break;
            case 2:
                jump_in_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Jump In!" << std::endl;
                break;
            case 3:
                everyone_out_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Everyone Out!" << std::endl;
                break;
            case 4:
                you_out_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: You Out!" << std::endl;
                break;
            case 5:
                brains_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Brains!" << std::endl;
                break;
            case 6:
                rainbow_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: Rainbow Brains!" << std::endl;
                break;
            case 7:
                friends_action(randomZomb.getType());
                std::cout << "New Zombie: " << randomZomb << " -- Action: New Friends!" << std::endl;
                break;
            default:
                break;
        }

        std::cout << "The conga line is now:" << std::endl;
        std::cout << "Size: " << congaLine.Length() << " :: ";
        congaLine.PrintList();
        std::cout << "**************************************************" << std::endl;


        if (congaLine.Length() == 0) {
            std::cout << "The Party is Over." << std::endl;
            break;
        }
    
    }
}

int main(int argc, char* argv[]){

    if(strcmp(argv[1], "-s")== 0){

        srand((atoi(argv[2])));
    }
    else{
        srand(time(0));      
    }

    int numRounds;
    std::cout << "How many rounds do you want to run? ";
    std::cin >> numRounds;

    Conga congaParty;

    congaParty.runCongaParty(numRounds);
    
        char choice;
    std::cout << "Do you want to continue the party? (y/n) ";
    std::cin >> choice;
    while (choice == 'y' || choice == 'Y') {
        std::cout << "How many rounds do you want to run? ";
        std::cin >> numRounds;

        congaParty.runCongaParty(numRounds);

        std::cout << "Do you want to continue the party? (y/n) ";
        std::cin >> choice;
    }

    return 0;
}