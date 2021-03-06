/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 15:18:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	try
	{
		Bureaucrat	me("Jules", 120);
		ShrubberyCreationForm f_me("tree");
		
		me.signForm(f_me);
		me.executeForm(f_me);
		std::cout << std::endl;
		std::cout << Reset " **** Shrubbery Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	me("Jules", 120);
		ShrubberyCreationForm f_me("leaf");
		
		me.signForm(f_me);
		me.executeForm(f_me);
		std::cout << std::endl;
		std::cout << Reset " **** Shrubbery Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat	me2("Theo", 78);
		PresidentialPardonForm f_me2("Flo");

		me2.signForm(f_me2);
		me2.executeForm(f_me2);
		std::cout << std::endl;
		std::cout << Reset " **** Presiendtial Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	me2("Theo", 43);
		PresidentialPardonForm f_me2("Flo");

		me2.signForm(f_me2);
		me2.executeForm(f_me2);
		std::cout << std::endl;
		std::cout << Reset " **** Presiendtial Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat	me3("Blabla", 26);
		RobotomyRequestForm f_me3("Steve");

		me3.signForm(f_me3);
		me3.executeForm(f_me3);
		std::cout << std::endl;
		std::cout << Reset " **** Robotomized Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	me3("Blabla", 1);
		RobotomyRequestForm f_me3("Steve");

		me3.signForm(f_me3);
		me3.executeForm(f_me3);
		std::cout << std::endl;
		std::cout << Reset " **** Robotomized Form done **** " << std::endl;
		std::cout << std::endl;
		std::cout << f_me3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Intern	intern;
		Form	*test;
	
		test = intern.makeForm("presidential", "Ma maman");
		std::cout << *test << std::endl;
		delete test;
	
		Form	*test2;
		test2 = intern.makeForm("robotomy", "Mon papa");
		std::cout << *test2 << std::endl;
		delete test2;
	
		Form	*test3;
		test3 = intern.makeForm("shrubbery", "arbre");
		std::cout << *test3 << std::endl;
		delete test3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

