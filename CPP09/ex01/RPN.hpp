/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:19 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/08 16:46:35 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>
#include <stdexcept>

// Class declaration
class RPN {
 public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &rhs);
  ~RPN();
  static void calculate(char *);
};