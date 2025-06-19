#include "zombie_son.h"


char Zombie:: getType(){


    int randNum = rand()% 6;

    switch(randNum){
        case 0:
            this->type = 'R';
            return this->type;
            
        case 1:
            this->type = 'Y';
            return this->type;
        case 2:
            this->type = 'G';  
            return this->type;
        case 3:
            this->type = 'B';
            return this->type;
        case 4:
            this->type = 'C';
            return this->type;
        case 5:
            this->type = 'M';
            return this->type;
        default:
            return this->type;
    } 


}

std::ostream& operator <<(std::ostream& os , const Zombie& z) {
    
    os << "[" << z.type << "]";
    return os;
}