/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:19:17 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 21:32:28 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreation", 145, 137), _target("[no target]") { return; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreation", 145, 137), _target(target) { return; }

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm("ShrubberyCreation", 145, 137), _target(other._target) {
  *this = other;
  return;
}

// Copy assignment overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() { return; }

void	ShrubberyCreationForm::executeForm() const {
	std::fstream file(_target+"_shrubbery", std::ios::out);
	file << "        /\\       \n";
	file << "       /. \\      \n";
	file << "      /_  _\\     \n";
	file << "      /.   \\     \n";
	file << "     /   .  \\    \n";
	file << "    /_      _\\   \n";
	file << "    /  .   . \\   \n";
	file << "   /      .   \\  \n";
	file << "  /____________\\ \n";
	file << "  /    /  \\    \\\n";
	file << "       |  |      \n";
	file << "       |  |      \n";
	file << "                 ";
	file.close();
}