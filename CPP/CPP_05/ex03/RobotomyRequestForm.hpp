#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{

	private:

	std::string target;

	public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm const &other);

	//Fonctions
	void execute(Bureaucrat const &executor)const;

};

#endif