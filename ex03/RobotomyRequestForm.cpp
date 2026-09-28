/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:27:43 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE),
	_target("someone")
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE),
	_target(target)
{
	std::cout << "RobotomyRequestForm: Parameters constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target)
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm: Copy assignment operator called"
		<< std::endl;
	if (this != &other)
		this->AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::_execute(void) const
{
	static bool	seeded = false;

	if (seeded == false)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	std::cout << "* BZZZZ... DRRRRR... the drilling noises are terrible *"
		<< std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully"
			<< std::endl;
	else
		std::cout << "the robotomy of " << this->_target << " failed"
			<< std::endl;
}
