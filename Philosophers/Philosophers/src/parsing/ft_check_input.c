#include "../philosophers.h" 

bool ft_check(char **av, int ac)
{

    if(ac == 1)
        {
            red();
            printf("\n\n YOUR ENTERED NOTHING PLEASE ENTER YOUR ARGUMENTS\n\n");
            return(false);
        }

    if (!ft_isdigit(av[1]) || !ft_isdigit(av[2]) || !ft_isdigit(av[3])
        || !ft_isdigit(av[4]))
    {
            red();
            printf("\n\nARGUMENTS ERROR PLEASE ENTER VALIDE AND POSITIVE NUMBERS\n\n");
            return(false);
    }
    if (ac == 6)
        {
            if (!ft_isdigit(av[5]))
             {
                red();
                printf("\n\nARGUMENTS ERROR PLEASE ENTER VALIDE AND POSITIVE NUMBERS\n\n");
                return(false);
            }
        }
    return(true);
}