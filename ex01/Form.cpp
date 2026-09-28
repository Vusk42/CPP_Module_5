/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/22 19:20:38 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

void	Form::_checkGrade(int grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(void) :
	_name("The Norm v4"),
	_signed(false),
	_signGrade(Bureaucrat::LOWEST_GRADE),
	_execGrade(Bureaucrat::LOWEST_GRADE)
{
	std::cout << "Form: " << this->_name
		<< " : Default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	Form::_checkGrade(signGrade);
	Form::_checkGrade(execGrade);
	std::cout << "Form: " << this->_name
		<< " : Parameters constructor called" << std::endl;
}

Form::Form(const Form& other) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	std::cout << "Form: " << this->_name
		<< " : Copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form: " << this->_name
		<< " : Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form: " << this->_name
		<< " : Destructor called" << std::endl;
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low");
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "Form " << form.getName() << ", "
		<< (form.getSigned() ? "signed" : "unsigned")
		<< ", grade " << form.getSignGrade() << " required to sign, grade "
		<< form.getExecGrade() << " required to execute.";
	return (out);
}
