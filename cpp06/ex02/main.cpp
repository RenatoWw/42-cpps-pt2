/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:37:25 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/04 16:07:04 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "--- Teste " << i + 1 << " ---" << std::endl;
		
		Base* random_obj = generate();
		std::cout << "Resultado usando ponteiro (Base*): ";
		identify(random_obj);

		std::cout << "Resultado usando referencia (Base&): ";		
		identify(*random_obj);

		delete random_obj;
		std::cout << std::endl;
	}
	return (0);
}
