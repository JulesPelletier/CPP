/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:37:41 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 11:57:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
	long	i;

	i = random();
	if (i % 3 == 0)
		return (new A());
	if (i % 3 == 1)
		return (new B());
	if (i % 3 == 2)
		return (new C());
	return (0);
}

void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "Type A" << std::endl;
	if (b)
		std::cout << "Type B" << std::endl;
	if (c)
		std::cout << "Type C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Type B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Type C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
	
}

int main(void)
{
	int	i;
	int	num;

	num = 10;
	i = 0;
	while (i < num)
	{
		Base	*base;

		base = generate();
		std::cout << "Index : " << i << Blue " : \n";
		identify(base);
		identify(*base);
		if (base)
			delete base;
		std::cout << Reset "Moving on to next type" << std::endl << std::endl;
		i++;
	}
	return (0);
}

/* 

int main(void)
{
	Base	*testing;

	for (int i = 0; i < 15; i++) {
		testing = generate();
		identify(testing);
		identify(*testing);
		if (testing)
			delete testing;
		std::cout << std::endl;
	}
	return (0);
}

*/