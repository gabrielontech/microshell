#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
    try
    {
            Bureaucrat  bureaucrat("Bureaucrat", 1);
            Bureaucrat bureau2("petit joueur", 150);
            Form        form("Form", 1, 5);

            bureaucrat.signForm(form);
            bureaucrat.signForm(form);
            bureau2.signForm(form);
            
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}