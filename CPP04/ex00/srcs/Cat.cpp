/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:33 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 20:29:10 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << Red " -- Default constructor for cat -- " Reset << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	*this = src;
	std::cout << Red "Copy constructor for cat" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(void)
{
	std::cout << Red " -- Default destructor for cat -- " Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Cat::getType(void) const
{
	return (this->_type);
}

void		Cat::makeSound(void) const
{
	std::cout << "** Meowww Meowww Meowww **" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */