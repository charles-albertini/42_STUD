#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{

	private:

	std::string target;

	public:

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm const &other);

	//Fonctions
	void execute(Bureaucrat const &executor)const;

};

#endif