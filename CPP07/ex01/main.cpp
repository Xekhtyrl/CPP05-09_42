/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:11:51 by lvodak            #+#    #+#             */
/*   Updated: 2024/09/21 22:33:20 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include "stdio.h"

void	repeatAlpha(char& str){
	if (!isalpha(str))
		return (void)(std::cout<<str);
	int q = 'A' * -1 * (isupper(str)) + 'a' * -1 *(islower(str));
	for (int i = 0; i <= ((int)str + q); i++)
		std::cout<<str;
}
void	test(int& a){
	++a;
}

void	test2(char& a){
	++a;
}

int main (){
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(arr, 10, test);
	for (int i = 0; i < 10; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;

	std::string str = "coucou";
	iter((char *)str.c_str(), 6, test2);
	std::cout<<str<<std::endl;

	std::string testo = "easy pz";
	iter((char *)testo.c_str(), 7, repeatAlpha);
}