#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Vérifier si le formulaire peut être exécuté
    checkExecutability(executor);
    
    // Créer un fichier et écrire des arbres ASCII
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (file.is_open()) {
        file << "       _-_       " << std::endl;
        file << "    /~~   ~~\\    " << std::endl;
        file << " /~~         ~~\\ " << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  / " << std::endl;
        file << "   ~  \\\\ //  ~   " << std::endl;
        file << "_- -   | | _- _  " << std::endl;
        file << "  _ -  | |   -_  " << std::endl;
        file << "      // \\\\      " << std::endl;
        
        file.close();
        std::cout << "Created shrubbery file: " << filename << std::endl;
    } else {
        std::cout << "Failed to create shrubbery file." << std::endl;
    }
}