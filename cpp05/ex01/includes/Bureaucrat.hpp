#ifndef  BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "../includes/Form.hpp"

#define CLEAR "\e[0m"
#define YELLOW "\e[33m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        unsigned short int _grade;
    public:
        //constructors and destructors
        Bureaucrat();
        unsigned short int getGrade(void) const ;
        std::string getName(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form& form);
        Bureaucrat(std::string name, unsigned short int grade);
        Bureaucrat(const Bureaucrat& copy);
        virtual ~Bureaucrat();
        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("Grade too high");
            }
        };
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("Grade too Low");
            }
        };
        //overloads
        Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &elem);

#endif