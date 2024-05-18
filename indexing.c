/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:56:22 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 16:06:43 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*convert_stack_to_array(t_stack *stack_a)
{
	int		size_stack;
	int		*array;
	t_stack	*tmp;
	int		i;

	size_stack = ft_stack_size(stack_a);
	array = (int *)malloc(sizeof(int) * size_stack);
	if (!array)
		return (NULL);
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

static void	give_element_index(t_stack **stack_a, int element, int index)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->data == element)
		{
			tmp->index = index;
			return ;
		}
		tmp = tmp->next;
	}
}

void	give_indexes(t_stack **stack_a)
{
	int	stack_size;
	int	*array;
	int	i;

	stack_size = ft_stack_size(*stack_a);
	array = convert_stack_to_array(*stack_a);
	bubble_sort(array, stack_size);
	i = 0;
	while (i < stack_size)
	{
		give_element_index(stack_a, array[i], i);
		i++;
	}
	free(array);
}
