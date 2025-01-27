/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:51:44 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/30 00:42:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// Default constructor
Intern::Intern() { return; }

// Copy constructor
Intern::Intern(const Intern &other) {
  *this = other;
  return;
}

// Copy assignment overload
Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Intern::~Intern() { return; }

AForm	*Intern::makeForm(std::string name, std::string target) {
	AForm	*form = NULL;
	std::string formName[3] = {"Presidential Pardon", "Shrubbery Creation", "Robotomy Request"};
	AForm* (Intern::*Forms[3])(const std::string&) const = {
        &Intern::createShrubberyCreation,
        &Intern::createRobotomyRequest,
        &Intern::createPresidentialPardon};
	
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(formName[i]))
			form = (this->*Forms[i])(target);
	}
	if (!form)
		std::cout<<"Form "<<name<<" does not exist!"<<std::endl;
	else
		std::cout<<"Intern creates "<<name<<std::endl;
	return form;
}

AForm	*Intern::createShrubberyCreation(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}
AForm	*Intern::createRobotomyRequest(const std::string& target) const {
	return new RobotomyRequestForm(target);
}
AForm	*Intern::createPresidentialPardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}