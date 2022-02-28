/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 14:17:38 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class WrongAnimal
{

	public:

		WrongAnimal(void);
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal(void);

		virtual WrongAnimal &		operator=( WrongAnimal const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;
		
	protected:
		std::string		_type;

	private:
		

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */