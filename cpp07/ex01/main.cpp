/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/06/09 17:18:53 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printElem(int &elem)
{
	std::cout << elem << " ";
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "No arguments supported, try again!\n"
					<< "type in ./iter"
					<< std::endl;
		return (1);
	}

	int	testArr[4] = {1, 2, 3, 4};
	const int testArr2[4] = {2, 4, 8, 10};

	std::cout	<< "========= TEMPLATE / REGULAR FUNC TEST ========="
				<< std::endl << std::endl;

	std::cout << "Test array: ";
	::iter(testArr, 4, printElem);
	std::cout << std::endl;
	std::cout << "Running increment template function: " << std::endl;
	::iter(testArr, 4, ::incrementElem<int>);
	std::cout << "Test array: ";
	::iter(testArr, 4, printElem);
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout	<< "========= CONST ARRAY TEST ========="
				<< std::endl << std::endl;

	std::cout << "Test array2: ";
	::iter(testArr2, 4, ::printConstElem<const int>);
	std::cout << std::endl;

	std::cout << std::endl;

	return 0;
}