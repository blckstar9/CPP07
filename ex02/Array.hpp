/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/11/24 18:30:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>
#include <exception>

template <typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;
		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#include "Array.tpp"

#endif
