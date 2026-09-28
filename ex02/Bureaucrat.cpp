/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:20:58 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const int	Bureaucrat::HIGHEST_GRADE = 1;
const int	Bureaucrat::LOWEST_GRADE = 150;

void	Bureaucrat::_checkGrade(int grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(void) :
	_name("Dupont"),
	_grade(Bureaucrat::LOWEST_GRADE)
{
	std::cout << "Bureaucrat: " << this->_name
		<< " : Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	Bureaucrat::_checkGrade(grade);
	std::cout << "Bureaucrat: " << this->_name
		<< " : Parameters constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat: " << this->_name
		<< " : Copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: " << this->_name
		<< " : Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat: " << this->_name
		<< " : Destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	Bureaucrat::_checkGrade(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	Bureaucrat::_checkGrade(this->_grade + 1);
	this->_grade++;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (out);
}
