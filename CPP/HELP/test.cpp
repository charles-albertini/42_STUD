#include <iostream>
#include <string>
#include "Personnage.hpp"


int main()
{
    Personnage david, goliath;

    goliath.attaquer(david); 
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);

    return 0;
}