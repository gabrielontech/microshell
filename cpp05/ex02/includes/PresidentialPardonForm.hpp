#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP


#define PRESIDENTIAL_SIGNED_GRADE 25
#define PRESIDENTIAL_EXEC_GRADE 5

#include <iostream>
#include <exception>
#include <string>

#include "../includes/AForm.hpp"


class PresidentialPardonForm : public AForm
{
    public: 
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( const PresidentialPardonForm& copy );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );
        void execute( const Bureaucrat& executor ) const;
};

std::ostream &operator<<(std::ostream &out, AForm const &elem);
#endif