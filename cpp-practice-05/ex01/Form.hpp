/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:10:51 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 15:39:34 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool _isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;

	protected:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

	public:
		Form();
		Form(const std::string name, const int gradeRequiredToSign,
			const int gradeRequiredToExecute);
		Form(const Form& src);
		Form & operator = (const Form& src);
		~Form();

		const std::string getName() const;
		bool isSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(Bureaucrat& b);


		
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
