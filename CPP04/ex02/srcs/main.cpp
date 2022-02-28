/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 14:43:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

/*
int main(void)
{
		
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;

	AAnimal	*zoo[6];
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		zoo[i] = new Dog();
	for (int i = 3; i < 6; i++)
		zoo[i] = new Cat();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing sounds " << std::endl;
	std::cout << zoo[0]->getType() << std::endl;
	zoo[0]->makeSound();
	std::cout << zoo[1]->getType() << std::endl;
	zoo[1]->makeSound();
	std::cout << zoo[2]->getType() << std::endl;
	zoo[2]->makeSound();
	std::cout << zoo[3]->getType() << std::endl;
	zoo[3]->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete zoo[i];
	std::cout << std::endl;
	
	return 0;
}
*/

int main(void)
{

	// Animal	randomAnimal;
	// Animal	petitOrni("Ornithorynque");
	std::cout << std::endl;

	// const Animal* meta = new Animal();
	// delete	meta;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	delete	i;
	delete	j;
	std::cout << std::endl;

	return (0);
}