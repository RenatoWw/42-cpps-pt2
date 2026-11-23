/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:29:25 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/11/23 15:06:45 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Error: could not open file.\n";
}

BitcoinExchange::BitcoinExchange(char *filename)
{
	std::ifstream input(filename);
	// verificar se deu certo a abertura
	this->file_name = filename;
	std::string		line;

	getline(input, line);
	checkHeader(line);

	getline(input, line);
	std::cout << "line: " << line << "\n";
	validateLine(line);
	input.close();
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : file_name(other.file_name)
{

}

BitcoinExchange&		BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->file_name = other.file_name;
	}
	return (*this);
}

int	BitcoinExchange::checkHeader(std::string line)
{
	if (!(line == "date | value"))
	{
		std::cout << "Error: bad input => " << line << "\n";
		return (0);
	}
	return (1);
}

int	BitcoinExchange::validateLine(std::string line)
{
	// validate pipe
	// se a primeira condição der errado ele roda a segunda?
	if (validateDate(line.substr(0, 10)) && validateNumber(line.substr(13)))
	{
		std::cout << "string ok\n";
	}
	else
	{
		std::cout << "string errada\n";
		// printError(line);
	}
	std::cout << line << "\n";
	return (1);
}

int	BitcoinExchange::validateDate(std::string date)
{
	std::cout << "date: " << date << "\n";
	if (date.length() != 10)
	{
		std::cout << "Error: bad input => " << date << "\n";
		return (0);
	}
	if (date[4] != '-' && date[7] != '-')
	{
		std::cout << "Error: bad input => " << date << "\n";
		return (0);
	}
	
	return (1);
}

int	BitcoinExchange::validateNumber(std::string num)
{
	std::cout << "num: " << num << "\n";
	return (1);
}
