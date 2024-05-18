/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:12:32 by almohame          #+#    #+#             */
/*   Updated: 2024/05/12 13:56:19 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num(t_stack *stack, int target)
{
	while (--target)
		stack = stack->next;
	return (stack->data);
}

int	ascending(t_stack *stack, int target1, int target2)
{
	return (get_num(stack, target1) < get_num(stack, target2));
}

t_stack	*ft_stack_last(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	return (stack_a);
}

void	ft_add_to_a(t_stack **stack_a, t_stack *new)
{
	t_stack	*p;

	if (!stack_a || !new)
		return ;
	else if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		p = ft_stack_last(*stack_a);
		p->next = new;
	}
}

t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
int	ft_print_str(int fd, char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s != 0 && s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
