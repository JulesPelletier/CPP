/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:45:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 15:09:48 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include "Colors.hpp"

class Replace
{
public:
	Replace(void);
	~Replace(void);

	int				createFile(std::string file);
	std::string		replaceStrings(std::string s1, std::string s2);
	

private:
	std::string		_original;
	std::string		_replace;
	std::string		_output_file;
	std::ifstream	_input_file;
};

int	display_error(int n);

#endif
