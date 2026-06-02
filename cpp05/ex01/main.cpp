/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:03:54 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/05/26 15:45:40 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "=========================================" << std::endl;
	std::cout << "1. TESTANDO CRIAÇÃO E OPERADOR DE OUTPUT" << std::endl;
	std::cout << "=========================================" << std::endl;
	
	try {
		Form formA("Formulario A", 100, 50);
		std::cout << formA << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "2. TESTANDO EXCEÇÕES NA INSTANCIAÇÃO" << std::endl;
	std::cout << "=========================================" << std::endl;
	
	try {
		std::cout << "Tentando criar Form com nota para assinar = 0..." << std::endl;
		Form formHigh("Super Secreto", 0, 50);
	} catch (std::exception &e) {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}

	try {
		std::cout << "Tentando criar Form com nota para executar = 151..." << std::endl;
		Form formLow("Super Inutil", 50, 151);
	} catch (std::exception &e) {
		std::cout << "Exceção capturada: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "3. TESTANDO ASSINATURAS (SIGNFORM & BESIGNED)" << std::endl;
	std::cout << "=========================================" << std::endl;

	try {
		Bureaucrat estagiario("Estagiario", 150);
		Bureaucrat diretor("Diretor", 1);
		Form contrato("Contrato de Risco", 50, 50);

		std::cout << "Estado inicial do formulário:" << std::endl;
		std::cout << contrato << std::endl;

		// Estagiário tenta assinar (Nota 150 tentado assinar form de nota 50 - Deve falhar)
		std::cout << "\n" << estagiario.getName() << " tentando assinar..." << std::endl;
		estagiario.signForm(contrato);
		std::cout << contrato << std::endl; // Status deve continuar "não assinado"

		// Diretor tenta assinar (Nota 1 tentando assinar form de nota 50 - Deve passar)
		std::cout << "\n" << diretor.getName() << " tentando assinar..." << std::endl;
		diretor.signForm(contrato);
		std::cout << contrato << std::endl; // Status deve mudar para "assinado"

	} catch (std::exception &e) {
		std::cout << "Exceção inesperada capturada no fluxo principal: " << e.what() << std::endl;
	}

	return 0;
}