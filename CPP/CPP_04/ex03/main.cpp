
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    // Tests supplementaires
    std::cout << "\n--- Tests supplementaires ---\n" << std::endl;
    
    // Test avec un type de Materia inconnu
    tmp = src->createMateria("unknown");
    if (tmp == NULL) {
        std::cout << "Materia 'unknown' n'existe pas" << std::endl;
    }
    
    // Test unequip et re-equip
    me->unequip(0);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob);
    
    // Test copie profonde de Character
    Character* original = new Character("original");
    tmp = src->createMateria("ice");
    original->equip(tmp);
    
    Character* copy = new Character(*original);
    copy->use(0, *bob);
    
    delete original;
    delete copy;
    
    delete bob;
    delete me;
    delete src;
    
    return 0;
}