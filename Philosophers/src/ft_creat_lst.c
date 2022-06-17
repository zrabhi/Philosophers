#include "philosophers.h"

t_list *ft_newnode(int id)
{
    t_list *lst;

    lst = malloc(sizeof(t_list));
    if(!lst)
        return(NULL);
    lst->id   = id;
    lst->index = 0;
    lst->is_dead  = 0;
    lst->left_fork = 0;
    lst->right_fork = 0;
    lst->next = NULL;
    lst->previous = NULL;
    return(lst);
}

void ft_get_lst(int philo_number, t_data *data)
{
    t_list *lst;
    int i;
    
    i = -1;
    while(++i < philo_number)
        ft_crearlst(&data, ft_newnode(i));
}


void    ft_crearlst(t_data **data, t_list *lst)
{
    t_list *tmp;

    if((*data))
    {
        if ((*data)->head)
        {
            (*data)->head = lst;
            (*data)->tail = lst;
            (*data)->head->next = NULL;
            (*data)->head->previous = (*data)->tail;
        }
        else
        {
            tmp = (*data)->head;
            (*data)->head = lst;
            (*data)->head->previous = (*data)->tail;
            lst->next = tmp;
            tmp->previous = (*data)->head;
            (*data)->tail->next = NULL;
        }
    }
}