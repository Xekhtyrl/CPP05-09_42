/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:33:37 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/28 17:28:03 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default constructor
Form::Form(): _name("Basic Form"), _gradeReqSign(150), _gradeReqExec(150){
	_signed = false;
	return ;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), 
		_gradeReqSign(gradeSign), _gradeReqExec(gradeExec){
	_signed = false;
	return ;
}

// Copy constructor
Form::Form(const Form &other): _name(other.getName()), 
		_gradeReqSign(other.getGradeReqSign()), _gradeReqExec(other.getGradeReqExec()){
	_signed = false;
	return ;
}

// Copy assignment overload
Form &Form::operator=(const Form &rhs) {
	(void(rhs));
	_signed = false;
  return *this;
}

// Default destructor
Form::~Form() { 
	std::cout<<"Form "<<_name<<" has been shreded"<<std::endl;
	return; }

void	Form::beSigned(Bureaucrat& Ahole){
	try
	{
		Ahole.signForm(*this);
		_signed = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what()<<std::endl;
	}
	catch(int e)
	{
		return;
	}
}

std::string Form::getName() const{
	return (_name);
}

bool Form::getSigned(){
	return _signed;
}

int Form::getGradeReqSign() const{
	return _gradeReqSign;
}

int Form::getGradeReqExec() const{
	return _gradeReqExec;
}

const char*	Form::GradeTooHighException::what() const throw() { 
	return "Grade too High: ";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade too Low: ";
}

std::ostream& operator<<(std::ostream& out, Form& Class){
	return out<<"Form "<<Class.getName()<<" Signed :"<<Class.getSigned()
		<<", the required grade to be signed is "<<Class.getGradeReqSign()
		<<", and to be executed is "<<Class.getGradeReqExec()<<std::endl;
}