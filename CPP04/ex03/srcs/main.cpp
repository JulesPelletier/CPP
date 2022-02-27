/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:41:01 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 21:29:51 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void) {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;
	AMateria* tmp2;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	tmp2 = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(1);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	bob->equip(tmp2);
	bob->unequip(3);
	bob->unequip(0);
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	Character	bob_bis("bob_bis");
	Character	me_bis(bob_bis);
	std::cout << std::endl;
	
	tmp = src->createMateria("ice");
	me_bis.equip(tmp);
	me_bis.equip(src->createMateria("ice"));
	me_bis.equip(src->createMateria("ice"));
	me_bis.equip(src->createMateria("ice"));
	tmp = src->createMateria("cure");
	me_bis.equip(tmp);
	std::cout << std::endl;
	bob_bis.equip(tmp);
	bob_bis = me_bis;
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	delete tmp2; // delete the item that is still in the wild.
	std::cout << std::endl;
	
	return (0);
}