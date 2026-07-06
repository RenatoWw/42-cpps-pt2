/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:38:39 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/07/06 16:01:14 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::cout << "================ VECTOR ================\n";
	std::vector<int>			numbersVector;
	std::vector<int>::iterator	itV;

	numbersVector.push_back(1);
	numbersVector.push_back(10);
	numbersVector.push_back(20);
	numbersVector.push_back(30);
	numbersVector.push_back(40);
	numbersVector.push_back(50);
	printContainer(numbersVector);
	std::cout << "================ Tentando achar o número 20 ================\n";
	try
	{
		itV = easyfind(numbersVector, 20);
		std::cout << "value: " << *itV << std::endl;
		std::cout << "index: " << std::distance(numbersVector.begin(), itV) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "================ Tentando achar o número 60 ================\n";
	try
	{
		itV = easyfind(numbersVector, 60);
		std::cout << "value: " << *itV << std::endl;
		std::cout << "index: " << std::distance(numbersVector.begin(), itV) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	
	std::cout << "================ LIST ================\n";

	std::list<int>				numbersList;
	std::list<int>::iterator	itL;

	numbersList.push_back(2);
	numbersList.push_back(4);
	numbersList.push_back(6);
	numbersList.push_back(8);
	numbersList.push_back(10);
	numbersList.push_back(12);

	printContainer(numbersList);

	std::cout << "================ Tentando achar o número 12 ================\n";
	try
	{
		itL = easyfind(numbersList, 12);
		std::cout << "value: " << *itL << std::endl;
		std::cout << "index: " << std::distance(numbersList.begin(), itL) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "================ Tentando achar o número 14 ================\n";
	try
	{
		itL = easyfind(numbersList, 14);
		std::cout << "value: " << *itL << std::endl;
		std::cout << "index: " << std::distance(numbersList.begin(), itL) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}

		std::cout << "================ DEQUE ================\n";

	std::deque<int>				numbersDeque;
	std::deque<int>::iterator	itD;

	numbersDeque.push_back(1);
	numbersDeque.push_back(3);
	numbersDeque.push_back(5);
	numbersDeque.push_back(7);
	numbersDeque.push_back(9);
	numbersDeque.push_back(11);

	printContainer(numbersDeque);

	std::cout << "================ Tentando achar o número 7 ================\n";
	try
	{
		itD = easyfind(numbersDeque, 7);
		std::cout << "value: " << *itD << std::endl;
		std::cout << "index: " << std::distance(numbersDeque.begin(), itD) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "================ Tentando achar o número 13 ================\n";
	try
	{
		itD = easyfind(numbersDeque, 13);
		std::cout << "value: " << *itD << std::endl;
		std::cout << "index: " << std::distance(numbersDeque.begin(), itD) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
