/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:47:24 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 19:11:32 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
private:
	std::string	form;
	std::string	form_target;

public:
	Intern();
	Intern(std::string form, std::string form_target);
	~Intern();
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);

	AForm*	makeForm(std::string form, std::string form_target);
};

AForm*	createRobotomy(std::string target);
AForm*	createShrubbery(std::string target);
AForm*	createPresidential(std::string target);

#endif