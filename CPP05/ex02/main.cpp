/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:13:01 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/19 19:11:13 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	
	std::cout<<"\\\\____________Class Constructor_____________//\n"<<std::endl;

	Bureaucrat Anderson("Thomas Anderson", 150);
	Bureaucrat Smith("Agent Smith", 50);
	Bureaucrat Morpheus("Morpheus", 4);
	PresidentialPardonForm PPF("Neo");
	ShrubberyCreationForm SCF("Tree");
	RobotomyRequestForm RRF("Smith");

	std::cout<<PPF<<std::endl;;
	std::cout<<SCF<<std::endl;;
	std::cout<<RRF<<std::endl;;
	std::cout<<"\n\\\\____________Fail test_____________//\n"<<std::endl;
	Anderson.executeForm(PPF);
	Smith.executeForm(PPF);
	Morpheus.executeForm(PPF);
	Anderson.signForm(PPF);
	std::cout<<"\n\\\\____________Form Info_____________//\n"<<std::endl;
	std::cout<<PPF.getName()<<" require "<<PPF.getGradeReqExec()<<" grade to be executed and "
			<<PPF.getGradeReqSign()<<" to be signed."<<std::endl;
	std::cout<<SCF.getName()<<" require "<<SCF.getGradeReqExec()<<" grade to be executed and "
			<<SCF.getGradeReqSign()<<" to be signed."<<std::endl;
	std::cout<<RRF.getName()<<" require "<<RRF.getGradeReqExec()<<" grade to be executed and "
			<<RRF.getGradeReqSign()<<" to be signed."<<std::endl;
	std::cout<<"\n\\\\____________Sign Form_____________//\n"<<std::endl;
	PPF.beSigned(Morpheus);
	SCF.beSigned(Smith);
	RRF.beSigned(Smith);
	std::cout<<"\n\\\\____________Execute Form_____________//\n"<<std::endl;
	PPF.execute(Morpheus);
	SCF.execute(Smith);
	Morpheus.executeForm(RRF);

	std::cout<<"\n\\\\____________Destructors_____________//\n"<<std::endl;
}