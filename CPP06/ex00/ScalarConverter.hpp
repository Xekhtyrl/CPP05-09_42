/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:04:24 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/21 18:03:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <iostream>

// Class declaration
class ScalarConverter {
 public:
  static void convert(std::string literal);
 private:
  static void toInt(std::string literal);
  static void toChar(std::string literal);
  static void toFloat(std::string literal);
  static void toDouble(std::string literal);
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP_
