#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#define SHRUBBERY_SIGNED_GRADE 145
#define SHRUBBERY_EXEC_GRADE 137

#include <iostream>
#include <exception>
#include <string>
#include <fstream>

#include "../includes/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public: 
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm& copy );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );
        void execute( const Bureaucrat& executor ) const;
};

std::ostream &operator<<(std::ostream &out, AForm const &elem);

#endif