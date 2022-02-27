/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 16:24:55 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat(void);
		Cat( Cat const & src );
		virtual ~Cat(void);

		Cat &			operator=( Cat const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;

	private:

};

#endif /* ************************************************************* CAT_H */