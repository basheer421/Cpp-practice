/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:43:07 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 04:10:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <climits>
#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

class Span
{
	private:
		std::vector<int> vec;
		std::size_t max_size;
		class NoCapacityException : public std::exception {};

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& src);
		Span& operator = (const Span& src);
		
		void addNumber(int num);
		
		
		
		int shortestSpan();
		int longestSpan();

		template <typename iterator>
		void addRange(iterator first, iterator last)
		{
			if (std::distance(first, last) + vec.size() > max_size)
				throw NoCapacityException();
			while (first != last)
			{
				vec.push_back(*first);
				first++;
			}
		}
};
