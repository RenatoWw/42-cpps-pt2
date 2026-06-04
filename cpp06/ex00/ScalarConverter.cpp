/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:15:58 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 14:53:04 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::is_char(std::string value)
{
	if (value.length() == 3 && (value[0] == '\'' && value[2] == '\''))
		return (true);
	else if (value.length() == 1 && !std::isdigit(value[0]))
		return (true);
	else
		return (false);
}

bool	ScalarConverter::is_int(std::string value)
{
	int	start = 0;
	int	i;

	if (value[0] == '-' || value[0] == '+')
		start = 1;
	for (i = start; value[i]; i++)
	{
		if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::is_float(std::string value)
{
	int	len;
	int	dot;

	if (value == "nanf" || value == "+inff" || value == "-inff")
        return (true);
	dot = 0;
	len = value.length();
	if (value[len - 1] != 'f')
		return (false);
	for (int i = 0; value[i]; i++)
	{
		if (value[i] == '.')
		{
			dot = i;
			break ;
		}
	}
	for (int i = dot + 1; i < len - 1; i++)
	{
		if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::is_double(std::string value)
{
	int	len;
	int	dot;

	if (value == "nan" || value == "+inf" || value == "-inf")
        return true;
	dot = 0;
	len = value.length();
	for (int i = 0; value[i]; i++)
	{
		if (value[i] == '.')
		{
			dot = i;
			break ;
		}
	}
	for (int i = dot + 1; i < len; i++)
	{
		if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

void	ScalarConverter::print_conversions(char c)
{
	if (c < 0 || c > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(c))
		std::cout << "char: " << "Non displayable\n";
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	ScalarConverter::print_conversions(long i)
{
	if (i < INT_MIN || i > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::print_conversions(float f)
{
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
	{
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void	ScalarConverter::print_conversions(double d)
{
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << "\n";
	}
}

void	ScalarConverter::convert_char(std::string value)
{
	char	original_val;

	if (value[0] == '\'')
		original_val = value[1];
	else
		original_val = value[0];
	long		int_val = static_cast<int>(original_val);
	float		float_val = static_cast<float>(original_val);
	double		double_val = static_cast<double>(original_val);

	print_conversions(original_val);
	print_conversions(int_val);
	print_conversions(float_val);
	print_conversions(double_val);
}

void	ScalarConverter::convert_int(std::string value)
{
	long	original_val = std::atol(value.c_str());
	char	char_val = static_cast<char>(original_val);
	float	float_val = static_cast<float>(original_val);
	double	double_val = static_cast<double>(original_val);

	print_conversions(char_val);
	print_conversions(original_val);
	print_conversions(float_val);
	print_conversions(double_val);
}

void	ScalarConverter::convert_float(std::string value)
{
	float	original_val = std::atof(value.c_str());
	double	double_val = static_cast<double>(original_val);
	
	if (std::isnan(original_val) || std::isinf(original_val))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else
	{
		long	int_val = static_cast<int>(original_val);
		char	char_val = static_cast<char>(original_val);
		print_conversions(char_val);
		print_conversions(int_val);		
	}
	print_conversions(original_val);
	print_conversions(double_val);
}

void	ScalarConverter::convert_double(std::string value)
{
	double	original_val = std::atof(value.c_str());
	float	float_val = static_cast<float>(original_val);
	
	if (std::isnan(original_val) || std::isinf(original_val))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else
	{
		char	char_val = static_cast<char>(original_val);
		long	int_val = static_cast<int>(original_val);
		print_conversions(char_val);
		print_conversions(int_val);		
	}
	print_conversions(float_val);
	print_conversions(original_val);
}

void	ScalarConverter::invalid_value()
{
	std::cout << "Error: invalid literal.\n";
}

void	ScalarConverter::convert(std::string value)
{
	if (is_char(value))
		convert_char(value);
	else if (is_int(value))
		convert_int(value);
	else if (is_float(value))
		convert_float(value);
	else if (is_double(value))
		convert_double(value);
	else
		invalid_value();
}
