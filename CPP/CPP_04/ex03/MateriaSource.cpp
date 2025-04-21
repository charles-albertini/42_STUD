#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    // Initialiser d'abord tous les templates à NULL
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
    
    // Copie profonde des templates
    for (int i = 0; i < 4; i++) {
        if (other.templates[i] != NULL) {
            this->templates[i] = other.templates[i]->clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        // Liberer la memoire existante
        for (int i = 0; i < 4; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        
        // Copie profonde des templates
        for (int i = 0; i < 4; i++) {
            if (other.templates[i] != NULL) {
                this->templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    // Liberer la memoire de tous les templates
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL) {
            delete this->templates[i];
            this->templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot learn NULL materia" << std::endl;
        return;
    }
    
    // Trouver un slot libre
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] == NULL) {
            std::cout << "Learning " << m->getType() << " at slot " << i << std::endl;
            this->templates[i] = m;
            return;
        }
    }
    
    // Si tous les slots sont occupes, on libere la memoire
    std::cout << "No space left to learn new materia, deleting " << m->getType() << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    std::cout << "Trying to create materia of type: " << type << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type) {
            std::cout << "Creating materia of type: " << type << std::endl;
            return this->templates[i]->clone();
        }
    }
    std::cout << "Unknown materia type: " << type << std::endl;
    return NULL; // Return NULL if type is unknown
}