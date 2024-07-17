
void	ft_print(t_list *a)
{
	t_list	*temp_a;
	int		i;

	temp_a = a;
	i = 1;
	while (temp_a)
	{
		printf("NOEUD %d\n", i);
		printf("value %d\n", temp_a->value);
		printf("position %d\n", temp_a->position);
		printf("cost %d\n", temp_a->cost);
		printf("temp %s\n", temp_a->temp);
		if (temp_a->target)
			printf("target->value %d\n\n", temp_a->target->value);
		else
			printf("\n");
		i++;
		temp_a = temp_a->next;
	}
}

void ft_forward_pointer(t_list *a)
{
	t_list *first_node;
	t_list *second_node;
	t_list *third_node;

	first_node = a;
	second_node = a->next;
	third_node = a->next->next;
	
	first_node->next = third_node;
	second_node->next = third_node->next;
	third_node->next = second_node;
}

void ft_incr(int *i)
{
	(*i)++;
}

int main(int ac, char **av)
{
    int i = 0;
	(void)ac;
	(void)av;
    // t_list *stack_a;

    // while (i < ac)
    // {
    //     ft_lstadd_back(&stack_a, ft_lstnew(av[i]));
	// 	i++;
    // }

	// ft_print(stack_a);
	// ft_forward_pointer(stack_a);
	// ft_print(stack_a);

	ft_incr(&i);
	
	printf("%d\n", i);

	return (0);
}
