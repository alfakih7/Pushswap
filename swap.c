/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:09:46 by almohame          #+#    #+#             */
/*   Updated: 2024/05/10 08:09:47 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_a = tmp;
		ft_printf("sa\n");
	}
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_b = tmp;
		ft_printf("sb\n");
	}
}

// ss : sa and sb at the same time.

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_a = tmp;
	}
	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_b = tmp;
	}
	ft_printf("ss\n");
}
