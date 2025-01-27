/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:44:20 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/30 00:32:58 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iostream>
#include "AForm.hpp"

// Class declaration
class Intern {
 public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &rhs);
  ~Intern();
  AForm	*makeForm(std::string name, std::string target);
  AForm	*createShrubberyCreation(const std::string& target) const;
  AForm	*createRobotomyRequest(const std::string& target) const;
  AForm	*createPresidentialPardon(const std::string& target) const;

 private:
  
};

#endif // INTERN_HPP_
