/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:11:59 by almohame          #+#    #+#             */
/*   Updated: 2024/05/17 19:46:30 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p)
	{
		tmp = p->next;
		p->next = *stack_a;
		*stack_a = p;
		*stack_b = tmp;
		ft_printf("pa\n");
	}
}

// pb (push b): Take the first element at the top of a and put it
//  at the top of b. Do nothing if a is empty

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p)
	{
		tmp = p->next;
		p->next = *stack_b;
		*stack_b = p;
		*stack_a = tmp;
		ft_printf("pb\n");
	}
}
