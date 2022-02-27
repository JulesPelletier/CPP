/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 20:26:29 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class Animal
{

	public:

		Animal(void);
		Animal( Animal const & src );
		virtual ~Animal(void);

		Animal &				operator=( Animal const & rhs );
		std::string				getType(void) const;
		virtual void			makeSound(void) const;
		
	protected:
		std::string		_type;

	private:
		

};

#endif /* ********************************************************** ANIMAL_H */