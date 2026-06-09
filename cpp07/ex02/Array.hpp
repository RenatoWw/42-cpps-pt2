/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:25:16 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/09 19:08:52 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{
private:
	T*				arr;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array<T>& other);
	Array<T>&		operator=(const Array<T>& other);
	T&		operator[](size_t index);
	const T&	operator[](size_t index) const;

	class	OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of bounds of array\n");
			}
	};
	unsigned int	size() const;
};

# include "Array.tpp"

#endif