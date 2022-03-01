/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:26:58 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 21:30:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

template<typename T>
void	function1(T const &src)
{
	std::cout << Blue << src << "f1" << Reset << "\t|\t";
}

template<typename T>
void	function2(T const &src)
{
	std::cout << Blue << src <<  "f2" << Reset << "\t|\t";
}

template <typename T>
void	function3(T const& t)
{
	std::cout << Blue << t << Reset << 0 << std::endl;
}

template<typename T>
void	iter(T *array, int len, void (*f)(T const &))
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*f)(array[i]);
		i++;
	}
}

#endif /* ************************************************************ ITER_H */