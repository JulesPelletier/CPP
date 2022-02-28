/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/28 21:22:30 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert(void) : _arg(0)
{
	std::cout << Yellow "Default constructor called for Convert" Reset << std::endl;
}

Convert::Convert(std::string arg) : _arg(arg)
{
	try
	{
		this->_type = CheckParam(arg);
		this->init(arg);
		this->convert();
		std::cout << *this << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Yellow "String constructor called for Convert" Reset << std::endl;
}

Convert::Convert( const Convert & src )
{
	this->_type = src.getType();
	this->_c = src.getChar();
	this->_int = src.getInt();
	this->_double = src.getDouble();
	this->_float = src.getFloat();

	this->_flags[0] = src._flags[0];
	this->_flags[1] = src._flags[1];
	this->_flags[2] = src._flags[2];
	std::cout << Yellow "Copy constructor called for Convert" Reset << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert(void)
{
	std::cout << Yellow "Default destructor called for Convert" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &				Convert::operator=( Convert const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_c = rhs.getChar();
		this->_int = rhs.getInt();
		this->_double = rhs.getDouble();
		this->_float = rhs.getFloat();
		this->_flags[0] = rhs._flags[0];
		this->_flags[1] = rhs._flags[1];
		this->_flags[2] = rhs._flags[2];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Convert const & i )
{
	o << "Arg : " << "\"" << i.getArg() << "\"" << std::endl << std::endl;
	if (i.Flag(0))
	{
		if (i.getChar() >= 32 && i.getChar() <= 126)
			o << "Char value \t : \t" << "\"" << i.getChar() << "\"" << std::endl;
		else
			o << "Char \t\t : \tnot displayable " << std::endl;
	}
	else
		o << "Char \t\t : \timpossible" << std::endl;
	if (i.Flag(1))
		o << "Int value \t : \t" << i.getInt()  << std::endl;
	else
		o << "Int \t\t : \timpossible" << std::endl;
	if (i.Flag(2))
	{
		if (i.getFloat() == static_cast<float>(i.getInt()))
			o << "Float value \t : \t" << std::setprecision(1) << std::fixed << i.getFloat() << "f" << std::endl;
		else
			o << "Float value \t : \t" << i.getFloat() << "f" << std::endl;
	}
	else
		o << "Float \t\t : \timpossible" << std::endl;
	if (i.getDouble() == static_cast<double>(i.getInt()))  
		o << "Double value \t : \t" << std::setprecision(1) << std::fixed << i.getDouble() << std::endl;
	else
		o << "Double value \t : \t" << i.getDouble() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Convert::init(const std::string &str)
{
	this->_c = 0;
	this->_float = 0;
	this->_int = 0;
	this->_double = 0;
	this->_flags[0] = 1;
	this->_flags[1] = 1;
	this->_flags[2] = 1;

	if (this->_type == 'C')
		this->_c = str[0];
	else if (this->_type == 'I')
	{
		double val;

		val = strtod(str.c_str(), NULL);
		if (val < -2147483648.0 || val > 2147483647.0)
			throw Convert::MaxInt();
		else
			this->_int = atoi(str.c_str());
	}
	else if (this->_type == 'D')
		this->_double = strtod(str.c_str(), NULL);
	else if (this->_type == 'F')
		this->_float = atof(str.c_str());
	else
		throw Convert::Invalid();
}

void	Convert::convert(void)
{
	if (this->_type == 'C')
		this->convert_c();
	if (this->_type == 'D')
		this->convert_d();
	if (this->_type == 'I')
		this->convert_i();
	if (this->_type == 'F')
		this->convert_f();
}

char	Convert::CheckParam(const std::string &str) const
{
	if (str.empty() == true)
		throw	Convert::Invalid();
	if (str[0] == '-' || str[0] == '+')
		return (checkSign(str));
	if (str[0] >= '0' && str[0] <= '9')
		return (checkNumber(str));
	if (str[0] >= 32 && str[0] <= 126)
		return (checkChar(str));
	throw	Convert::Invalid();
	return (0);
}

char	Convert::checkSign(const std::string& str) const
{

	if (str.length() == 1)
		return ('C');

	if (str[1] >= '0' && str[1] <= '9')
		return (this->checkNumber(str));

	if (str[0] == '-') {
		if (str.compare("-inf") == 0)
			return ('D');
		else if (str.compare("-inff") == 0)
			return ('F');
	}
	else if (str[0] == '+') {
		if (str.compare("+inf") == 0)
			return ('D');
		else if (str.compare("+inff") == 0)
			return ('F');
	}
	
	throw Convert::Invalid();
	return (0);
}

char	Convert::checkChar(const std::string& str) const {

	if (str.length() == 1)
		return ('C');
	
	if (str.compare("inf") == 0 || str.compare("nan") == 0)
		return ('D');
	else if (str.compare("inff") == 0 | str.compare("nanf") == 0)
		return ('F');

	throw Convert::Invalid();
	return (0);
}

char	Convert::checkNumber(const std::string& param) const {

	int	count = 0;
	int	start = 0;
	int	size = param.length();
	
	if (param[0] == '+' || param[0] == '-')
		start++;
		
	for (int i = start; i < size; i++)
		if (param[i] == '.')
			count++;

	if (count == 0) {
		for (int i = start; i < size; i++)
			if (param[i] < '0' || param[i] > '9')
				throw Convert::Invalid();
		return ('I');
	}
	else if (count == 1) {

		if (param[size - 1] == 'f') {
			for (int i = start;  i < size - 1; i++)
				if ((param[i] < '0' || param[i] > '9') && param[i] != '.')
					throw Convert::Invalid();
			return ('F');
		}
		else
		{
			for (int i = start;  i < size; i++)
				if ((param[i] < '0' || param[i] > '9') && param[i] != '.')
					throw Convert::Invalid();
			return ('D');
		}
	}
	
	throw Convert::Invalid();
	return (0);
}

int		Convert::Flag(int index) const {
	return (this->_flags[index]);
}

void	Convert::convert_c(void) {

	this->_int = static_cast<int>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	return;
}

void	Convert::convert_i(void) {

	this->_double = static_cast<double>(this->getInt());
	this->_float = static_cast<float>(this->getInt());

	if (this->_int < static_cast<int>(CHAR_MIN) || this->_int > static_cast<int>(CHAR_MAX))
		this->_flags[0] = 0;
	else
		this->_c = static_cast<char>(this->getInt());

	return;
}

void	Convert::convert_f(void) {

	this->_double = static_cast<double>(this->getFloat());

	if (this->_float != this->_float || this->_float == INFINITY || this->_float == -INFINITY) {
		this->_flags[0] = 0;
		this->_flags[1] = 0;
	}
	else {
		
		if (this->_double < static_cast<float>(CHAR_MIN) || this->_double > static_cast<double>(CHAR_MAX))
			this->_flags[0] = 0;
		else
			this->_c = static_cast<char>(this->getFloat());
		
		if (this->_double < static_cast<double>(INT_MIN) || this->_float > static_cast<double>(INT_MAX))
			this->_flags[1] = 0;
		else
			this->_int = static_cast<int>(this->getFloat());
	}
	return;
}

void	Convert::convert_d(void) {

	if (this->_double != this->_double || this->_double == INFINITY || this->_double == -INFINITY) {
		this->_flags[0] = 0;
		this->_flags[1] = 0;
		this->_float = static_cast<float>(this->getDouble());
	}
	else {

		if (this->_double < static_cast<double>(CHAR_MIN) || this->_double > static_cast<double>(CHAR_MAX))
			this->_flags[0] = 0;
		else
			this->_c = static_cast<char>(this->getDouble());
		
		if (this->_double < static_cast<double>(INT_MIN) || this->_double > static_cast<double>(INT_MAX))
			this->_flags[1] = 0;
		else
			this->_int = static_cast<int>(this->getDouble());

		this->_float = static_cast<float>(this->getDouble());
	}
}

std::string		Convert::getArg(void) const
{
	return (this->_arg);
}

char	Convert::getType(void) const
{
	return (this->_type);
}

char	Convert::getChar(void) const
{
	return (this->_c);
}

int		Convert::getInt(void) const
{
	return (this->_int);
}

float 	Convert::getFloat(void) const
{
	return (this->_float);
}

double 	Convert::getDouble(void) const
{
	return (this->_double);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Convert::Invalid::Invalid() throw() {}

Convert::Invalid::~Invalid() throw() {}

const char* Convert::Invalid::what() const throw() 
{
	return ("ERROR : param invalid\n");
}

Convert::MaxInt::MaxInt() throw() {}

Convert::MaxInt::~MaxInt() throw() {}

const char* Convert::MaxInt::what() const throw() 
{
	return ("ERROR : int above int max or below int min\n");
}



/* ************************************************************************** */