#include "../includes/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(std::string name, unsigned short int gradeToSign, unsigned short int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form " << this->_name << " created" << std::endl;
    this->_signed = copy._signed;
}

unsigned short int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

unsigned short int Form::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_signed);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else if (this->_signed)
        throw Form::FormAlreadySignedException();
    else
        this->_signed = true;
}

Form::~Form()
{
    std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}