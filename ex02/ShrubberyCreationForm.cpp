/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:29:37 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

#define SHRUBBERY_SIGN_GRADE 145
#define SHRUBBERY_EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE),
	_target("home")
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE),
	_target(target)
{
	std::cout << "ShrubberyCreationForm: Parameters constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm: Copy assignment operator called"
		<< std::endl;
	if (this != &other)
		this->AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::_execute(void) const
{
	std::ofstream	file((this->_target + "_shrubbery").c_str());

	if (file.is_open() == false)
	{
		std::cout << "ShrubberyCreationForm: cannot open "
			<< this->_target << "_shrubbery" << std::endl;
		return ;
	}
	for (int tree = 0; tree < 2; tree++)
	{
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
		file << std::endl;
	}
	file.close();
	std::cout << "ShrubberyCreationForm: " << this->_target
		<< "_shrubbery has been planted" << std::endl;
}
