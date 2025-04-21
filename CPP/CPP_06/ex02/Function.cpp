#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {

    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated type A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated type C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

//on tente de convertir le pointeur vers chaque type possible

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL) 
        std::cout << "Type identified (via pointer): A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) 
        std::cout << "Type identified (via pointer): B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL) 
        std::cout << "Type identified (via pointer): C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;
}

/*
dynamic cats avec une reference lance une exception en cas
d'echec (alors que avec les poointeur ca renvoie NULL) 
*/
void identify(Base& p) {

    try 
	{
        A& a = dynamic_cast<A&>(p); //on creer un a qui sert a rien mais c'est pour tester le try
        (void)a;
        std::cout << "Type identified (via reference): A" << std::endl;
    } 
	catch (...) //... catch n'importe quelle exception
	{
	}
    try 
	{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type identified (via reference): B" << std::endl;
    } 
	catch (...) 
	{
	}
    try 
	{
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type identified (via reference): C" << std::endl;
    } 
	catch (...) 
	{

	}
	
    std::cout << "Unknown type" << std::endl;
}
