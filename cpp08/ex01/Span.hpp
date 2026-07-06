/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:08:33 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/07/06 16:16:48 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <vector>

class	Span
{
private:
	std::vector<int>	span;

public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span&		operator=(const Span& other);

	void	addNumber();
	void	shortestSpan();
	void	longestSpan();

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