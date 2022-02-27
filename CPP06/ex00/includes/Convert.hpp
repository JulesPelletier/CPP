/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:49 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/27 23:50:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <float.h>
# include <cmath>
# include <stdlib.h>
# include "Colors.hpp"

class Convert
{

	public:

		Convert(void);
		Convert(std::string arg);
		Convert( Convert const & src );
		~Convert(void);

	Convert &		operator=( Convert const & rhs );


		char			getType(void) const;
		char			getChar(void) const;
		int				getInt(void) const;
		float 			getFloat(void) const;
		double 			getDouble(void) const;
		std::string		getArg(void) const;
		int				Flag(int index) const;

		// Exceptions

		class Invalid : public std::exception
		{
			public:
				Invalid() throw();
				virtual ~Invalid() throw();
				virtual const char* what() const throw();
		};

		class MaxInt : public std::exception
		{
			public:
				MaxInt() throw();
				virtual ~MaxInt() throw();
				virtual const char* what() const throw();
		};
		
	private:
		void			init(const std::string &str);
		void			convert(void);
		char			CheckParam(const std::string &str) const;
		char			checkSign(const std::string& str) const;
		char			checkChar(const std::string& str) const;
		char			checkNumber(const std::string& param) const;

		//Conversions
		void			convert_c(void);
		void			convert_d(void);
		void			convert_i(void);
		void			convert_f(void);


		std::string		_arg;
		char			_type;
		char			_c;
		int				_int;
		double			_double;
		float			_float;
		int				_flags[3];

};

std::ostream &			operator<<( std::ostream & o, Convert const & i );

#endif /* ********************************************************* CONVERT_H */