/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:12:52 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:15:28 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_list(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*dop;

	if (check_duplicate(*a, value))
		return (1);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (1);
	new->head_val = 0;
	new->index = -1;
	new->value = value;
	new->next = new;
	new->correct_pos = false;
	if (*a)
	{
		dop = *a;
		while (dop->next != *a)
			dop = dop->next;
		dop->next = new;
		new->next = *a;
		return (0);
	}
	*a = new;
	return (0);
}

int		init(t_stack **a, char **av)
{
	int			i;
	long long	num;

	i = 0;
	if (check(av))
		return (1);
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if ((num == 0 || num == -1) && ft_strlen(av[i]) > 2)
			return (1);
		if (num == 0 && ft_strlen(av[i]) == 2 && av[i][0] == '0')
			return (1);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		if (add_list(a, (int)num))
			return (1);
		i++;
	}
	return (0);
}

void	default_data(t_data **data)
{
	(*data)->commands1 = NULL;
	(*data)->commands2 = NULL;
	(*data)->a = NULL;
	(*data)->a1 = NULL;
	(*data)->a2 = NULL;
	(*data)->b = NULL;
}

t_data	*initialization(int ac, char **av)
{
	t_data	*data;
	char	**str;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		do_exit(&data);
	default_data(&data);
	av++;
	str = av;
	if (ac == 2)
		if (!(str = ft_strsplit(av[0], ' ')))
			do_exit(&data);
	if (init(&data->a1, str) || init(&data->a2, str))
	{
		if (str != av)
			ft_arfree(&str);
		do_exit(&data);
	}
	if (ac == 2)
		ft_arfree(&str);
	return (data);
}
