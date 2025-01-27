/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:29:51 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/01 18:00:44 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "maax( c, d ) = " << ::max( c, d ) << std::endl;
std::string e = "coucou";
std::string f = "bonjour";

::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "maax( e, f ) = " << ::max( e, f ) << std::endl;

e = "coucou";
f = "coucou";

::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;

std::string& min = (::min( e, f ));
std::string& max = (::max( e, f ));
std::cout << "min( e, f ) = " << &min <<"   "<<&f<< std::endl;
std::cout << "maax( e, f ) = " << &max <<"  "<<&f<< std::endl;
}