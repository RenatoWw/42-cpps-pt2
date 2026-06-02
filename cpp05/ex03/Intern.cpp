/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:50:33 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 19:20:13 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() : form("shruberry"), form_target("default")
{
	std::cout << "Intern: default constructor called\n";
}

Intern::Intern(std::string form, std::string form_target) : form(form), form_target(form_target)
{
	std::cout << "Intern: parametrized constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern: deconstructor called\n";
}

Intern::Intern(const Intern& other) : form(other.form), form_target(other.form_target)
{
	std::cout << "Intern: copy constructor called\n";
}

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "Intern: copy assignment operator called\n";
	if (this != &other)
	{
		this->form = other.form;
		this->form_target = other.form_target;
	}
	return (*this);
}

AForm*	createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm*	createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
	
}
AForm*	createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string form, std::string form_target)
{
	std::string	forms[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	AForm*	(*form_pointers_arr[])(std::string) = {
		&createRobotomy,
		&createPresidential,
		&createShrubbery
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return form_pointers_arr[i](form_target);
		}
	}
	std::cout << "Intern couldn't create form " << form << std::endl;
	return (NULL);
}
