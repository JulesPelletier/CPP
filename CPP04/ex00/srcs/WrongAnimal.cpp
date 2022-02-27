/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:27 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 16:59:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(void)
{
	this->type = "Standard wrong animal";
	std::cout << " ==== WRONG Animal default constructor ==== " << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	*this = src;
	std::cout << " ==== WRONG Animal copy constructor ==== " << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << " ==== Animal destructor ==== " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void		WrongAnimal::makeSound(void) const
{
	if (this->type == "Cat")
		std::cout << "** Bark Bark Bark **" << std::endl;
	else if (this->type == "Dog")
		std::cout << "** Meowww Meowww Meowww **" << std::endl;
	else
		std::cout << "** can't define a sound for the standard animal **" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */