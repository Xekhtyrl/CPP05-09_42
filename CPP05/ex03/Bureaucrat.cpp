/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:46:37 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 22:07:23 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdio.h>

// Default constructor
Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(150) { return; }

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Exception: "<< e.what()<<grade<<std::endl;
		_grade = 150;
	}
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  *this = other;
  return;
}

// Copy assignment overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Bureaucrat::~Bureaucrat() { 
	std::cout<<this->_name<<" has been removed from The Matrix"<<std::endl;
	return; }

std::string const Bureaucrat::getName()
{
	return (this->_name);
}
int	 Bureaucrat::getGrade() const
{
	return (this->_grade);
}
void Bureaucrat::upGrade()
{
	std::cout<<"Upgrade "<<this->_name<<std::endl;
	try
	{
		if (_grade - 1 < 1)
			throw GradeTooHighException();
		_grade--;
		std::cout<<this->_name<<" new grade: "<<this->_grade<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Exception: "<< e.what()<< _grade - 1<<std::endl;
	}
}
void Bureaucrat::downGrade()
{
	std::cout<<"Downgrade "<<this->_name<<std::endl;
	try
	{
		if (_grade + 1 > 150)
			throw GradeTooLowException();
		_grade++;
		std::cout<<this->_name<<" new grade: "<<this->_grade<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Exception: "<< e.what()<< _grade + 1<<std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() { 
	return "Grade too High: ";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too Low: ";
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& Class){
	return out<<Class.getName()<<", bureaucrat grade "<< Class.getGrade();
}

void Bureaucrat::signForm(AForm& Form){
	Form.beSigned(*this);
}
void	Bureaucrat::executeForm(const AForm& form) {
	form.execute(*this);
}
