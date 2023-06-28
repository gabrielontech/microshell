#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned short int _gradeToSign;
        const unsigned short int _gradeToExecute;
    
    public:
        Form();
        Form(std::string name, unsigned short int gradeToSign, unsigned short int gradeToExecute);
        Form(const Form& copy);
        virtual ~Form();
        Form& operator=(const Form& rhs);
        std::string getName(void) const;
        bool getSigned(void) const;
        unsigned short int getGradeToSign(void) const;
        unsigned short int getGradeToExecute(void) const;
        void beSigned(Bureaucrat& bureaucrat);
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
                return ("Form not signed");
            }
        };
        class FormAlreadySignedException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("Form already signed");
            }
        };
        class FormAlreadyExecutedException : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("Form already executed");
            }
        };
};

std::ostream &operator<<(std::ostream &out, Form const &elem);

#endif