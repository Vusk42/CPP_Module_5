/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/09 15:20:00 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void	testInvalidForms(void)
{
	try
	{
		Form	impossible("form 28A", 0, 42);

		std::cout << impossible << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "form 28A cannot exist because "
			<< e.what() << "." << std::endl;
	}

	try
	{
		Form	impossible("form 28B", 42, 151);

		std::cout << impossible << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "form 28B cannot exist because "
			<< e.what() << "." << std::endl;
	}
}

static void	testSigningSucceeds(void)
{
	Bureaucrat	boss("Alice", 20);
	Form		taxes("tax return", 42, 10);

	std::cout << taxes << std::endl;
	boss.signForm(taxes);
	std::cout << taxes << std::endl;
}

static void	testSigningFails(void)
{
	Bureaucrat	clerk("Bob", 100);
	Form		secret("nuclear launch", 3, 1);

	std::cout << secret << std::endl;
	clerk.signForm(secret);
	std::cout << secret << std::endl;
}

static void	testSigningExactGrade(void)
{
	Bureaucrat	clerk("Charlie", 50);
	Form		holidays("holiday request", 50, 50);

	std::cout << "the grade is exactly the required one:" << std::endl;
	clerk.signForm(holidays);
	std::cout << holidays << std::endl;
}

static void	testBeSignedDirectly(void)
{
	Bureaucrat	clerk("Dave", 120);
	Form		form("form 28C", 100, 90);

	try
	{
		form.beSigned(clerk);
		std::cout << "form signed without going through the bureaucrat"
			<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "beSigned() threw: " << e.what() << std::endl;
	}
}

static void	testCanonicalForm(void)
{
	Bureaucrat	boss("Eve", 1);
	Form		original("form 42", 42, 42);
	Form		copy(original);
	Form		assigned;

	boss.signForm(original);
	assigned = original;

	std::cout << "original: " << original << std::endl;
	std::cout << "copy    : " << copy << std::endl;
	std::cout << "assigned: " << assigned << std::endl;
	std::cout << "(name and grades are const, only the signature is assigned)"
		<< std::endl;
}

int	main(void)
{
	std::cout << "=== Forms with invalid grades ===" << std::endl;
	testInvalidForms();

	std::cout << std::endl << "=== A bureaucrat signing a form ===" << std::endl;
	testSigningSucceeds();

	std::cout << std::endl << "=== A bureaucrat whose grade is too low ==="
		<< std::endl;
	testSigningFails();

	std::cout << std::endl << "=== Signing with the exact required grade ==="
		<< std::endl;
	testSigningExactGrade();

	std::cout << std::endl << "=== Calling beSigned() directly ===" << std::endl;
	testBeSignedDirectly();

	std::cout << std::endl << "=== Orthodox canonical form ===" << std::endl;
	testCanonicalForm();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
