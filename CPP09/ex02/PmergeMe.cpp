/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:03:32 by lvodak            #+#    #+#             */
/*   Updated: 2024/10/03 14:25:07 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdio.h>
#include <ctime>

// Default constructor
PmergeMe::PmergeMe() { return; }

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
  return;
}

// Copy assignment overload
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
PmergeMe::~PmergeMe() { return; }

template <typename T>
void PrintCont(T cont){
	for (int i = 0; i < (int)cont.size(); i++)
		std::cout<<cont.at(i)<<" ";
	std::cout<<std::endl;
}
template <typename T>
void insertionSort(T& in, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = in[i + 1];
        int j = i + 1;
        while (j > p && in[j - 1] > tempVal) {
            in[j] = in[j - 1];
            j--;
        }
        in[j] = tempVal;
    }
}

template <typename T>
void merge(T& in, int pos, int q, int res) {
    int n1 = q - pos + 1;
    int n2 = res - q;
    T leftCont;
	std::copy(in.begin() + pos, in.begin() + q + 1, std::back_inserter(leftCont));
    T rightCont;
	std::copy(in.begin() + q + 1, in.begin() + res + 1, std::back_inserter(rightCont));
    int rI = 0;
    int lI = 0;
    for (int i = pos; i <= res; i++) {
        if (rI == n2) {
            in[i] = leftCont[lI];
            lI++;
        } else if (lI == n1) {
            in[i] = rightCont[rI];
            rI++;
        } else if (rightCont[rI] > leftCont[lI]) {
            in[i] = leftCont[lI];
            lI++;
        } else {
            in[i] = rightCont[rI];
            rI++;
        }
    }
}

template <typename T>
void sort(T& in, int pos, int rest) {
    if (rest - pos > 2) {
        int q = (pos + rest) / 2;
        sort(in, pos, q);
        sort(in, q + 1, rest);
        merge(in, pos, q, rest);
    } else {
        insertionSort(in, pos, rest);
    }
}

void makeVect(char **argv, std::vector<int>& in) {
	for (int i = 0; argv[i]; i++)
	{
		if (isdigit(argv[i][0]) || argv[i][0] == '-')
			in.push_back(atoi(argv[i]));
		else
			return ((void)(std::cerr<<"Error: wrong input!"<<std::endl));
		if (atoi(argv[i]) == 0 && (argv[i][0] != '0' && (argv[i][0] == '-' && argv[i][1] != '0')))
			return ((void)(std::cerr<<"Error: wrong input! >> "<<argv[i]<<std::endl));
	}
}

void makeDeque(char **argv, std::deque<int>& in) {
	for (int i = 0; argv[i]; i++)
	{
		if (isdigit(argv[i][0]) || argv[i][0] == '-')
			in.push_back(atoi(argv[i]));
		else
			return ((void)(std::cerr<<"Error: wrong input!"<<std::endl));
		if (atoi(argv[i]) == 0 && (argv[i][0] != '0' && (argv[i][0] == '-' && argv[i][1] != '0')))
			return ((void)(std::cerr<<"Error: wrong input! >> "<<argv[i]<<std::endl));
	}
}

void PmergeMe::initiateSorting(char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;
	float	time_init;
	float	time_vec;
	float	time_deq;
	
	makeVect(argv, vec);
	std::cout<<"\033[0;32m\x1b[1mBefore: \033[0m";
	PrintCont(vec);
	time_init = clock();
    sort(vec, 0, vec.size() - 1);
	time_vec = clock() - time_init;
	makeDeque(argv, deq);
	time_init = clock();
    sort(deq, 0, deq.size() - 1);
	time_deq = clock() - time_init;
	std::cout<<"\033[0;31m\x1b[1mAfter (vect): \033[0m";
	PrintCont(deq);
	std::cout<<"\033[0;31m\x1b[1mAfter (deq): \033[0m";
	PrintCont(vec);
	std::cout<<"Time to process a range of "<< vec.size()<<" elements with std::vector :\t"<<time_vec / CLOCKS_PER_SEC * 1000<<std::endl;
	std::cout<<"Time to process a range of "<< deq.size()<<" elements with std::deque :\t"<<time_deq / CLOCKS_PER_SEC * 1000<<std::endl;
}