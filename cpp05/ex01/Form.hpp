/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:53:51 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/05/20 17:00:36 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			exec_grade;

public:
	Form();
	Form(const std::string name, const int sign_grade, const int exec_grade);
	~Form();
	Form(const Form& other);
	Form&	operator=(const Form& other);
	void		beSigned(const Bureaucrat &bureaucrat);
	std::string	getName() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	bool		getIsSigned() const;

	class		GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class		GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif