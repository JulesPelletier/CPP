/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 16:25:44 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat(void);
		WrongCat( WrongCat const & src );
		virtual ~WrongCat(void);

		WrongCat &		operator=( WrongCat const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif /* ************************************************************* CAT_H */