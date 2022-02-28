/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 14:21:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Showing Types xxxxxx " Reset << std::endl;
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Showing Sounds xxxxxx " Reset << std::endl;
	std::cout << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Other Test xxxxxx " Reset << std::endl;
	std::cout << std::endl;


	Cat	a;
	Dog	b;
	
	std::cout << a.getType() << " " << std::endl;
	std::cout << b.getType() << " " << std::endl;
	a.makeSound(); 
	b.makeSound(); 

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Other Test ++ xxxxxx " Reset << std::endl;
	std::cout << std::endl;

	WrongAnimal *wronganimal = new WrongAnimal();
	WrongAnimal *wrongcat= new WrongCat();

	std::cout << wrongcat->getType() << " " << std::endl;
	std::cout << wronganimal->getType() << " " << std::endl;


	wrongcat->makeSound(); 
	wronganimal->makeSound(); 
	std::cout << std::endl;
	std::cout << std::endl;

	delete wrongcat;
	delete wronganimal;
	
	return 0;
}


/*

// Other main 

int	main(void)
{
	//Animal part ------------------------------------------------------------------------------
	std::cout << Green << "Creating and testing an Animal: " << Reset << std::endl << std::endl;
	
	Animal			*meta = new Animal();
	
	std::cout << "basic noise of an Animal: ";
	meta->makeSound();
	std::cout << std::endl;
	
	std::cout << std::endl << Red << "Destroying my Animal" << Reset << std::endl;
	delete meta;
	

	//Dog part ---------------------------------------------------------------------------------
	std::cout << std::endl << Green << "Creating and testing a Dog: " << Reset
		<< std::endl << std::endl;
	
	const Animal		*j = new Dog();
	
	std::cout << j->getType() << " make the sound: ";
	j->makeSound();
	
	std::cout << std::endl << Red << "Destroying my Dog" << Reset << std::endl;
	delete j;
	
	
	//Cat part ----------------------------------------------------------------------------------
	std::cout << std::endl << Green << "Creating and testing a Cat: " << Reset
		<< std::endl << std::endl;
	
	const Animal		*i = new Cat();
	
	std::cout << i->getType() << " make the sound: ";
	i->makeSound();
	
	std::cout << std::endl << Red << "Destroying my Cat" << Reset << std::endl;
	delete i;
	
	
	//WrongCat part -----------------------------------------------------------------------------
	std::cout << std::endl << Green << "Creating and testing a WrongCat: " << Reset
		<< std::endl << std::endl;
	
	const WrongAnimal	*k = new WrongCat();
	
	std::cout << k->getType() << " make the sound: ";
	k->makeSound();
	std::cout << std::endl;
	
	std::cout << std::endl << Red << "Destroying my WrongCat" << Reset << std::endl;
	delete k;

	return (0);
}
*/