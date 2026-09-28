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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

static void	testKnownForm(void)
{
	Intern		someRandomIntern;
	Bureaucrat	boss("Alice", 1);
	AForm*		form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form == NULL)
		return ;
	std::cout << *form << std::endl;
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
}

static void	testEveryForm(void)
{
	Intern		someRandomIntern;
	Bureaucrat	boss("Eve", 1);
	const char*	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int idx = 0; idx < 3; idx++)
	{
		AForm*	form = someRandomIntern.makeForm(names[idx], "office");

		if (form == NULL)
			continue ;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
		std::cout << std::endl;
	}
}

static void	testUnknownForm(void)
{
	Intern	someRandomIntern;
	AForm*	form;

	form = someRandomIntern.makeForm("coffee making", "the boss");
	if (form == NULL)
		std::cout << "makeForm() returned NULL, nothing to delete" << std::endl;
	else
		delete form;
}

static void	testCanonicalForm(void)
{
	Intern	first;
	Intern	copy(first);
	Intern	assigned;

	assigned = first;
	std::cout << "every intern is interchangeable" << std::endl;
}

int	main(void)
{
	std::cout << "=== An intern makes a known form ===" << std::endl;
	testKnownForm();

	std::cout << std::endl << "=== An intern makes every existing form ==="
		<< std::endl;
	testEveryForm();

	std::cout << std::endl << "=== An intern makes an unknown form ==="
		<< std::endl;
	testUnknownForm();

	std::cout << std::endl << "=== Orthodox canonical form ===" << std::endl;
	testCanonicalForm();

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
