/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:08:33 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/08/12 18:19:02 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class	Span
{
private:
	std::vector<int>	span;
	unsigned long		size;

public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span&		operator=(const Span& other);

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

	class	ExceededNumberOfElements : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Span already at maximum capacity.\n");
			}
	};

	class	EmptySpan : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Empty Span.\n");
			}
	};

	class	OneElement : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Span with only one element.\n");
			}
	};
};

#endif