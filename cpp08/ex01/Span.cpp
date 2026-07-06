/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:08:06 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/07/06 16:20:34 by ranhaia-         ###   ########.fr       */
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
}

Span::~Span()
{

}

Span::Span(const Span& other)
{

}

Span&		Span::operator=(const Span& other)
{

}


void	Span::addNumber()
{

}

void	Span::shortestSpan()
{

}

void	Span::longestSpan()
{

}
