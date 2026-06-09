/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:31:26 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/09 19:08:58 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	this->arr = new	T[0]();
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->arr = new	T[n]();
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
	this->arr = new T[other._size]();
	for (unsigned int i = 0; i < other._size; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->arr;
		this->arr = new T[other._size]();
		this->_size = other._size;
		for (unsigned int i = 0; i < other._size; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
T&		Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (this->arr[index]);
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (this->arr[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}