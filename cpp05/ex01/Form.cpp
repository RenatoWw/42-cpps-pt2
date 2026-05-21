/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:59:10 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/05/20 17:04:44 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), is_signed(false), sign_grade(150), exec_grade(150)
{
	std::cout << "Form: default constructor called\n";
}
Form::Form(const std::string name, const int sign_grade, const int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form: parameterized constructor called\n";
}

Form::~Form()
{
	std::cout << "Form: deconstructor called\n";
}

Form::Form(const Form& other) : name(other.name), is_signed(false), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	std::cout << "Form: copy constructor called\n";
}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form: copy assignment operator called\n";
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::string	Form::getName() const
{
	return (this->name);
}

int			Form::getSignGrade() const
{
	return (this->sign_grade);
}

int			Form::getExecuteGrade() const
{
	return (this->exec_grade);
}

bool		Form::getIsSigned() const
{
	return (this->is_signed);
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << "Form name: " << Form.getName() << std::endl;
	out << "Form sign grade: " << Form.getSignGrade() << std::endl;
	out << "Form execute grade: " << Form.getExecuteGrade() << std::endl;
	out << "Form is signed: " << Form.getIsSigned() << std::endl;
	return (out);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}


