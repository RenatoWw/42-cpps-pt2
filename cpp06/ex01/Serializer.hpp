/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:57:39 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 15:20:52 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <stdint.h>

class	Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();	
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif