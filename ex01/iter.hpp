/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/21 14:58:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T* array, const std::size_t length, void (*function)(T&))
{
	std::size_t	i;

	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

template <typename T>
void	iter(const T* array, const std::size_t length, void (*function)(const T&))
{
	std::size_t	i;

	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

#endif
