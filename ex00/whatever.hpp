/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/21 14:58:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& first, T& second)
{
	T	tmp;

	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
const T&	min(const T& first, const T& second)
{
	if (first < second)
		return (first);
	return (second);
}

template <typename T>
const T&	max(const T& first, const T& second)
{
	if (first > second)
		return (first);
	return (second);
}

#endif
