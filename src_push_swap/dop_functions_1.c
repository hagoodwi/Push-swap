/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:55:12 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:57:56 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_commands(t_commands *commands)
{
	int			i;
	t_commands	*dop;

	i = 0;
	dop = commands;
	while (dop)
	{
		i++;
		dop = dop->next;
	}
	return (i);
}

int			add_command(t_commands **commands, char *str)
{
	t_commands	*dop;

	dop = *commands;
	if (dop == NULL)
	{
		if (!(dop = malloc(sizeof(t_commands))))
			return (1);
		dop->next = NULL;
		if (!(dop->command = ft_strdup(str)))
			return (1);
		*commands = dop;
	}
	else
	{
		while (dop->next != NULL)
			dop = dop->next;
		if (!(dop->next = malloc(sizeof(t_commands))))
			return (1);
		dop->next->next = NULL;
		if (!(dop->next->command = ft_strdup(str)))
			return (1);
	}
	return (0);
}

t_stack		*min_in_stack(t_stack *a)
{
	t_stack		*min;
	t_stack		*dop;

	min = a;
	if (len_stack(a) == 1)
		return (a);
	dop = a;
	while (1)
	{
		if (dop->value < min->value)
			min = dop;
		dop = dop->next;
		if (dop == a)
			break ;
	}
	return (min);
}

t_shift		*create_shift(void)
{
	t_shift		*shift;

	shift = malloc(sizeof(t_shift));
	if (shift == NULL)
		return (NULL);
	shift->a_dir = R;
	shift->a_elem = NULL;
	shift->b_elem = NULL;
	shift->b_dir = R;
	shift->a_kol = -1;
	shift->b_kol = -1;
	shift->is_set = false;
	return (shift);
}

int			max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
