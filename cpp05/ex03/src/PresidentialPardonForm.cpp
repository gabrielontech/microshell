#include <stdio.h>
#include <stdlib.h>
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", PRESIDENTIAL_SIGNED_GRADE, PRESIDENTIAL_EXEC_GRADE)
{
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, PRESIDENTIAL_SIGNED_GRADE, PRESIDENTIAL_EXEC_GRADE)
{
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm " << this->getName() << " destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
        this->AForm::operator=(rhs);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}


