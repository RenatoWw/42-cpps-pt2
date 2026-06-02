/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:39:47 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 16:52:53 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("zezinho")
{
	std::cout << "PresidentialPardonForm: default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm: parametrized constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: deconstructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm: copy constructor called\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm: copy assignment operator called\n";
	if (this != &other)
	{
		this->target = other.target;
	}
	setIsSigned(other.getIsSigned());
	return (*this);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}
