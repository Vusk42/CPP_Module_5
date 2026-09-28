/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/22 18:35:42 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void	testValidBureaucrat(void)
{
	try
	{
		Bureaucrat	boss("Alice", 1);
		Bureaucrat	intern("Bob", 150);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

static void	testInvalidGrades(void)
{
	try
	{
		Bureaucrat	tooGood("Randria", 0);

		std::cout << tooGood << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Randria (Grade 0)	: "
			<< e.what() << "." << std::endl;
	}

	try
	{
		Bureaucrat	tooBad("Darius", 151);

		std::cout << tooBad << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Darius (Grade 151)	: "
			<< e.what() << "." << std::endl;
	}
}

static void	testIncrementDecrement(void)
{
	Bureaucrat	clerk("Charlie", 42);

	std::cout << clerk << std::endl;
	try
	{
		clerk.incrementGrade();
		std::cout << "after one promotion:	" << clerk << std::endl;
		clerk.decrementGrade();
		clerk.decrementGrade();
		std::cout << "after two demotions:	" << clerk << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

static void	testBounds(void)
{
	Bureaucrat	top("Zeus", 1);
	Bureaucrat	bottom("Hades", 150);

	try
	{
		std::cout << top << " Asking for a promotion:	" << std::endl;
		top.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "  refused because " << e.what() << "." << std::endl;
	}

	try
	{
		std::cout << bottom << " Asking for a demotion..." << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "  refused because " << e.what() << "." << std::endl;
	}
}

static void	testCanonicalForm(void)
{
	Bureaucrat	dupont;
	Bureaucrat	original("Dave", 10);
	Bureaucrat	copy(original);
	Bureaucrat	assigned;

	std::cout << std::endl << "default		: " << dupont << std::endl;
	std::cout << "original	: " << original << std::endl;
	std::cout << "copy		: " << copy << std::endl << std::endl;
	assigned = original;
	std::cout << std::endl << "assigned	: " << assigned << std::endl << std::endl;
}

int	main(void)
{
	std::cout << "=== Valid bureaucrats ===" << std::endl;
	testValidBureaucrat();

	std::cout << std::endl << "=== Invalid grades at construction ==="
		<< std::endl;
	testInvalidGrades();

	std::cout << std::endl << "=== Increment and decrement ===" << std::endl;
	testIncrementDecrement();

	std::cout << std::endl << "=== Out of bounds increment/decrement ==="
		<< std::endl;
	testBounds();

	std::cout << std::endl << "=== Orthodox canonical form ===" << std::endl;
	testCanonicalForm();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
