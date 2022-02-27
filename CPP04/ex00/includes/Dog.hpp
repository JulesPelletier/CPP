/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 16:25:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog(void);
		Dog( Dog const & src );
		virtual ~Dog(void);

		Dog &		operator=( Dog const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;

	private:

};

#endif /* ************************************************************* DOG_H */