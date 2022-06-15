// t_stack	*ft_create_a(int nbr, t_stack *stack_a)
// {
// 	t_stack	*new;
// 	t_stack	*tmp;

// 	tmp = stack_a;
// 	while (stack_a != NULL && stack_a->next != NULL)
// 		stack_a = stack_a->next;
// 	new = malloc(sizeof(t_stack));
// 	if (!new)
// 		return (0);
// 	new->data= nbr;
// 	new->index = -1;
// 	new->next = NULL;
// 	if (tmp == NULL)
// 		tmp = new;
// 	else
// 		stack_a->next = new;
// 	return (tmp);
// }
