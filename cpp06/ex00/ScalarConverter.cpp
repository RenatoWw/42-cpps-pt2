/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:15:58 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 21:31:04 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	is_char(std::string value)
{
	
}

static int	is_int(std::string value)
{
	
}

static int	is_float(std::string value)
{
	
}

static int	is_double(std::string value)
{
	
}

static int	check_type(std::string value)
{
	if (is_char(value))
		return (CHAR);
	else if (is_int(value))
		return (INT);
	else if (is_float(value))
		return (FLOAT);
	else if (is_double(value))
		return (DOUBLE);
	else
		return (4);
}

// void print_conversions(char c);
// void print_conversions(int i);
// void print_conversions(float f);
// void print_conversions(double d);

void	ScalarConverter::convert(std::string value)
{
	int	type;

	std::cout << "oi " << value << std::endl;
	type = check_type(value);
	// convert_type
	// -> converter pra char e printar
	// -> converter pra int e printar
	// -> converter pra float e printar
	// -> converter pra double e printar
}
