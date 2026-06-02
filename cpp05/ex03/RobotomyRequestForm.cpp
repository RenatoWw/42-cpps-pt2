/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:06:52 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 17:09:09 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("robocop")
{
	std::cout << "RobotomyRequestForm: default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm: parametrized constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: deconstructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm: copy constructor called\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm: copy assignment operator called\n";
	if (this != &other)
	{
		this->target = other.target;
	}
	setIsSigned(other.getIsSigned());
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	int	random;

	srand(time(0));
	random = rand() % 2;
	if (random == 0)
		std::cout << "Bzzzzzzzzzzzzzzz... " << this->target << " has been robotomized.\n";
	else
		std::cout << this->target << " has NOT been robotomized.\n";
}
