#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, unsigned short int grade ): _name(name), _grade(grade)
{
    if (this->_grade < 1)
       throw Bureaucrat::GradeTooHighException();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Constructor called for: " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor of Bureaucrat called " << std::endl;
    return ;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor of Bureaucrat called " << std::endl;
    return ;
}

unsigned short int Bureaucrat::getGrade(void) const
{
    return(this->_grade);
}

Bureaucrat  &Bureaucrat::operator=( Bureaucrat const &rhs )
{
    this->_grade = rhs.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
     std::cout << "Bureaucrat construtor by copy called for: " << std::endl;
    *this = copy;
}

std::string Bureaucrat::getName(void) const
{
    return(this->_name);
}

void Bureaucrat::incrementGrade(void)
{
    this->_grade++;
}

void Bureaucrat::decrementGrade(void)
{
    this->_grade--;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &elem)
{
    out << elem.getName() << ","<< " bureaucrat grade " << elem.getGrade() << "."<<std::endl;
    return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}