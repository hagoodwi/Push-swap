/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:04:01 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:04:31 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		check(char **args)
{
	int		i;
	int		k;

	while (*args)
	{
		i = 0;
		k = 0;
		if ((*args)[0] == '+' || (*args)[0] == '-')
		{
			if (ft_strlen(*args) == 1)
				return (1);
			i++;
		}
		while ((*args)[i])
		{
			if ((*args)[i] < '0' || (*args)[i] > '9')
				return (1);
			i++;
		}
		args++;
	}
	return (0);
}

int		check_duplicate(t_stack *a, int value)
{
	t_stack		*dop;

	if (a == NULL)
		return (0);
	dop = a;
	while (1)
	{
		if (dop->value == value)
			return (1);
		dop = dop->next;
		if (dop == a)
			break ;
	}
	return (0);
}
