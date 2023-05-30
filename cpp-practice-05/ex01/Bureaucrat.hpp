/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:34 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 14:34:13 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>

class Form;

class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat & operator = (const Bureaucrat& src);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#include "Form.hpp"

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);