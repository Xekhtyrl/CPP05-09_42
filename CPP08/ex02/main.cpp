/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:13 by lvodak            #+#    #+#             */
/*   Updated: 2024/08/05 22:10:03 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);

// std::list<int> mstack;
// mstack.push_back(5);
// mstack.push_back(17);
// std::cout << mstack.back() << std::endl;
// mstack.pop_back();
// std::cout << mstack.size() << std::endl;
// mstack.push_back(3);
// mstack.push_back(5);
// mstack.push_back(737);
// //[...]
// mstack.push_back(0);
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::list<int> s(mstack);

std::cout<<"\\\\_____________Test for bigger stack______________ //"<<std::endl;

MutantStack<int> BStack;

for (int i = 0; i < 100; i++)
	BStack.push(i);
std::cout << BStack.top() << std::endl;
BStack.pop();
MutantStack<int>::iterator it1 = BStack.begin();
MutantStack<int>::iterator ite1 = BStack.end();
++it1;
--it1;
while (it1 != ite1) // does not print the last then
{
	std::cout << *it1 << std::endl;
	++it1; 
}
std::stack<int> d(BStack);

// std::list<int> BStack;

// for (int i = 0; i < 100; i++)
// 	BStack.push_back(i);
// std::cout << BStack.back() << std::endl;
// BStack.pop_back();
// std::list<int>::iterator it1 = BStack.begin();
// std::list<int>::iterator ite1 = BStack.end();
// ++it1;
// --it1;
// while (it1 != ite1)
// {
// 	std::cout << *it1 << std::endl;
// 	++it1;
// }
// std::list<int> d(BStack);
// return 0;
}