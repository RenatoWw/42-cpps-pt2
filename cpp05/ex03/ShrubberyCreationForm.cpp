/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:10:15 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 19:21:11 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("arvorezinha")
{
	std::cout << "ShrubberyCreationForm: default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm: parametrized constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: deconstructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm: copy constructor called\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm: copy assignment operator called\n";
	if (this != &other)
	{
		this->target = other.target;
	}
	setIsSigned(other.getIsSigned());
	return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
	std::string	path = this->target + "_shrubbery";
	std::ofstream	arvore(path.c_str());
	if (!arvore.is_open())
	{
		throw	OpenFileException();
	}
	arvore <<
	"⠀⠀⠀           ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣀⠀⠀⢀⠀⢐⡜⠀⡀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠇⠀⡄⠀⣆⣸⡀⣆⠈⣤⢿⠆⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣤⣀⡀⠸⡀⢿⢢⣀⣿⣇⣻⡿⠿⣯⠂⠀⠰⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢥⠀⠈⢢⣷⢀⢹⡛⢻⠋⠉⠳⡴⠃⢠⠤⠒⠚⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣈⡃⠉⠛⠲⡹⣹⣄⣀⠃⣯⡧⣿⠉⠉⠁⡀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⠀⣈⢧⣱⣄⣄⠀⠈⢻⢻⣯⡵⠃⢰⣚⣛⣛⡟⠀⢀⡸⡀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠛⢻⣉⣁⢀⢀⡈⠕⠤⢬⡙⣾⡦⢴⣃⣀⡜⠁⠀⢈⡥⠖⠃⡩⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠘⢟⣏⣿⣍⡉⢩⡙⢠⣤⠊⠉⣷⠃⣿⣾⠟⠛⠒⠒⢲⢭⢹⠥⢬⠔⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠙⣆⡈⣇⠙⣄⡀⢘⡾⢻⡇⣄⣠⢤⣦⣤⠞⠊⠁⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣨⣯⡷⠶⠒⠿⠓⠶⠾⢟⣿⣷⣿⣿⣿⢿⡏⠀⠀⡀⢀⣄⣀⡴⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⢏⡟⡆⠀⢀⡺⠛⣛⣳⣏⠶⣿⣿⣿⣧⠼⠟⡷⠿⣻⠻⠻⡿⠷⡷⠆⣀⡀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠃⣠⡾⣓⡒⠚⠤⠋⢌⣰⠋⠀⢻⣿⡿⡝⠦⣠⠃⠀⠀⠀⠀⠀⠘⠃⠀⠀⠈⠓⠄⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠀⠈⠉⠁⠀⠀⠀⠀⠔⠁⠀⠀⠸⣿⡇⠀⠀⠈⢣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⣶⣶⣦⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣷⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	"⣿⣽⣏⣛⣿⠿⠷⠶⠶⠦⢤⣤⣄⣀⣀⣀⣀⣀⣀⣀⣤⣀⠀⣀⣀⣀⣄⣀⣠⣤⣤⣤⣤⣤⣤⣤⣤⣴⡶⠶⠶⠞⠋⠉⣉⣙⣻⣶⣤⣤⣤⣤⣤⣄⣠⡤⢤⣤⣄⣀⣀⣀⣀⣀⣀\n"
	"⣿⣿⣿⣿⣿⣷⣶⣿⣿⠷⠶⠟⠛⠛⠻⠋⠛⣋⣉⣭⣭⣽⠿⠿⢿⣿⣟⣛⣛⣛⣿⣯⣝⣛⠓⢀⠺⠤⣤⣶⢒⣛⣟⠛⠋⠉⣩⣭⣉⣉⣭⣼⣿⣿⡿⠿⠶⠾⠻⠿⠛⠋⠉⡉⠉\n"
	"⡿⠿⠛⠛⠋⠉⠉⠁⣀⣤⣤⣤⣶⣶⣶⡾⣿⣿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣭⡿⠿⠿⠿⠯⢛⣛⢿⣛⣦⣬⣥⣬⣽⣶⣶⣶⠿⠛⠛⠟⠛⠛⠩⠭⠁⠀⠐⠂⠀⠈⠁⠀⠠⣤⣤⣤\n"
	"⣠⣴⣴⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣷⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢟⡛⠉⠉⠍⠀⠀⠀⠀⠉⠉⠉⢀⣂⣀⢁⣀⣀⡀⢬⣿⣳⡶⠶⣶⡖⠒⠁⠩⠹\n"
	"⢿⣿⣿⣿⣿⣷⣿⣿⡛⣛⣛⣋⣉⣭⣩⣽⣿⣿⡿⠿⣿⡿⠿⠿⠿⠟⠛⠋⠉⠛⠛⠉⠉⠉⠉⢁⣀⣀⣀⣀⣠⣄⡒⠠⡲⠶⡓⢚⣐⡛⢩⡨⠭⠃⢀⠈⠉⢉⣁⣰⣦⣄⣉⣡⣭\n"
	"⣌⣿⣼⣷⣶⣶⣾⠿⠿⠟⠛⡛⠛⠛⠛⠥⠀⠀⠀⠀⠀⠀⢀⣄⣀⣀⡀⠤⢠⣤⠤⠴⠒⠿⠿⠾⣿⣻⠿⠿⠿⠶⠀⢀⣀⣈⣁⣤⣬⣥⣴⢶⣶⣾⣿⡿⠿⣿⣿⣿⣿⣿⡿⣿⣿\n"
	"⠙⠋⠩⠍⠛⠁⢀⠀⠀⠀⠉⡁⣀⢀⣀⣀⣨⣤⣵⣲⡦⠶⠾⢿⣾⠯⠿⠿⠄⠀⠒⠀⠂⣈⣁⣀⣥⣤⠤⣦⣶⣶⣏⣚⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠟⠻⠿\n"
	"⣒⣬⣀⣤⣽⡿⣌⠓⣓⡛⠚⠛⠛⠛⠟⠉⢉⡁⡉⣉⣥⣈⣁⣉⠂⠒⡒⢦⣤⣌⣉⡿⣷⡭⣭⣭⣶⣯⣽⣿⣿⣿⣿⣿⣟⣙⣛⣛⣛⣓⣲⣴⣶⣦⣶⣶⡶⣾⣿⣓⠳⢶⣶⣶⣿\n"
	"⠉⠉⠉⢉⣉⢉⠉⠉⠉⠙⠋⠑⠒⠚⠛⠻⠿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⣯⣼⣿⣒⣻⣿⣿⣿⣿⣿⣭⣿⣿⣿⠿⣿⣛⣿⡯⠍⠋⢉⣐⡎⣵⣶⡶⣤\n"
	"⣤⣀⣠⣄⣀⣀⡀⠉⡛⠀⠒⠀⠙⠳⠐⠓⠀⠀⣀⠀⢀⠀⢀⡀⠀⠀⠄⠀⡀⠀⢀⠈⣉⢉⠉⠉⠙⠛⠛⠛⠛⠛⠛⠻⠿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
	"⢀⢀⠠⠭⠀⠀⣀⣀⠀⠀⢠⢝⠒⡒⠂⠲⠞⠙⠊⢄⣤⠡⡤⠤⠤⠀⠀⣀⡅⠍⡁⠀⠐⠤⠤⠀⠉⠁⠀⠄⠤⠄⠛⠀⢉⣥⡺⠖⠶⣶⣦⣤⡤⢤⡄⢀⠉⠉⠉⠛⠛⠛⠛⠛⠛\n";
	arvore.close();
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("Could not open and write the file!\n");
}
