/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:58:56 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/28 17:19:07 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();
		std::string const getName();
		int	 getGrade();
		void upGrade();
		void downGrade();
		void signForm(Form& Form);
		class GradeTooHighException : public std::exception{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			virtual const char *what() const throw();
		};

	private:
		std::string	const	_name;
		int	_grade;
};
std::ostream& operator<<(std::ostream& out, Bureaucrat& Class);

#endif
