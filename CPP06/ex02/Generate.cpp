/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:14:10 by lvodak            #+#    #+#             */
/*   Updated: 2024/07/31 23:30:15 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generate.hpp"
#include <iostream>
#include <sys/time.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	timeval t;
	gettimeofday(&t, NULL);
	static int iter;
	long	r = t.tv_sec * 1000 + t.tv_usec + iter++;

	if (r % 3 == 0)
		return new A();
	else if (r % 3 == 1)
		return new B();
	else if (r % 3 == 2)
		return new C();
	return 0;
}