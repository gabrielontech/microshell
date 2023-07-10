#include <stdio.h>
#include <stdlib.h>
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", SHRUBBERY_SIGNED_GRADE, SHRUBBERY_EXEC_GRADE)
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, SHRUBBERY_SIGNED_GRADE, SHRUBBERY_EXEC_GRADE)
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
        this->AForm::operator=(rhs);
    return (*this);
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::string outfile = AForm::getTarget() + "_shrubbery";
	    std::ofstream file(outfile.c_str());
        if (!file)
        {
            std::cout << RED "Error: can't create the file" CLEAR << std::endl;
            return;
        }
        file << "       _-_" << std::endl;
        file << "    /~~   ~~\\" << std::endl;
        file << " /~~         ~~\\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\\\ //  ~" << std::endl;
        file << "_- -   | | _- _" << std::endl;
        file << "  _ -  | |   -_" << std::endl;
        file << "      // \\\\" << std::endl;
        file << "     //   \\\\" << std::endl;
        file << "    //     \\\\" << std::endl;
        file << "   //       \\\\" << std::endl;
        file << "  //         \\\\" << std::endl;
        file << " //           \\\\" << std::endl;
        file << "//             \\\\" << std::endl;
        file << "___________________" << std::endl;
        file.close();
    }
}