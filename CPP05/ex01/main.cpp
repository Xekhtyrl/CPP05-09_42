/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:13:01 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/28 17:26:26 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	
	std::cout<<"\\\\____________Class Constructor_____________//\n"<<std::endl;

	Bureaucrat Anderson("Thomas Anderson", 150);
	Bureaucrat Smith("Agent Smith", 1);
	Form	Basic;
	Form	Complex("Order 66", 50, 1);

	std::cout<<"\n\\\\____________<< operator_____________//\n"<<std::endl;
	std::cout<<Basic<<std::endl;
	std::cout<<Complex<<std::endl;

	std::cout<<"\n\\\\____________Sign Form_____________//\n"<<std::endl;
	Basic.beSigned(Anderson);
	Basic.beSigned(Smith);
	Complex.beSigned(Anderson);
	Complex.beSigned(Smith);

	std::cout<<"\n\\\\____________Destructors_____________//\n"<<std::endl;
}