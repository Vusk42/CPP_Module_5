/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:29:57 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static void	testAbstract(void)
{
	std::cout << "AForm is abstract: the two lines below do not compile."
		<< std::endl;
	std::cout << "  AForm  form;" << std::endl;
	std::cout << "  AForm* form = new AForm(\"form\", 1, 1);" << std::endl;

	// AForm	form;
	// AForm*	form = new AForm("form", 1, 1);
}

static void	testShrubbery(void)
{
	Bureaucrat				gardener("Alice", 130);
	ShrubberyCreationForm	shrubbery("garden");

	std::cout << shrubbery << std::endl;
	gardener.signForm(shrubbery);
	gardener.executeForm(shrubbery);
}

static void	testRobotomy(void)
{
	Bureaucrat			doctor("Bob", 40);
	RobotomyRequestForm	robotomy("Marvin");

	doctor.signForm(robotomy);
	for (int attempt = 0; attempt < 4; attempt++)
		doctor.executeForm(robotomy);
}

static void	testPardon(void)
{
	Bureaucrat				president("Zaphod", 1);
	PresidentialPardonForm	pardon("Arthur Dent");

	president.signForm(pardon);
	president.executeForm(pardon);
}

static void	testNotSigned(void)
{
	Bureaucrat				president("Zaphod", 1);
	PresidentialPardonForm	pardon("Ford Prefect");

	std::cout << "executing a form nobody signed:" << std::endl;
	president.executeForm(pardon);
}

static void	testGradeTooLowToExecute(void)
{
	Bureaucrat				boss("Alice", 20);
	Bureaucrat				clerk("Bob", 24);
	PresidentialPardonForm	pardon("Trillian");

	boss.signForm(pardon);
	std::cout << "a grade 24 bureaucrat cannot execute a grade 5 form:"
		<< std::endl;
	clerk.executeForm(pardon);
}

static void	testPolymorphism(void)
{
	Bureaucrat	boss("Eve", 1);
	AForm*		forms[3];

	forms[0] = new ShrubberyCreationForm("office");
	forms[1] = new RobotomyRequestForm("Bender");
	forms[2] = new PresidentialPardonForm("Slartibartfast");

	std::cout << std::endl;
	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << *forms[idx] << std::endl;
		boss.signForm(*forms[idx]);
		boss.executeForm(*forms[idx]);
		std::cout << std::endl;
	}

	std::cout << "--- deleting every form through an AForm* ---" << std::endl;
	for (int idx = 0; idx < 3; idx++)
		delete forms[idx];
}

int	main(void)
{
	std::cout << "=== An abstract base form ===" << std::endl;
	testAbstract();

	std::cout << std::endl << "=== ShrubberyCreationForm ===" << std::endl;
	testShrubbery();

	std::cout << std::endl << "=== RobotomyRequestForm ===" << std::endl;
	testRobotomy();

	std::cout << std::endl << "=== PresidentialPardonForm ===" << std::endl;
	testPardon();

	std::cout << std::endl << "=== Executing an unsigned form ===" << std::endl;
	testNotSigned();

	std::cout << std::endl << "=== Executing without the required grade ==="
		<< std::endl;
	testGradeTooLowToExecute();

	std::cout << std::endl << "=== Polymorphism through AForm* ===" << std::endl;
	testPolymorphism();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
