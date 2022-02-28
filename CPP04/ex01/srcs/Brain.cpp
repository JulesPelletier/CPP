/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:55 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 14:30:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(void)
{
	if (sizeof(this->ideas) == 0)
		return ;
	for (size_t i = 0; i < sizeof(this->ideas) / sizeof(this->ideas[0]); i++)
		this->ideas[i] = "Idea init";
	std::cout << " === Default constrcutor for Brain Class === " << std::endl;
}

Brain::Brain( const Brain & src )
{
	if (sizeof(this->ideas) == 0)
		return ;
	for (size_t i = 0; i < sizeof(src.ideas) / sizeof(src.ideas[0]); i++)
		this->ideas[i] = src.ideas[i];
	*this = src;
	std::cout << " === Copy constrcutor for Brain Class === " << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain(void)
{
	std::cout << " === Default destructor for Brain Class === " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if (this == &rhs)
		return (*this);

	if (sizeof(rhs.ideas) == 0)
		return (*this);
	
	if (sizeof(rhs.ideas) != sizeof(this->ideas))
		return (*this);
	
	for (size_t i = 0; i < sizeof(rhs.ideas) / sizeof(rhs.ideas[0]); i++)
		this->ideas[i] = rhs.ideas[i];
		
	return (*this);
}

std::string	Brain::getIdeas(int i) const
{
	return (this->ideas[i]);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */