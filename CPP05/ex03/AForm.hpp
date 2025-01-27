/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:33:26 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/29 21:36:19 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
// Class declaration
class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm();
		virtual void	beSigned(Bureaucrat& Ahole);
		virtual void	execute(const Bureaucrat & executor) const;
		virtual std::string getName() const;
		virtual bool getSigned();		
		virtual int getGradeReqSign() const;
		virtual int getGradeReqExec() const;
		class GradeTooHighException : public std::exception{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception{
			virtual const char *what() const throw();
		};
	protected:
		virtual void executeForm() const = 0;
	private:
		const std::string	_name;
		bool _signed;
		const int	_gradeReqSign;
		const int	_gradeReqExec;

		
};
std::ostream& operator<<(std::ostream& out, AForm& Class);

#endif // FORM_HPP_
