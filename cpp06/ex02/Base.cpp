/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:40:45 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 16:10:46 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	generate(void)
{
	int	random;

	srand(time(0));
	random = rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
	
}

Base::~Base()
{
}
