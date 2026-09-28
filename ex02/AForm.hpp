/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:20:00 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/09 15:20:00 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		static void	_checkGrade(int grade);

	protected:
		AForm(void);
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);

		virtual void	_execute(void) const = 0;

	public:
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);
		void	execute(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif
