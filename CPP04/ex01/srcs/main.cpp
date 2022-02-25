/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:26:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Brain.hpp"

int main(void)
{
	int		number = 10;
	int		i = 0;
	Animal	*animals[number];
	Animal	*test;
	Brain	*brain;

	while (i < number)
	{
		std::cout << std::endl;
		if (i % 4 == 0)
			animals[i] = new Dog();
		if (i % 4 == 1)
			animals[i] = new Cat();
		if (i % 4 == 2)
			animals[i] = new Cat();
		if (i % 4 == 3)
			animals[i] = new Dog();
		i++;
	}
		
	std::cout << std::endl;
	brain = animals[6]->getBrain();
	brain->ideas[0] = Red "Idea number 0" Reset;
	brain->ideas[1] = Yellow "Idea number 1" Reset;
	brain->ideas[2] = Blue "Idea number 2" Reset;
	brain->ideas[3] = Green "Idea number 3" Reset;
	brain->ideas[4] = Purple "Idea number 4" Reset;
	brain->ideas[5] = Cyan "Idea number 5" Reset;

	std::cout << "Printing ideas" << std::endl;
	std::cout << animals[6]->getBrain()->ideas[0] << std::endl;;
	std::cout << animals[6]->getBrain()->ideas[2] << std::endl;;
	std::cout << animals[6]->getBrain()->ideas[4] << std::endl;;


	test = animals[6];
	std::cout << std::endl;
	std::cout << "Printing DUP ideas" << std::endl;
	std::cout << test->getBrain()->ideas[1] << std::endl;;
	std::cout << test->getBrain()->ideas[3] << std::endl;;
	std::cout << test->getBrain()->ideas[5] << std::endl;;
	std::cout << std::endl;
	std::cout << std::endl;

	
	i = 0;
	while (i < number)
	{
		delete animals[i];
		i++;
	}

	
	return 0;
}