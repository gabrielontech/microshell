#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
    protected:
        const std::string _name;
        unsigned short int grade;
    public:
        //constructors and destructors
        Bureaucrat();
        int getGrade();
        std::String getName();
        IncrementGrade(unsigned short int grade);
        DecrementGrade(unsigned short int grade);
        Bureaucrat(std::string type);
        Bureaucrat(const Bureaucrat& other);
        virtual ~Bureaucrat();
        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Grade too high");
            }
        }
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Grade too Low");
            }
        }
        //overloads
        Bureaucrat& operator=(const Bureaucrat& rhs);
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &elem);

#endif