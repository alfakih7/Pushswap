/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:11:54 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 15:58:15 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct stack
{
	int				data;
	int				index;
	struct stack	*next;
}					t_stack;

t_stack				*ft_stack_last(t_stack *stack_a);
t_stack				*ft_new_node(int data);
long long			ft_atoi_p(const char *str);
void				give_indexes(t_stack **stack_a);
void				handle_errors(t_stack **stack_a, char **av);
int					ft_print_str(int fd, char *s);
int					ft_check(t_stack **stack_a);
int					ascending(t_stack *stack, int target1, int target2);
int					get_num(t_stack *stack, int target);
int					ft_stack_size(t_stack *stack_a);
int					ft_get_min(t_stack **stack_a);
char				**ft_split(char const *s, char c);
void				ft_add_to_a(t_stack **stack_a, t_stack *new);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ft_free(t_stack **stack_a, t_stack **stack_b);
void				ft_check_if_sorted(t_stack **stack_a, int i);
void				ft_sort_three(t_stack **stack_a);
void				ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void				ft_radix(t_stack **stack_a, t_stack **stack_b);
#endif