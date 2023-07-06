#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

//-------- Colors ------------
#define CLEAR "\e[0m"
#define YELLOW "\e[33m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
# define MAGENTA  "\x1B[35m"
//----------------------------

#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const std::string _target;
        bool _signed;
        const unsigned short int _gradeToSign;
        const unsigned short int _gradeToExecute;
    
    public:
        AForm();
        AForm(std::string name, unsigned short int gradeToSign, unsigned short int gradeToExecute);
        AForm(const AForm& copy);
        virtual ~AForm();
        AForm& operator=(const AForm& rhs);
        std::string getName(void) const;
        bool getSigned(void) const;
        unsigned short int getGradeToSign(void) const;
        unsigned short int getGradeToExecute(void) const;
        void beSigned(Bureaucrat& bureaucrat);
        virtual void   execute( const Bureaucrat &executor ) const = 0;
        std::string getTarget(void) const;
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
        class FormNotSignedException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("AForm not signed");
            }
        };
        class FormAlreadySignedException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("AForm already signed");
            }
        };
        class FormAlreadyExecutedException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("AForm already executed");
            }
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &elem);

#endif