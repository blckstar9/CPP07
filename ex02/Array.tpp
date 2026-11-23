/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/21 14:58:00 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(0), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n)
{
	if (_size > 0)
		_data = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array& other) : _data(0), _size(other._size)
{
	unsigned int	i;

	if (_size > 0)
	{
		_data = new T[_size];
		i = 0;
		while (i < _size)
		{
			_data[i] = other._data[i];
			i++;
		}
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	unsigned int	i;

	if (this != &other)
	{
		delete [] _data;
		_data = 0;
		_size = other._size;
		if (_size > 0)
		{
			_data = new T[_size];
			i = 0;
			while (i < _size)
			{
				_data[i] = other._data[i];
				i++;
			}
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Array index is out of bounds.");
}
