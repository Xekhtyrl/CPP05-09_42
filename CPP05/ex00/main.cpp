/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:13:01 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/27 18:57:33 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	
	std::cout<<"\\\\____________Class Constructor_____________//\n"<<std::endl;

	Bureaucrat Anderson("Thomas Anderson", 150);
	Bureaucrat Smith("Agent Smith", 1);
	Bureaucrat Error("Some Low Employee", 151);
	Bureaucrat noOne;

	std::cout<<"\n\\\\____________Grade Change_____________//\n"<<std::endl;
	Anderson.downGrade();
	Anderson.upGrade();
	Smith.upGrade();
	Smith.downGrade();
	
	std::cout<<"\n\\\\____________<< operator_____________//\n"<<std::endl;
	std::cout<<Anderson<<std::endl;
	std::cout<<Smith<<std::endl;
	std::cout<<Error<<std::endl;

	std::cout<<"\n\\\\____________Destructors_____________//\n"<<std::endl;
}