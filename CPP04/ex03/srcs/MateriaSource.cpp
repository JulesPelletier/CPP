/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:52:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 21:42:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(void) : _size(0)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->source[i] = NULL;
		i++;
	}
	std::cout << "Default constructor for MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) {

	for (int i = 0; i < 4; i++) {
		
		if (src.source[i] != NULL)
			this->source[i] = src.source[i]->clone();
		else
			this->source[i] = NULL;
	}
	this->_size = src._size;
	std::cout << "A new Materia Source has been copied." << std::endl;
	return;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->source[i] != NULL)
			delete this->source[i];
		i++;
	}
	std::cout << "Default destructor for MateriaSource" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < this->_size; i++)
		delete this->source[i];
		
	this->_size = rhs._size;
	for (int i = 0; i < 4; i++) {
		
		if (rhs.source[i] != NULL)
			this->source[i] = rhs.source[i]->clone();
		else
			this->source[i] = NULL;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	if (this->_size >= 4)
		std::cout << "Full " << std::endl;
	this->source[this->_size] = m;
	this->_size = this->_size + 1;
	std::cout << Blue "Added  " Reset << this->source[i]->getType() << Blue " materia " Reset << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{

	for (int i = 0; i < 4; i++) {
	
		if (this->source[i] && (this->source[i]->getType() == type))
		{
			std::cout << Blue "Created " Reset << this->source[i]->getType() << Blue " materia" Reset << std::endl;
			return (this->source[i]->clone());
		}
	}
	std::cout << "Type not found in Materia Source (NULL returned)." << std::endl;
	return (NULL);
	int			i;

	i = 0;
	while (i < 4)
	{
		if (this->source[i] && this->source[i]->getType() == type)
			return (this->source[i]->clone());
		i++;
	}
	return (0);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */