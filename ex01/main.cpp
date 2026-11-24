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
#include <cctype>
#include "iter.hpp"

static int	g_callCount = 0;

template <typename T>
void	printElement(const T& value)
{
	std::cout << value << " ";
}

void	increment(int& value)
{
	value++;
}

int	doubleValue(int& value)
{
	value *= 2;
	return (value);
}

void	makeUpper(char& c)
{
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void	appendExclamation(std::string& text)
{
	text += "!";
}

void	countCall(int&)
{
	g_callCount++;
}

int	main(void)
{
	int					numbers[] = {1, 2, 3, 4, 5};
	const std::size_t	numbersLen = sizeof(numbers) / sizeof(numbers[0]);
	char				word[] = "template";
	const std::size_t	wordLen = (sizeof(word) / sizeof(word[0])) - 1;
	const std::string	texts[] = {"hello", "from", "iter"};
	const std::size_t	textsLen = sizeof(texts) / sizeof(texts[0]);
	std::string			mutableTexts[] = {"one", "two", "three"};
	const std::size_t	mutableTextsLen = sizeof(mutableTexts) / sizeof(mutableTexts[0]);
	int					sentinel[] = {123};

	std::cout << "--- non-const arrays ---" << std::endl;
	iter(numbers, numbersLen, increment);
	std::cout << "incremented ints: ";
	iter(numbers, numbersLen, printElement<int>);
	std::cout << std::endl;
	iter(word, wordLen, makeUpper);
	std::cout << "upper chars: ";
	iter(word, wordLen, printElement<char>);
	std::cout << std::endl;
	iter(mutableTexts, mutableTextsLen, appendExclamation);
	std::cout << "mutated strings: ";
	iter(mutableTexts, mutableTextsLen, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "--- const arrays ---" << std::endl;
	std::cout << "const strings: ";
	iter(texts, textsLen, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "--- non-void function ---" << std::endl;
	iter(numbers, numbersLen, doubleValue);
	std::cout << "doubled ints: ";
	iter(numbers, numbersLen, printElement<int>);
	std::cout << std::endl;
	std::cout << "--- zero-length safety ---" << std::endl;
	g_callCount = 0;
	iter(sentinel, 0, countCall);
	std::cout << "call count for length 0: " << g_callCount << std::endl;
	std::cout << "sentinel value unchanged: " << sentinel[0] << std::endl;
	return (0);
}
