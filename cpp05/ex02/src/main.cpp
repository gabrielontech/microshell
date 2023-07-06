#include "../includes/Bureaucrat.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"

int main()
{   
    {
        try
        {  
            std::cout << MAGENTA << "---------------------------------------" << std::endl;
            std::cout << " Tests with valid grade to sign and execute Form " << std::endl;
            std::cout << "---------------------------------------" << CLEAR << std::endl;

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Bureaucrat Creation "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Bureaucrat Helen("Helen", 1);
            Bureaucrat Tom("Tom", 70);
            Bureaucrat Mathis("Mathis", 4);

            std::cout << Helen;
            std::cout << Tom;
            std::cout << Mathis;
    
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Forms Creation "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            ShrubberyCreationForm ShcrubberyAgreement("ShcrubberyAgreement");
            PresidentialPardonForm PresidentialAgreement("PresidentialAgreement");
            RobotomyRequestForm RobotomyAgreement("RobotomyAgreement");
            std::cout << ShcrubberyAgreement;
            std::cout << PresidentialAgreement;
            std::cout << RobotomyAgreement;

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Forms signature "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;

            Helen.signForm(ShcrubberyAgreement);
            Helen.signForm(PresidentialAgreement);
            Helen.signForm(RobotomyAgreement);
            std::cout << ShcrubberyAgreement;
            std::cout << PresidentialAgreement;
            std::cout << RobotomyAgreement;

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Forms execution "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN  << " SCHRUBBERY EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(ShcrubberyAgreement);

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN << " PRESIDENTIAL EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(PresidentialAgreement);

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN << " ROBOTIMISATION EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(RobotomyAgreement);
            Helen.executeForm(RobotomyAgreement);
            Helen.executeForm(RobotomyAgreement);
            Helen.executeForm(RobotomyAgreement);

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Objects Destruction "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << '\n';
        }
    }
    // Tests with invalid grade to sign Form 
    {
    std::cout << MAGENTA << "---------------------------------------" << std::endl;
    std::cout << " Tests with invalid grade to sign Form " << std::endl;
    std::cout << "---------------------------------------" << CLEAR << std::endl;
    try
    {
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " Bureaucrat Creation "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        Bureaucrat Helen("Helen", 146);
        
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " Forms Creation "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;

        ShrubberyCreationForm ShcrubberyAgreement("ShcrubberyAgreement");
        std::cout << ShcrubberyAgreement;

        Helen.signForm(ShcrubberyAgreement);
        std::cout << ShcrubberyAgreement;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    }
    // Test with form nor signed
    {
        try
        {
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Bureaucrat Creation "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Bureaucrat Helen("Helen", 146);

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Forms Creation "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;

            ShrubberyCreationForm ShcrubberyAgreement("ShcrubberyAgreement");
            PresidentialPardonForm PresidentialAgreement("PresidentialAgreement");
            RobotomyRequestForm RobotomyAgreement("RobotomyAgreement");
            std::cout << ShcrubberyAgreement;
            std::cout << PresidentialAgreement;
            std::cout << RobotomyAgreement;

            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN  << " SCHRUBBERY EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(ShcrubberyAgreement);  
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN << " PRESIDENTIAL EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(PresidentialAgreement);   
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << CYAN << " ROBOTIMISATION EXECUTION "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            Helen.executeForm(RobotomyAgreement);
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
            std::cout << GREEN << " Objects Destruction "<< CLEAR << std::endl;
            std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        // Tests with invalid grade to executeForm Form
        {
            std::cout << MAGENTA << "---------------------------------------" << std::endl;
            std::cout << " Tests with invalid grade to executeForm Form" << std::endl;
            std::cout << "---------------------------------------" << CLEAR << std::endl;
            try
            {
                Bureaucrat Tom("Tom", 20);
                Bureaucrat Helen("Helen", 6);
                std::cout << Tom;
                std::cout << Helen;
                PresidentialPardonForm PresidentialAgreement("PresidentialAgreement");
                std::cout << PresidentialAgreement;
                Tom.signForm(PresidentialAgreement);
                std::cout << PresidentialAgreement;

                Helen.executeForm(PresidentialAgreement);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    } 
}