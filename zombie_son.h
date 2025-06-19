#include <iostream>
#include <cstdlib>
#pragma once

class Zombie{

    private:
        char type;

    public:
        char getType();

        bool operator==(const Zombie& A) const{
            return this->type == A.type;    
        }
        bool operator!=(const Zombie& A) const{
            return this->type != A.type;
        }
        friend std::ostream &operator <<(std::ostream& os , const Zombie& z);



    Zombie()
        : type()
    {

    }
    Zombie(char _type)
        : type(_type)
    {
        
    }

};
