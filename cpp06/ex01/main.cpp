/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:01:26 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 15:27:56 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

int	main(void)
{
	Data*		ptr;
	Data*		serialized;
	uintptr_t	raw;

	ptr = new Data;
	ptr->name = "zezinho";
	ptr->age = 99;

	raw = Serializer::serialize(ptr);
	serialized = Serializer::deserialize(raw);
	
	std::cout << "Default data: \n";
	std::cout << "name: " << ptr->name << "\nage: " << ptr->age << std::endl;
	
	std::cout << "\nSerialized data: \n";
	std::cout << "name: " << serialized->name << "\nage: " << serialized->age << std::endl;
	delete ptr;
	return (0);
}
