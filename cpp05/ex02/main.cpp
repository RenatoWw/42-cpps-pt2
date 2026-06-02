/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:38:11 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 17:51:25 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat boss("Chefe", 1);
	std::cout << "--- CENÁRIO 1: Burocrata com nível suficiente para tudo ---" << std::endl;
	try
	{
		std::cout << "\e[0;32m================ Shrubbery test ================\e[0m\n";
		ShrubberyCreationForm form1("jardim");

		boss.signForm(form1);
		std::cout << "\n";
		boss.executeForm(form1);
		std::cout << "\n\e[0;32m================================\e[0m\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\e[0;32m================ Presidential test ================\e[0m\n";
		PresidentialPardonForm form1("zézão");

		boss.signForm(form1);
		std::cout << "\n";
		boss.executeForm(form1);
		std::cout << "\n\e[0;32m================================\e[0m\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\e[0;32m================ Robotomy test ================\e[0m\n";
		RobotomyRequestForm form1("robocop");

		boss.signForm(form1);
		std::cout << "\n";
		boss.executeForm(form1);
		std::cout << "\n\e[0;32m================================\e[0m\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada: " << e.what() << std::endl;
	}

	std::cout << "\n--- CENÁRIO 2: Burocrata com nível muito baixo para assinar ---" << std::endl;
	try
	{
		// Nível 150 é maior/pior que 145, então não deve conseguir assinar
		Bureaucrat intern("Estagiario", 150);
		ShrubberyCreationForm form2("Quintal");

		std::cout << intern << std::endl;

		intern.signForm(form2);
		intern.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada: " << e.what() << std::endl;
	}

	std::cout << "\n--- CENÁRIO 3: Burocrata assina, mas não pode executar ---" << std::endl;
	try
	{
		// Nível 140 é suficiente para assinar (<= 145), mas falha ao executar (> 137)
		Bureaucrat junior("Junior", 140);
		ShrubberyCreationForm form3("Praca");

		std::cout << junior << std::endl;

		junior.signForm(form3);
		junior.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exceção capturada: " << e.what() << std::endl;
	}

	return 0;
}
