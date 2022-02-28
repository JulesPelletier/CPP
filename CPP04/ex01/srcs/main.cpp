/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 14:41:31 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

/*

int main(void)
{
	
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;

	Animal	*zoo[6];
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		zoo[i] = new Dog();
	for (int i = 3; i < 6; i++)
		zoo[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		zoo[i]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete zoo[i];
	std::cout << std::endl;


	Animal *ori = new Cat();
	Animal *cpy(ori);

	ori->makeSound();
	cpy->makeSound();
	std::cout << ori->getBrain()->ideas[0] << std::endl;
	std::cout << cpy->getBrain()->ideas[0] << std::endl;
	std::cout << ori->getBrain()->ideas[1] << std::endl;
	std::cout << cpy->getBrain()->ideas[1] << std::endl;

	cpy->getBrain()->ideas[2] = "New idea";
	std::cout << ori->getBrain()->ideas[2] << std::endl;
	std::cout << cpy->getBrain()->ideas[2] << std::endl;


	return (0);
}

*/

int main(void)
{
	
	// Animal	test_vs_ex02;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;

	Animal	*zoo[6];
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		zoo[i] = new Dog();
	for (int i = 3; i < 6; i++)
		zoo[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		zoo[i]->makeSound();
	std::cout << std::endl;

	Dog		new_dog;
	std::cout << std::endl;
	std::cout << new_dog.getBrain()->ideas[0] << " vs. " << zoo[0]->getBrain()->ideas[0] << std::endl;
	new_dog.getBrain()->ideas[0] = "I love you!";
	std::cout << new_dog.getBrain()->ideas[0] << " vs. " << zoo[0]->getBrain()->ideas[0] << std::endl;
	zoo[0]->getBrain()->ideas[0] = "So happy to see youuuu!";
	std::cout << new_dog.getBrain()->ideas[0] << " vs. " << zoo[0]->getBrain()->ideas[0] << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete zoo[i];
	std::cout << std::endl;

	std::cout << " --- Other Tests --- " << std::endl;
	Dog	basic;
	Dog tmp = basic;
	std::cout << "Ori : " << basic.getBrain()->ideas[0] << std::endl;
	std::cout << "Copy : " << tmp.getBrain()->ideas[0] << std::endl;


	return (0);
}