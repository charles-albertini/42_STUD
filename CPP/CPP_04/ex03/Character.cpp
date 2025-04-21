#include "AMateria.hpp"
#include "Character.hpp"

AMateria* Character::droppedMaterias[100] = {NULL};
int Character::droppedCount = 0;

Character::Character() : name("") {
    std::cout << "Character default constructor called" << std::endl;
    // Initialiser tous les slots d'inventaire à NULL
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character parameterized constructor called" << std::endl;
    // Initialiser tous les slots d'inventaire à NULL
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    // Initialiser d'abord tous les slots à NULL
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    
    // Copie profonde de l'inventaire
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i] != NULL) {
            this->inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        // Liberer la memoire existante
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
        
        // Copier le nom
        this->name = other.name;
        
        // Copie profonde de l'inventaire
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                this->inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    // Liberer la memoire de tous les materia dans l'inventaire
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    
    // Nettoyer les materias desequipees (uniquement pour le dernier Character detruit)
    static bool isFirstDestruction = true;
    if (isFirstDestruction) {
        isFirstDestruction = false;
        // Liberer toutes les materias desequipees
        for (int i = 0; i < droppedCount; i++) {
            if (droppedMaterias[i] != NULL) {
                delete droppedMaterias[i];
                droppedMaterias[i] = NULL;
            }
        }
        droppedCount = 0;
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (m == NULL) {
        std::cout << "Cannot equip NULL materia" << std::endl;
        return;
    }
    
    // Trouver un slot libre
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            std::cout << "Equipping " << m->getType() << " at slot " << i << std::endl;
            this->inventory[i] = m;
            return;
        }
    }
    // Si tous les slots sont occupes, on ne fait rien
    std::cout << "Inventory full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (this->inventory[idx] != NULL) {
            std::cout << "Unequipping slot " << idx << std::endl;
            // Stocker la materia dans la liste des materias desequipees
            droppedMaterias[droppedCount++] = this->inventory[idx];
            this->inventory[idx] = NULL;
        } else {
            std::cout << "Nothing to unequip at slot " << idx << std::endl;
        }
    } else {
        std::cout << "Invalid inventory slot: " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
        std::cout << "Using " << this->inventory[idx]->getType() << " on " << target.getName() << std::endl;
        this->inventory[idx]->use(target);
    } else {
        std::cout << "Invalid inventory slot or empty slot: " << idx << std::endl;
    }
}