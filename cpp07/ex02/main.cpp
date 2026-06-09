/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:09:12 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/09 19:11:42 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() 
{
	try 
	{
		std::cout << "--- 1. Testando Array de Inteiros ---" << std::endl;
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); i++) {
			intArray[i] = i * 10;
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}

		std::cout << "\n--- 2. Testando Cópia Profunda (Deep Copy) ---" << std::endl;
		Array<int> copyArray(intArray);
		std::cout << "Modificando a cópia..." << std::endl;
		copyArray[0] = 999; 
		
		std::cout << "intArray[0] original: " << intArray[0] << " (deve continuar 0)" << std::endl;
		std::cout << "copyArray[0] copiado: " << copyArray[0] << " (deve ser 999)" << std::endl;

		std::cout << "\n--- 3. Testando Tipos Diferentes (std::string) ---" << std::endl;
		Array<std::string> strArray(2);
		strArray[0] = "Olá";
		strArray[1] = "Mundo";
		std::cout << strArray[0] << " " << strArray[1] << "!" << std::endl;

		std::cout << "\n--- 4. Testando Exceção (Fora dos Limites) ---" << std::endl;
		std::cout << "Tentando acessar intArray[10]..." << std::endl;
		std::cout << intArray[10] << std::endl;

	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what();
	}

	std::cout << "\n--- 5. Testando Array Vazio ---" << std::endl;
		Array<float> emptyArray;
		std::cout << "Tamanho do emptyArray: " << emptyArray.size() << " (deve ser 0)" << std::endl;
		try 
		{
			std::cout << "Tentando acessar o índice 0 de um array vazio..." << std::endl;
			std::cout << emptyArray[0] << std::endl; 
		} 
		catch (const std::exception& e) 
		{
			std::cerr << "Exceção capturada (esperado): " << e.what();
		}
	return 0;
}
