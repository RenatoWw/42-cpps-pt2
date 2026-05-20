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

#include <Form.hpp>

Form::Form() : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "Form: default constructor called\n";
}
Form::Form(const std::string name, const int sign_grade, const int exec_grade) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "Form: default constructor called\n";

}

Form::~Form()
{
	std::cout << "Form: deconstructor called\n";
}

Form::Form(const Form& other) : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
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

void		Form::beSigned(const Bureaucrat &bureaucrat);
std::string	Form::getName() const;
int			Form::getSignGrade() const;
int			Form::getExecuteGrade() const;
int			Form::getIsSigned() const;

std::ostream& operator<<(std::ostream& out, const Form& Form);