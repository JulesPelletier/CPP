/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:30:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 12:39:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <math.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int		tab1[4] = {0, 1, 2, 3};
	int		tab2[4] = {0, -1, -2, -3};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== Function1  ==== " Reset << std::endl;
	iter(tab1, 4, ::function1);
	std::cout << std::endl;
	iter(tab2, 4, ::function1);
	std::cout << std::endl;


	char	char1[4] = {'a', 'b', 'c', 'd'};
	char	char2[4] = {'a', 'c', 'b', 'd'};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== Function2  ==== " Reset << std::endl;
	iter(char1, 4, ::function2);
	std::cout << std::endl;

	iter(char2, 4, ::function2);
	std::cout << std::endl;

	char	char3[4] = {'1', '2', '3', '4'};
	char	char4[4] = {'1', '2', '3', '4'};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== Function2  ==== " Reset << std::endl;
	iter(char3, 4, ::function2);
	std::cout << std::endl;

	iter(char4, 4, ::function2);
	std::cout << std::endl;

	std::string	str1[4] = {"1", "10", "100", "1000"};
	std::string	str2[4] = {"2", "20", "200", "2000"};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== Function 3 ==== " Reset << std::endl;
	iter(str1, 4, ::function3);
	std::cout << std::endl;

	iter(str2, 4, ::function3);
	std::cout << std::endl;

}

/*

int main(void)
{
	int tab[4] = {1, 2, 3, 4};
	std::cout << "--- Testing tab ---" << std::endl;
	iter(tab, 4, function3);
	std::string ts[3] = {
	"Salut",
	"Ca",
	"Va ?"
	};
	std::cout << "--- Testing string ---" << std::endl;
	iter(ts, 3, function3);
}
*/