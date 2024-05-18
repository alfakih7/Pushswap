/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:12:06 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 16:00:29 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	while (p && p->next)
	{
		if (ascending(p, 1, 2))
			p = p->next;
		else
			return (1);
	}
	return (0);
}

int	ft_get_min(t_stack **stack_a)
{
	int		min_value;
	t_stack	*p;

	p = *stack_a;
	min_value = p->data;
	while (p)
	{
		if (min_value > p->data)
			min_value = p->data;
		p = p->next;
	}
	return (min_value);
}

static int	ft_max_bit(t_stack **stack_a)
{
	t_stack	*p;
	int		i;
	int		j;

	j = 0;
	p = *stack_a;
	i = ft_stack_size(p);
	while (i)
	{
		i /= 2;
		j++;
	}
	return (j);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	t_stack	*p;

	i = -1;
	give_indexes(stack_a);
	while (ft_check(stack_a) && ++i < ft_max_bit(stack_a))
	{
		p = *stack_a;
		j = ft_stack_size(p);
		while (j--)
		{
			p = *stack_a;
			if (p && !((p->index >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		p = *stack_b;
		while (p)
		{
			pa(stack_a, stack_b);
			p = *stack_b;
		}
	}
}
