/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:02 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 21:28:02 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon", 25, 5), _target("[no target]") { return; }

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential Pardon", 25, 5), _target(target) { return; }

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm("Presidential Pardon", 25, 5), _target(other._target) {
  *this = other;
  return;
}

// Copy assignment overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
PresidentialPardonForm::~PresidentialPardonForm() { return; }

void	PresidentialPardonForm::executeForm() const{
	std::cout<<_target<<" has been graciously pardoned by the Mercifull Zaphod Beeblebrox"<<std::endl;
}