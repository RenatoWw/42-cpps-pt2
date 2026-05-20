/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:03:54 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/05/20 16:08:45 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "       TESTES DO BUREAUCRAT              " << std::endl;
	std::cout << "=========================================\n" << std::endl;

	std::cout << "--- 1. Teste de Instanciação Válida e Operador '<<' ---" << std::endl;
	try
	{
		Bureaucrat hermes("Hermes", 42);
		std::cout << "Criado com sucesso: " << hermes << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Erro inesperado: " << e.what() << std::endl;
	}

	std::cout << "\n--- 2. Teste: Instanciação com Grade Muito Alta (0) ---" << std::endl;
	try
	{
		Bureaucrat god("Deus da Burocracia", 0);
		std::cout << god << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	std::cout << "\n--- 3. Teste: Instanciação com Grade Muito Baixa (151) ---" << std::endl;
	try
	{
		Bureaucrat zoidberg("Zoidberg", 151);
		std::cout << zoidberg << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	std::cout << "\n--- 4. Teste: Incremento e Decremento Válidos ---" << std::endl;
	try
	{
		Bureaucrat fry("Fry", 100);
		std::cout << "Inicial: " << fry << std::endl;
		
		fry.incrementGrade();
		std::cout << "Após incremento (deve ser 99): " << fry << std::endl;
		
		fry.decrementGrade();
		std::cout << "Após decremento (deve voltar para 100): " << fry << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Erro inesperado: " << e.what() << std::endl;
	}

	std::cout << "\n--- 5. Teste: Incremento Inválido (Ultrapassar Grade 1) ---" << std::endl;
	try
	{
		Bureaucrat boss("Chefe", 1);
		std::cout << boss << std::endl;
		std::cout << "Tentando promover o Chefe..." << std::endl;
		boss.incrementGrade();
		std::cout << boss << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	std::cout << "\n--- 6. Teste: Decremento Inválido (Ultrapassar Grade 150) ---" << std::endl;
	try
	{
		Bureaucrat intern("Estagiário", 150);
		std::cout << intern << std::endl;
		std::cout << "Tentando rebaixar o Estagiário..." << std::endl;
		intern.decrementGrade();
		std::cout << intern << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "             FIM DOS TESTES              " << std::endl;
	std::cout << "=========================================" << std::endl;

	return 0;
}