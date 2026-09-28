/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:38:37 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define FORM_COUNT 3

AForm*	Intern::_makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void)
{
	std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern: Copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "Intern: Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern: Destructor called" << std::endl;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string	names[FORM_COUNT] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm*				(*builders[FORM_COUNT])(const std::string&) = {
		&Intern::_makeShrubbery,
		&Intern::_makeRobotomy,
		&Intern::_makePresidential
	};

	for (int idx = 0; idx < FORM_COUNT; idx++)
	{
		if (names[idx] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (builders[idx](target));
		}
	}
	std::cout << "Intern cannot create " << name
		<< ": this form does not exist" << std::endl;
	return (NULL);
}
