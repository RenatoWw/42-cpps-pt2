/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:02:30 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/08/12 18:18:17 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void printHeader(std::string const & title) {
    std::cout << "\n" << YELLOW << "=== " << title << " ===" << RESET << std::endl;
}

int	main(void)
{
	// -------------------------------------------------------------------------
	printHeader("1. Teste do Subject (Basico)");
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << " (Esperado: 2)" << std::endl;
		std::cout << "Longest: "  << sp.longestSpan()  << " (Esperado: 14)" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
	}

	// -------------------------------------------------------------------------
	printHeader("2. Teste de Excecoes (Capacidade)");
	try {
		Span sp2 = Span(2);
		sp2.addNumber(1);
		sp2.addNumber(2);
		std::cout << "Tentando adicionar o 3o elemento em um Span de max 2..." << std::endl;
		sp2.addNumber(3); // Deve lançar exceção
		std::cout << RED << "FALHA: Nenhuma excecao lancada!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada com sucesso: " << e.what() << RESET << std::endl;
	}

	// -------------------------------------------------------------------------
	printHeader("3. Teste de Excecoes (Falta de Elementos para Span)");
	try {
		Span sp3 = Span(5);
		sp3.addNumber(42);
		std::cout << "Tentando achar span com apenas 1 elemento..." << std::endl;
		sp3.shortestSpan(); // Deve lançar exceção
		std::cout << RED << "FALHA: Nenhuma excecao lancada!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada com sucesso: " << e.what() << RESET << std::endl;
	}

	try {
		Span sp4 = Span(5);
		std::cout << "Tentando achar span com 0 elementos..." << std::endl;
		sp4.longestSpan(); // Deve lançar exceção
		std::cout << RED << "FALHA: Nenhuma excecao lancada!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada com sucesso: " << e.what() << RESET << std::endl;
	}

	// // -------------------------------------------------------------------------
	// printHeader("4. Teste de Insercao via Iteradores (Range)");
	// try {
	// 	Span sp5 = Span(10);
	// 	std::vector<int> vec;
	// 	for (int i = 0; i < 10; ++i) {
	// 		vec.push_back(i * 10); // 0, 10, 20... 90
	// 	}
		
	// 	sp5.addNumber(vec.begin(), vec.end());
	// 	std::cout << "Range de 10 elementos adicionado com sucesso." << std::endl;
	// 	std::cout << "Shortest: " << sp5.shortestSpan() << " (Esperado: 10)" << std::endl;
	// 	std::cout << "Longest: "  << sp5.longestSpan()  << " (Esperado: 90)" << std::endl;
	// } catch (std::exception &e) {
	// 	std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
	// }

	// // -------------------------------------------------------------------------
	// printHeader("5. Teste Massivo (100.000 Elementos)");
	// try {
	// 	unsigned int largeSize = 100000;
	// 	Span spLarge = Span(largeSize);
	// 	std::vector<int> largeVec;
		
	// 	largeVec.reserve(largeSize);
	// 	for (unsigned int i = 0; i < largeSize; ++i) {
	// 		largeVec.push_back(std::rand()); // Numeros aleatorios
	// 	}

	// 	largeVec[0] = 0;           // Garantir o minimo
	// 	largeVec[1] = 2000000000;  // Garantir um maximo grande (perto do INT_MAX)
		
	// 	spLarge.addNumber(largeVec.begin(), largeVec.end());
	// 	std::cout << "Foram adicionados " << largeSize << " numeros." << std::endl;
		
	// 	std::cout << "Shortest Span: " << spLarge.shortestSpan() << std::endl;
	// 	std::cout << "Longest Span : " << spLarge.longestSpan() << std::endl;
	// 	std::cout << GREEN << "Busca em array massivo executada sem lentidao!" << RESET << std::endl;
	// } catch (std::exception &e) {
    //     std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
    // }
	return (0);
}
