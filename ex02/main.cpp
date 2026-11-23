/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/21 14:58:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void	printArray(const Array<T>& array, const std::string& label)
{
	unsigned int	i;

	i = 0;
	std::cout << label;
	while (i < array.size())
	{
		std::cout << array[i];
		if (i + 1 < array.size())
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

int	main(void)
{
	Array<int>			empty;
	Array<int>			zeroes(4);
	Array<int>			numbers(5);
	Array<int>			copy;
	Array<int>			assigned;
	Array<std::string>	words(3);
	const Array<int>*	constView;
	unsigned int		i;

	std::cout << "--- default constructor ---" << std::endl;
	std::cout << "empty size: " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "empty access: " << e.what() << std::endl;
	}
	std::cout << "--- default initialization ---" << std::endl;
	printArray(zeroes, "zeroes: ");
	std::cout << "--- fill and read ---" << std::endl;
	i = 0;
	while (i < numbers.size())
	{
		numbers[i] = static_cast<int>(i * 10);
		i++;
	}
	printArray(numbers, "numbers: ");
	Array<int>	copyCtor(numbers);
	copy = numbers;
	assigned = numbers;
	std::cout << "--- deep copy check ---" << std::endl;
	numbers[0] = 999;
	copyCtor[4] = 666;
	copy[1] = 888;
	assigned[2] = 777;
	std::cout << "numbers size: " << numbers.size() << std::endl;
	std::cout << "copyCtor size: " << copyCtor.size() << std::endl;
	std::cout << "copy size: " << copy.size() << std::endl;
	std::cout << "assigned size: " << assigned.size() << std::endl;
	printArray(numbers, "numbers content: ");
	printArray(copyCtor, "copyCtor content: ");
	printArray(copy, "copy content: ");
	printArray(assigned, "assigned content: ");
	std::cout << "--- self assignment ---" << std::endl;
	Array<int>*	selfRef;

	selfRef = &assigned;
	assigned = *selfRef;
	printArray(assigned, "assigned after self-assignment: ");
	std::cout << "--- const access ---" << std::endl;
	constView = &copy;
	std::cout << "constView[1] = " << (*constView)[1] << std::endl;
	std::cout << "--- template with std::string ---" << std::endl;
	words[0] = "hello";
	words[1] = "from";
	words[2] = "array";
	printArray(words, "words: ");
	std::cout << "--- bounds exceptions ---" << std::endl;
	try
	{
		numbers[numbers.size()] = 42;
	}
	catch (std::exception& e)
	{
		std::cout << "index == size: " << e.what() << std::endl;
	}
	try
	{
		std::cout << numbers[1000] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "large index: " << e.what() << std::endl;
	}
	return (0);
}
