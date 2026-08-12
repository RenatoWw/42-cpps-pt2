/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:08:06 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/08/12 18:27:02 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	throw EmptySpan();
}

Span::Span(unsigned int N)
{
	span.reserve(N);
	this->size = N;
}

Span::~Span()
{
}

Span::Span(const Span& other)
{
	this->span = other.span;
	this->size = other.size;
}

Span&		Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->span = other.span;
		this->size = other.size;
	}
	return (*this);
}


void	Span::addNumber(int num)
{
	if (this->size <= this->span.size())
		throw ExceededNumberOfElements();
	else
		span.push_back(num);
}

int	Span::shortestSpan()
{
	std::vector<int>	temp;
	int					shortest_span = std::numeric_limits<int>::max();
	int					current_span;

	if (span.size() == 1)
		throw OneElement();
	if (span.size() == 0)
		throw EmptySpan();
	temp = this->span;
	std::sort(temp.begin(), temp.end());
	// std::cout << "\ntemp: " << temp[0] << "\n";
	for (size_t i = 0; i < temp.size(); ++i)
	{
		current_span = temp[i] - temp[i - 1];
		std::cout << "current_span: " << current_span << "\n";
		if (current_span > shortest_span)
			shortest_span = current_span;
	}
	return (shortest_span);
	
}

int	Span::longestSpan()
{
	std::vector<int>	temp;
	int					longest_span = 1;
	int					current_span = 1;

	if (span.size() == 1)
		throw OneElement();
	if (span.size() == 0)
		throw EmptySpan();
	temp = this->span;
	for (size_t i = 0; i < temp.size(); ++i)
	{
		if (temp[i] == temp[i - 1])
			current_span++;
		else
		{
			longest_span = std::max(longest_span, current_span);
			current_span = 1;
		}
	}
	return (longest_span);
	
}
