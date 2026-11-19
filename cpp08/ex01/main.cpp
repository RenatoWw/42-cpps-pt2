/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:02:30 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/11/19 16:46:54 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <cstdlib>
#include <ctime>

void printHeader(std::string const & title)
{
	std::cout << "\n" << YELLOW << "=== " << title << " ===" << RESET << std::endl;
}

int	main(void)
{
	std::srand(std::time(NULL));

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
	printHeader("2. Teste de Excecoes (Capacidade e Tamanho 0)");
	try {
		Span sp2 = Span(2);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		std::cout << RED << "FALHA: Deveria lancar excecao ao exceder!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada: " << e.what() << RESET;
	}

	try {
		Span spZero = Span(0);
		spZero.addNumber(1);
		std::cout << RED << "FALHA: Deveria lancar excecao em Span(0)!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada (Span 0): " << e.what() << RESET;
	}

	// -------------------------------------------------------------------------
	printHeader("3. Teste de Excecoes (0 e 1 Elemento)");
	try {
		Span sp3 = Span(5);
		sp3.addNumber(42);
		sp3.shortestSpan();
		std::cout << RED << "FALHA: Deveria lancar excecao com 1 elemento!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada: " << e.what() << RESET;
	}

	try {
		Span sp4 = Span(5);
		sp4.longestSpan();
		std::cout << RED << "FALHA: Deveria lancar excecao com 0 elementos!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao capturada: " << e.what() << RESET;
	}

	// -------------------------------------------------------------------------
	printHeader("4. Teste addRange (std::vector, std::list e Array C)");
	try {
		Span sp5 = Span(12);
		
		std::vector<int> vec;
		for (int i = 0; i < 5; ++i)
			vec.push_back(i * 10); // 0, 10, 20, 30, 40

		std::list<int> lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(205);

		int arr[] = { -50, -20, 500, 1000 };

		sp5.addRange(vec.begin(), vec.end());
		sp5.addRange(lst.begin(), lst.end());
		sp5.addRange(arr, arr + 4);

		std::cout << "Shortest: " << sp5.shortestSpan() << " (Esperado: 5)" << std::endl;
		std::cout << "Longest: "  << sp5.longestSpan()  << " (Esperado: 1050)" << std::endl;

		// Tentando estourar a capacidade usando addRange
		sp5.addRange(vec.begin(), vec.end());
		std::cout << RED << "FALHA: addRange deveria lancar excecao!" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Excecao addRange capturada: " << e.what() << RESET;
	}

	// -------------------------------------------------------------------------
	printHeader("5. Teste de Numeros Negativos e Duplicados");
	try {
		Span spNeg = Span(5);
		spNeg.addNumber(-10);
		spNeg.addNumber(-50);
		spNeg.addNumber(-10); // Duplicado -> shortestSpan deve ser 0
		spNeg.addNumber(-5);
		std::cout << "Shortest (duplicados): " << spNeg.shortestSpan() << " (Esperado: 0)" << std::endl;
		std::cout << "Longest (negativos):   " << spNeg.longestSpan()  << " (Esperado: 45)" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
	}

	// -------------------------------------------------------------------------
	printHeader("6. Teste de Copia Profunda (Canonical Form)");
	try {
		Span original = Span(3);
		original.addNumber(10);
		original.addNumber(20);

		Span copia(original);
		Span atribuido = Span(10);
		atribuido = original;

		original.addNumber(1000); // Nao deve afetar copia nem atribuido

		std::cout << "Original Longest:  " << original.longestSpan()  << " (Esperado: 990)" << std::endl;
		std::cout << "Copia Longest:     " << copia.longestSpan()     << " (Esperado: 10)" << std::endl;
		std::cout << "Atribuido Longest: " << atribuido.longestSpan() << " (Esperado: 10)" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
	}

	// -------------------------------------------------------------------------
	printHeader("7. Teste Massivo Deterministico (15.000 Elementos)");
	try {
		unsigned int largeSize = 15000;
		Span spLarge = Span(largeSize);
		std::vector<int> largeVec;

		largeVec.reserve(largeSize);
		for (unsigned int i = 0; i < largeSize; ++i)
			largeVec.push_back(i * 3); // 0, 3, 6, ..., 44997

		spLarge.addRange(largeVec.begin(), largeVec.end());
		std::cout << "Foram adicionados " << largeSize << " numeros." << std::endl;
		std::cout << "Shortest Span: " << spLarge.shortestSpan() << " (Esperado: 3)" << std::endl;
		std::cout << "Longest Span : " << spLarge.longestSpan()  << " (Esperado: 44997)" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Erro inesperado: " << e.what() << RESET << std::endl;
	}
	return (0);
}