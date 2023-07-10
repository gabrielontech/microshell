#include <stdio.h>
#include <stdlib.h>
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", ROBOTOMY_SIGNED_GRADE, ROBOTOMY_EXEC_GRADE)
{
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, ROBOTOMY_SIGNED_GRADE, ROBOTOMY_EXEC_GRADE)
{
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << this->getName() << " destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
        this->AForm::operator=(rhs);
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "* drilling noises *" << std::endl;
        if (rand() % 2 == 0)
            std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->getTarget() << " robotomization failed" << std::endl;
    }
}