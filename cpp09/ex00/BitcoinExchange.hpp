/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:29:12 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/11/23 15:04:11 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>

class	BitcoinExchange
{
private:
	std::string	file_name;

public:
	BitcoinExchange();
	BitcoinExchange(char *filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&		operator=(const BitcoinExchange& other);

	int		checkHeader(std::string line);
	int		validateLine(std::string line);
	int		validateDate(std::string date);
	int		validateNumber(std::string num);
};

#endif