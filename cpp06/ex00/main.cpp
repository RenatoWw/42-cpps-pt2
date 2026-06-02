/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:16:01 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 20:32:45 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::string	value;

	if (argc != 2)
	{
		std::cout << "Usage: ./convert <value>\n";
		return (1);
	}
	value = argv[1];
	ScalarConverter::convert(value);
}
