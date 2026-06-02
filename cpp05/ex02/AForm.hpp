/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:53:51 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 16:32:01 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			exec_grade;
	virtual void		executeAction() const = 0;

public:
	AForm();
	AForm(const std::string name, const int sign_grade, const int exec_grade);
	~AForm();
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	void		beSigned(const Bureaucrat &bureaucrat);
	std::string	getName() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	bool		getIsSigned() const;
	void		setIsSigned(bool is_signed);
	void		execute(Bureaucrat const &executor) const;

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

std::ostream& operator<<(std::ostream& out, const AForm& Form);

#endif