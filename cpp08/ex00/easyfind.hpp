/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:44:24 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/07/06 16:01:07 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>

class	ElementNotFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Element not found.\n");
		}
};


template <typename T>
void	printContainer(T& container)
{
	typename T::iterator	it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
typename	T::iterator	easyfind(T& container, int occurence)
{
	typename T::iterator	iterator;

	iterator = find(container.begin(), container.end(), occurence);
	if (iterator == container.end())
		throw ElementNotFound();
	return (iterator);
}

#endif