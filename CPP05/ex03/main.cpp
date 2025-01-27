/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:13:01 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/21 14:18:01 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(){
	
	std::cout<<"\\\\____________Class Constructor_____________//\n"<<std::endl;

	Bureaucrat Anderson("Thomas Anderson", 150);
	Bureaucrat Smith("Agent Smith", 50);
	Bureaucrat Morpheus("Morpheus", 4);
	
	Intern intern;
	AForm* PPF;
	PPF = intern.makeForm("Presidential Pardon","Neo");
	AForm* SCF;
	SCF = (intern.makeForm("Shrubbery Creation", "Neo"));
	AForm* RRF;
	RRF = (intern.makeForm("Robotomy Request", "Neo"));

	std::cout<<*PPF<<std::endl;;
	std::cout<<*SCF<<std::endl;;
	std::cout<<*RRF<<std::endl;;
	std::cout<<"\n\\\\____________Fail test_____________//\n"<<std::endl;
	Anderson.executeForm(*PPF);
	Smith.executeForm(*PPF);
	Morpheus.executeForm(*PPF);
	Anderson.signForm(*PPF);
	std::cout<<"\n\\\\____________Sign Form_____________//\n"<<std::endl;
	PPF->beSigned(Morpheus);
	SCF->beSigned(Smith);
	RRF->beSigned(Smith);
	std::cout<<"\n\\\\____________Execute Form_____________//\n"<<std::endl;
	PPF->execute(Morpheus);
	SCF->execute(Smith);
	Morpheus.executeForm(*RRF);

	std::cout<<"\n\\\\____________Destructors_____________//\n"<<std::endl;
}