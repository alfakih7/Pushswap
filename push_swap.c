/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:11:43 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 16:00:47 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*tmp;

	if (stack_a && *stack_a)
	{
		p = *stack_a;
		while (p)
		{
			tmp = p->next;
			free(p);
			p = tmp;
		}
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		p = *stack_b;
		while (p)
		{
			tmp = p->next;
			free(p);
			p = tmp;
		}
		*stack_b = NULL;
	}
}

void	ft_check_if_sorted(t_stack **stack_a, int i)
{
	t_stack	*p;

	if (i < 2)
	{
		ft_free(stack_a, NULL);
		exit(0);
	}
	p = *stack_a;
	while (p && p->next && p->data < p->next->data)
		p = p->next;
	if (!p->next)
	{
		ft_free(stack_a, NULL);
		exit(0);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		if (!av[1][0])
			exit(write(2, "Error\n", 6));
		handle_errors(&stack_a, av);
		ft_sort_stack(&stack_a, &stack_b);
	}
	return (ft_free(&stack_a, &stack_b), 0);
}
