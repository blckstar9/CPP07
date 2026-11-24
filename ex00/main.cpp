/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/11/24 18:30:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

class Number
{
	private:
		int	_value;

	public:
		Number() : _value(0) {}
		Number(int value) : _value(value) {}
		Number(const Number& other) : _value(other._value) {}
		Number&	operator=(const Number& other)
		{
			if (this != &other)
				_value = other._value;
			return (*this);
		}
		~Number() {}

		bool	operator<(const Number& other) const
		{
			return (_value < other._value);
		}
		bool	operator>(const Number& other) const
		{
			return (_value > other._value);
		}
		int		getValue() const
		{
			return (_value);
		}

};

class NoDefault
{
	public:
		int	value;
		NoDefault(int v) : value(v) {}
};

std::ostream&	operator<<(std::ostream& os, const Number& number)
{
	os << number.getValue();
	return (os);
}

int	main(void)
{
	int					a;
	int					b;
	std::string			c;
	std::string			d;
	std::string			firstEqual;
	std::string			secondEqual;
	const std::string*	minEqual;
	const std::string*	maxEqual;
	Number				firstNumber;
	Number				secondNumber;

	std::cout << std::boolalpha;
	std::cout << "--- subject tests ---" << std::endl;
	a = 2;
	b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	c = "chaine1";
	d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << "--- equal values rule ---" << std::endl;
	firstEqual = "same";
	secondEqual = "same";
	minEqual = &::min(firstEqual, secondEqual);
	maxEqual = &::max(firstEqual, secondEqual);
	std::cout << "min equal returns second: " << (minEqual == &secondEqual) << std::endl;
	std::cout << "max equal returns second: " << (maxEqual == &secondEqual) << std::endl;
	std::cout << "--- custom comparable type ---" << std::endl;
	firstNumber = Number(42);
	secondNumber = Number(7);
	std::cout << "before swap -> first: " << firstNumber << ", second: " << secondNumber << std::endl;
	::swap(firstNumber, secondNumber);
	std::cout << "after swap -> first: " << firstNumber << ", second: " << secondNumber << std::endl;
	std::cout << "min(number) = " << ::min(firstNumber, secondNumber) << std::endl;
	std::cout << "max(number) = " << ::max(firstNumber, secondNumber) << std::endl;
	NoDefault	ndA(10);
	NoDefault	ndB(20);
	::swap(ndA, ndB);
	std::cout << "swap without default ctor -> ndA: " << ndA.value << ", ndB: " << ndB.value << std::endl;
	return (0);
}
