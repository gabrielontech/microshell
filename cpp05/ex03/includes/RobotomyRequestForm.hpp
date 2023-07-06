#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#define ROBOTOMY_SIGNED_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

#include <exception>
#include <string>
#include <iostream>
#include <fstream> 

#include "../includes/AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public: 
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );
        void execute( const Bureaucrat& executor ) const;
};

std::ostream &operator<<(std::ostream &out, AForm const &elem);
#endif