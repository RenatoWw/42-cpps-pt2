/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:20:14 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/09 17:17:42 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	incrementElem(T &elem)
{
	 elem++;
}

template <typename T>
void	printConstElem(const T &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	iter(T *arr, const int len, void (*func)(T &))
{
	int	i;

	if (!arr | !func)
		return ;
	i = 0;
	while (i < len)
		func(arr[i++]);
}

template <typename T>
void	iter(const T *arr, const int len, void (*func)(T const &))
{
	int	i;

	if (!arr | !func)
		return ;
	i = 0;
	while (i < len)
		func(arr[i++]);
}

#endif
