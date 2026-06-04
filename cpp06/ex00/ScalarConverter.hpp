/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:20:11 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 13:16:10 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <climits>

class	ScalarConverter
{
public:
	static void	convert(std::string value);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool	is_char(std::string value);
	static bool	is_int(std::string value);
	static bool	is_float(std::string value);
	static bool	is_double(std::string value);

	static void	print_conversions(char c);
	static void	print_conversions(long i);
	static void	print_conversions(float f);
	static void	print_conversions(double d);

	static void	convert_char(std::string value);
	static void	convert_int(std::string value);
	static void	convert_float(std::string value);
	static void	convert_double(std::string value);
	static void	invalid_value();
};

#endif