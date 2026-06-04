/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:03:40 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 15:21:50 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data*	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
