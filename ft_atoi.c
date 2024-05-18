/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almohame <almohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:10:23 by almohame          #+#    #+#             */
/*   Updated: 2024/05/18 13:01:09 by almohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_p(const char *str)
{
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	if (!*str)
		return (999999999999);
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*(str++) - '0');
		if (result > 2147483647 && sign == 1)
		{
			return (999999999999);
		}
		if (result - 1 > 2147483647 && sign == -1)
			return (999999999999);
	}
	if (*str)
		return (999999999999);
	return (result * sign);
}
