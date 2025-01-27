/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:33:37 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 22:10:41 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm(): _name("Basic Form"), _gradeReqSign(150), _gradeReqExec(150){
	_signed = false;
	return ;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), 
		_gradeReqSign(gradeSign), _gradeReqExec(gradeExec){
	_signed = false;
	return ;
}

// Copy constructor
AForm::AForm(const AForm &other): _name(other.getName()), 
		_gradeReqSign(other.getGradeReqSign()), _gradeReqExec(other.getGradeReqExec()){
	_signed = false;
	return ;
}

// Copy assignment overload
AForm &AForm::operator=(const AForm &rhs) {
	(void(rhs));
	_signed = false;
  return *this;
}

// Default destructor
AForm::~AForm() { 
	std::cout<<"Form "<<_name<<" has been shreded"<<std::endl;
	return; }

void	AForm::beSigned(Bureaucrat& Ahole){
	try
	{
		if (Ahole.getGrade() > this->getGradeReqSign())
		{
			std::cout<<Ahole.getName()<<" couldn't sign "<<_name<<" because ";
			throw AForm::GradeTooLowException();
		}
		if (_signed)
		{
			std::cout<<Ahole.getName()<<" couldn't sign "<<_name<<" because it is already signed"<<std::endl;
			throw 0;
		}
		else
		{
			std::cout<<Ahole.getName()<<" signed "<<_name<<std::endl;
		}
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

std::string AForm::getName() const{
	return (_name);
}

bool AForm::getSigned(){
	return _signed;
}

int AForm::getGradeReqSign() const{
	return _gradeReqSign;
}

int AForm::getGradeReqExec() const{
	return _gradeReqExec;
}

const char*	AForm::GradeTooHighException::what() const throw() { 
	return "Grade too High: ";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade too Low: ";
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return "Form not Signed";
}

std::ostream& operator<<(std::ostream& out, AForm& Class){
	return out<<"Form "<<Class.getName()<<" Signed :"<<Class.getSigned()
		<<", the required grade to be signed is "<<Class.getGradeReqSign()
		<<", and to be executed is "<<Class.getGradeReqExec()<<std::endl;
}

void	AForm::execute(const Bureaucrat & executor) const {
	try
	{
		if (!_signed)
			throw FormNotSignedException();
		else if (this->getGradeReqExec() < executor.getGrade())
			throw GradeTooLowException();
		executeForm();
	}
	catch(const std::exception& e)
	{
		std::cerr<<"Exception : "<< e.what() << '\n';
	}
}
