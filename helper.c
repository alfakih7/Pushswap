/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:15:13 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 18:51:52 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_check_dup(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*check2;

	while (stack_a)
	{
		check = stack_a;
		while (check)
		{
			check2 = check;
			while (check2->next)
			{
				check2 = check2->next;
				if (check2->data == check->data)
				{
					ft_free(&stack_a, NULL);
					exit(write(2, "Error\n", 6));
				}
			}
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

static void	ft_set_a(t_stack **stack_a, char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		if (ft_atoi_p(args[i]) != 999999999999)
			ft_add_to_a(stack_a, ft_new_node(ft_atoi_p(args[i])));
		else if (ft_atoi_p(args[i]) == 999999999999)
		{
			i = 0;
			while (args[i])
				free(args[i++]);
			free(args);
			ft_free(stack_a, NULL);
			exit(write(2, "Error\n", 6));
		}
		i++;
	}
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	handle_errors(t_stack **stack_a, char **av)
{
	int		i;
	char	**args;

	i = 1;
	while (av[i])
	{
		args = ft_split(av[i++], ' ');
		if (!args || !args[0])
		{
			ft_set_a(stack_a, args);
			ft_free(stack_a, NULL);
			exit(ft_print_str(2, "Error\n"));
		}
		ft_set_a(stack_a, args);
	}
	ft_check_dup(*stack_a);
	ft_check_if_sorted(stack_a, i);
}
