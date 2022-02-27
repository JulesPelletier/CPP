#include "../includes/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(void) : _name("Empty"), _grade(150)
{
	std::cout << Yellow "Default constructor called for Bureaucrat" Reset << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	checkGrade();
	std::cout << Purple "Constructor called for Bureaucrat" Reset << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << Blue "Copy constructor called for Bureaucrat" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << Yellow "Default destructor called for Bureaucrat" Reset << std::endl;

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << "'s grade is = " << i.getGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	const		&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	const				&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::bettergrade(void)
{
	this->_grade = this->_grade - 1;
	checkGrade();
	std::cout << this->_name << Cyan "'s grade was updated to " Reset << this->_grade << std::endl;
}

void				Bureaucrat::worsegrade(void)
{
	this->_grade = this->_grade + 1;
	checkGrade();
	std::cout << this->_name << Cyan "'s grade was updated to " Reset << this->_grade << std::endl;
}

void	Bureaucrat::checkGrade(void)
{
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned() == true)
		std::cout << "Form is already signed" << std::endl;
	else if (this->_grade <= form.getGSign())
	{
		form.beSigned(*this);
		std::cout << form.getName() << Cyan " signed the contract of " Reset << this->_name << std::endl;
	}
	else
		std::cout << form.getName() << Cyan " didn't sign the contract of " Reset << this->_name << std::endl;

}

void		Bureaucrat::executeForm(Form &form) const
{
	form.execute(*this);
	std::cout << std::endl;
	std::cout << Green << this->_name << Reset " executed the form" << std::endl;
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (Red "Error : grade is too low" Reset);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (Red "Error : grade is too high" Reset);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */