#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm " << this->_name << " created" << std::endl;
}

AForm::AForm(std::string name, unsigned short int gradeToSign, unsigned short int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "AForm " << this->_name << " created" << std::endl;
    this->_signed = copy._signed;
}

unsigned short int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

unsigned short int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

std::string AForm::getTarget(void) const
{
    return (this->_target);
}

bool AForm::getSigned(void) const
{
    return (this->_signed);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    else if (this->_signed)
        throw AForm::FormAlreadySignedException();
    else
        this->_signed = true;
}


AForm::~AForm()
{
    std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs)
{
    out << rhs.getName() << " and requires grade " << rhs.getGradeToSign() << " to be signed and grade " << rhs.getGradeToExecute() << " to be executed" << std::endl;
    return (out);
}