/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:20:11 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 21:25:13 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum	Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class	ScalarConverter
{
public:
	static void	convert(std::string value);
private:
	ScalarConverter();
};

#endif