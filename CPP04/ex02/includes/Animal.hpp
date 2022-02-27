/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 20:58:01 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Brain.hpp"

class AAnimal
{

	public:

		AAnimal(void);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);

		virtual AAnimal 				&operator=( AAnimal const & rhs );
		
		virtual std::string				getType(void) const;
		virtual void					makeSound(void) const;
		virtual Brain					*getBrain(void) const = 0;
		
	protected:
		std::string		type;

	private:
		

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */