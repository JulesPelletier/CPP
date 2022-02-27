/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 20:48:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

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

	return (0);
}