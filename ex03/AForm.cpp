/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/28 18:26:31 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void	AForm::_checkGrade(int grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(void)
	: _name("The Norm v4"),
	_signed(false),
	_signGrade(Bureaucrat::LOWEST_GRADE),
	_execGrade(Bureaucrat::LOWEST_GRADE)
{
	std::cout << "AForm: " << this->_name
		<< " : Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	AForm::_checkGrade(signGrade);
	AForm::_checkGrade(execGrade);
	std::cout << "AForm: " << this->_name
		<< " : Parameters constructor called" << std::endl;
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	std::cout << "AForm: " << this->_name
		<< " : Copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "AForm: " << this->_name
		<< " : Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm: " << this->_name
		<< " : Destructor called" << std::endl;
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	this->_execute();
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low");
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return ("the form is not signed");
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << "Form " << form.getName() << ", "
		<< (form.getSigned() ? "signed" : "unsigned")
		<< ", grade " << form.getSignGrade() << " required to sign, grade "
		<< form.getExecGrade() << " required to execute.";
	return (out);
}
