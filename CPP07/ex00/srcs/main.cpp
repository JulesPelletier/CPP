/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:19:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 12:05:39 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.hpp"

int main( void ) 
{
	std::cout << " === Original Test === " << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << " === Other Test === " << std::endl;

	int t1 = 2;
	int t2 = 3;
	int t3 = 2;
	int t4 = -1;
	::swap(t1, t2);
	std::cout << "t1 = " << t1 << ", t2 = " << t2 << std::endl;
	std::cout << "min( t1, t2 ) = " << ::min( t1, t2 ) << std::endl;
	std::cout << "max( t1, t2 ) = " << ::max( t1, t2 ) << std::endl;
	::swap(t2, t3);
	std::cout << "t2 = " << t2 << ", t3 = " << t3 << std::endl;
	std::cout << "min( t2, d ) = " << ::min( t2, t3 ) << std::endl;
	std::cout << "max( t2, d ) = " << ::max( t2, t3 ) << std::endl;
	::swap(t2, t4);
	std::cout << "t2 = " << t2 << ", t4 = " << t4 << std::endl;
	std::cout << "min( t2, d ) = " << ::min( t2, t4 ) << std::endl;
	std::cout << "max( t2, d ) = " << ::max( t2, t4 ) << std::endl;

	
	return 0;
}