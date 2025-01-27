/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:33:26 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/28 17:25:33 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
// Class declaration
class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &other);
		Form &operator=(const Form &rhs);
		~Form();
		void	beSigned(Bureaucrat& Ahole);
		std::string getName() const;
		bool getSigned();		
		int getGradeReqSign() const;
		int getGradeReqExec() const;
		class GradeTooHighException : public std::exception{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool _signed;
		const int	_gradeReqSign;
		const int	_gradeReqExec;

		
};
std::ostream& operator<<(std::ostream& out, Form& Class);

#endif // FORM_HPP_
