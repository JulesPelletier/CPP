/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:31:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 21:32:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(void) : _size(0)
{
	this->_name = "Default";
	for (int i = 0; i < 4 ; i++)
		this->inventory[i] = 0;
	std::cout << "Default constructor for Character" << std::endl;
}

Character::Character(std::string name) : _name(name), _size(0)
{
	for (int i = 0; i < 4 ; i++)
		this->inventory[i] = 0;
	this->_name = name;
	std::cout << "Default constructor for Character" << std::endl;
}


Character::Character( const Character & src )
{
	this->_name = src.getName();
	this->_size = src._size;
	
	for (int i = 0 ; i < this->_size; i++)
	{
		this->inventory[i] = src.inventory[i]->clone();
	}
	for (int i = this->_size + 1; i < 4 ; i++)
		this->inventory[i] = 0;

	std::cout << "Copy constructor for Character" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character(void) {

	for (int i = 0; i < this->_size; i++) {
		delete this->inventory[i];
	}
	
	std::cout << "The Character " << this->getName() << " has been destroyed." << std::endl;
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		return (*this);
	}
	
	for (int i = 0 ; i < this->_size; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = 0;
	}
	this->_size = rhs._size;
	
	for (int i = 0; i < this->_size; i++)
		this->inventory[i] = rhs.inventory[i]->clone();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Name = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const 			&Character::getName(void) const
{
	return (this->_name);
}

void						Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	std::cout << Blue "About to equip an item" Reset << std::endl;
	if (this->_size >= 4)
		std::cout << Red "Inventory already full" Reset << std::endl;
	else
	{
		this->inventory[i] = m;
		this->_size = this->_size + 1;
		std::cout << Blue "Item euiqed : " Reset << this->inventory[i]->getType() << std::endl;
	}
}

void				Character::unequip(int idx)
{
	int	i;

	i = 0;
	std::cout << Blue "About to unequip an item" Reset << std::endl;
	if (!this->inventory[0])
		std::cout << Red "Inventory is empty ! " Reset << std::endl;
	if (idx <= 0 || idx > 4)
		std::cout << Red "Incorrect index ! " Reset << std::endl;
	std::cout << Blue "Item unequiped : " Reset << this->inventory[i]->getType() << std::endl;
	for (i = idx; i < this->_size - 1; i++)
		this->inventory[i] = this->inventory[i + 1];
	this->inventory[i] = NULL;
	this->_size -= 1;
	return;
}

void				Character::use(int idx, ICharacter &target)
{
	std::cout << Blue "About to use an item" Reset << std::endl;
	if (idx <= 0 || idx > 4)
		std::cout << Red "Impossible index (between 1 and 4)" Reset << std::endl;
	else
	{
		if (this->inventory[idx - 1] != 0)
		{
			std::cout << "Type : " << this->inventory[idx - 1]->getType() << std::endl;
			this->inventory[idx - 1]->use(target);
		}
		else
			std::cout << Red "Slot is empty" Reset << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */