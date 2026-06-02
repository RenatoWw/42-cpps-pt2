/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:59:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 16:31:35 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), is_signed(false), sign_grade(150), exec_grade(150)
{
	std::cout << "AForm: default constructor called\n";
}
AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm: parameterized constructor called\n";
}

AForm::~AForm()
{
	std::cout << "AForm: deconstructor called\n";
}

AForm::AForm(const AForm& other) : name(other.name), is_signed(false), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	std::cout << "AForm: copy constructor called\n";
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "AForm: copy assignment operator called\n";
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

void		AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::string	AForm::getName() const
{
	return (this->name);
}

int			AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int			AForm::getExecuteGrade() const
{
	return (this->exec_grade);
}

bool		AForm::getIsSigned() const
{
	return (this->is_signed);
}

void		AForm::setIsSigned(bool _is_signed)
{
	this->is_signed = _is_signed;
}

void		AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == false)
		std::cout << "not signed\n";
	if (this->exec_grade < executor.getGrade())
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm name: " << AForm.getName() << std::endl;
	out << "AForm sign grade: " << AForm.getSignGrade() << std::endl;
	out << "AForm execute grade: " << AForm.getExecuteGrade() << std::endl;
	out << "AForm is signed: " << AForm.getIsSigned() << std::endl;
	return (out);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}


