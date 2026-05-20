/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:42:57 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/05/20 16:20:47 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("zézinho")
{
	std::cout << "Bureaucrat: default constructor called\n";
	this->grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat: constructor called\n";
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: deconstructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	std::cout << "Bureaucrat: copy constructor called\n";
	this->grade = other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: copy assignment operator called\n";
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return (out);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

