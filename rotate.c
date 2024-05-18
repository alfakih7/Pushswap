/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:09:56 by almohame          #+#    #+#             */
/*   Updated: 2024/05/10 08:10:06 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
		ft_printf("ra\n");
	}
}
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
		ft_printf("rb\n");
	}
}

// rr : ra and rb at the same time.

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
	}
	p = *stack_b;
	if (p && p->next)
	{
		tmp = p->next;
		ft_stack_last(*stack_b)->next = p;
		p->next = NULL;
		*stack_b = tmp;
	}
	ft_printf("rr\n");
}
