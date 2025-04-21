#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    std::cout << "Cloning Cure materia" << std::endl;
    Cure* newCure = new Cure();
    return newCure;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}