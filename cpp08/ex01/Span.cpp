/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:08:06 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/11/19 16:40:59 by ranhaia-         ###   ########.fr       */
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

unsigned int	Span::shortestSpan()
{
	std::vector<int>	temp;
	long				shortest_span = std::numeric_limits<unsigned int>::max();
	long				current_span;

	if (span.size() == 1)
		throw OneElement();
	if (span.size() == 0)
		throw EmptySpan();
	temp = this->span;
	std::sort(temp.begin(), temp.end());
	for (size_t i = 1; i < temp.size(); i++)
	{
		current_span = static_cast<unsigned int>(temp[i]) - static_cast<unsigned int>(temp[i - 1]);
		if (current_span < shortest_span)
			shortest_span = current_span;
	}
	return (static_cast<unsigned int>(shortest_span));
	
}

unsigned int	Span::longestSpan()
{
	if (span.size() == 1)
		throw OneElement();
	if (span.size() == 0)
		throw EmptySpan();
	std::sort(span.begin(), span.end());
	return (static_cast<unsigned int>(span.back()) - static_cast<unsigned int>(span.front()));
}
