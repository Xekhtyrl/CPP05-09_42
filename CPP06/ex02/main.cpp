/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:53:36 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 23:30:31 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Generate.hpp"
#include "Identify.hpp"
#include <typeinfo>
#include <iostream>

int main() {
	Base *one= generate();
	Base *two= generate();
	Base *three= generate();
	identify(one);
	identify(two);
	identify(three);
	identify(*one);
	identify(*two);
	identify(*three);
}