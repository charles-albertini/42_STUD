#include "Functions.hpp"
#include <iostream>

int main() {
    // Générer une instance aléatoire
    Base* instance = generate();
    
    // Identifier le type en utilisant les deux méthodes
    identify(instance);
    identify(*instance);
    
    // Libérer la mémoire
    delete instance;
    
    return 0;
}