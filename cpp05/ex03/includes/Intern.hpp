#ifndef INTERN_H
#define INTERN_H

//------ librairies------------
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

//-------- Colors ------------
#define CLEAR "\e[0m"
#define YELLOW "\e[33m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
//----------------------------
class AForm;

class Intern{

    public:
        Intern( void );
        ~Intern( void );
        Intern( const Intern &copy );
        Intern &operator=( Intern const &copy );

        AForm*	shrubbery(std::string target);
        AForm*	presidential(std::string target);
        AForm*	robotomy(std::string target);
        AForm*   makeForm(std::string FormName, std::string FormTarget);

        class InexistingFormException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return("form does not exist.");
            }
        };
};

#endif