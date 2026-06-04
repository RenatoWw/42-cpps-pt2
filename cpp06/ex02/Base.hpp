/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:37:22 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 15:50:13 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

class	Base
{
public:
	virtual	~Base();
};

class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
