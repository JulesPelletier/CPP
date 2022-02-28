/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 15:39:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Convert.hpp"

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1)
		std::cout << "Error : you need to input arguments to convert " << std::endl;
	else
	{
		std::cout << " --- Printing original test --- " << std::endl;
		Convert conv1("0");
		Convert conv2("42.0f");
		Convert conv3("nan");
		while (av[i])
		{
			Convert	conv(av[i]);
			i++;
		}
	}
}
