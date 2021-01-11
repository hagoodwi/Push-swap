/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:26:53 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:06:10 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check(char **args)
{
	int	i;
	int	k;

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
	t_stack	*dop;

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

int		add_list(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*dop;

	if (check_duplicate(*a, value))
		return (1);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (1);
	new->value = value;
	new->next = new;
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
