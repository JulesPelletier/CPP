/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:50:42 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 15:19:18 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(void)
{
	std::cout << Yellow "Default constructor called for Intern" Reset << std::endl;
}

Intern::Intern( const Intern & src )
{
	(void)src;
	std::cout << Purple "Copy constructor called for Intern" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(void)
{
	std::cout << Yellow "Default destructor called for Intern" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
		return (*this);
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Intern created the form" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form			*Intern::makeForm(std::string type, std::string target)
{
	std::string		Form_type[3] = {
		"shrubbery",
		"robotomy",
		"presidential"
	};

	int i;
	i = 0;
	while (i < 3)
	{
		if (Form_type[i] == type)
			break;
		i++;
	}
	if (i < 3)
		std::cout << Green "Intern created the form" Reset << std::endl;
	switch(i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
	}
	return (0);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */