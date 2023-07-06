#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"

// main du sujet 
/*int main()
{   
    try
    {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return(0);
}*/

// main perso 
int main()
{   
    std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
    std::cout << MAGENTA << " Test with existing form  "<< CLEAR << std::endl;
    std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
    try
    {   
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " Intern Creation "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        Intern intern;
        AForm *RobotomyForm;
        AForm* ShrubberyForm;
        AForm* PresidentialForm;

        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " AForm Creation "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        RobotomyForm = intern.makeForm("robotomy request", "Tom");
        ShrubberyForm = intern.makeForm("shrubbery creation", "Laurie");
        PresidentialForm = intern.makeForm("presidential pardon", "Manon");

        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " Bureaucrat Creation "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        Bureaucrat Helen("Helen", 5);
        std::cout << Helen;

        Helen.signForm(*RobotomyForm);
        Helen.executeForm(*RobotomyForm);
        std::cout << *RobotomyForm;

        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << GREEN << " Objects Destruction "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        delete RobotomyForm;
        delete ShrubberyForm;
        delete PresidentialForm;;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    {
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
        std::cout << MAGENTA << " Test with inexisting form  "<< CLEAR << std::endl;
        std::cout << YELLOW << "---------------------------------------" << CLEAR << std::endl;
    try
    {   
        Intern intern;
        AForm* RobotomyForm;

        RobotomyForm = intern.makeForm("I don't exists", "Bender");
        
        delete RobotomyForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    }
    return(0);
}