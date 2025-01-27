/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:53 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 21:30:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequest", 72, 45), _target("[no target]") { return; }

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequest", 72, 45), _target(target) { return; }

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm("RobotomyRequest", 72, 45), _target(other._target) {
  *this = other;
  return;
}

// Copy assignment overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
RobotomyRequestForm::~RobotomyRequestForm() { return; }

void	RobotomyRequestForm::executeForm() const {
	std::cout<<"*drilling noises* bzzzzzzd bzzzzzzd vvvvvvvvvvvvr cccccrrrrrrr bzzzzzzzd bzzzzzzzd vvvvvvvvvv kkh"<<std::endl;
	if (rand() % 100 < 50)
		std::cout<<_target<<" has succesfully been robotomized!!! bip bip bip bouppa"<<std::endl;
	else
		std::cout<<"Robotomisation failed... "<<_target<<" is... Unalive..."<<std::endl;
}