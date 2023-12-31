#include "../includes/Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern constructor by copy called" << std::endl;
}

Intern &Intern::operator=(Intern const &copy)
{
    (void)copy;
    return (*this);
}

AForm *Intern::shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::presidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::robotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    typedef AForm *(Intern::*func)(std::string target);

    func array[3] = {&Intern::shrubbery,
                     &Intern::presidential,
                     &Intern::robotomy};

    std::string type[3] = {"shrubbery creation",
                           "presidential pardon",
                           "robotomy request"};
    for (int i = 0; i < 3; i++)
    {
        if (type[i] == form)
        {
            std::cout << "Intern create " << type[i] << " form" << std::endl;
            return (this->*array[i])(target);
        }
    }
    throw InexistingFormException();
    return 0;
}