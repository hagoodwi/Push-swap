/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:36:44 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 19:14:11 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_it_2(t_stack **a, t_stack **b, t_commands *commands)
{
	if (!ft_strcmp(commands->command, "rrb"))
		rra(b);
	else if (!ft_strcmp(commands->command, "rrr"))
		rrr(a, b);
	else if (!ft_strcmp(commands->command, "ss"))
		ss(a, b);
	else if (!ft_strcmp(commands->command, "sb"))
		sa_sb(b);
	else if (!ft_strcmp(commands->command, "sa"))
		sa_sb(a);
}

void	do_it(t_stack **a, t_stack **b, t_commands *commands)
{
	while (commands)
	{
		if (!ft_strcmp(commands->command, "ra"))
			ra(a);
		else if (!ft_strcmp(commands->command, "rb"))
			ra(b);
		else if (!ft_strcmp(commands->command, "rr"))
			rr(a, b);
		else if (!ft_strcmp(commands->command, "pa"))
			pb(b, a);
		else if (!ft_strcmp(commands->command, "pb"))
			pb(a, b);
		else if (!ft_strcmp(commands->command, "rra"))
			rra(a);
		else
			do_it_2(a, b, commands);
		commands = commands->next;
	}
}

int		check_sort(t_stack *a, t_stack *b)
{
	t_stack	*dop;
	t_stack	*dop2;

	if (a == NULL && b != NULL)
		return (1);
	dop = a;
	dop2 = a->next;
	while (1)
	{
		if (dop->value > dop2->value)
			return (1);
		dop = dop->next;
		dop2 = dop2->next;
		if (dop2 == a)
			break ;
	}
	if (len_stack(b))
		return (1);
	return (0);
}

void	checker_commands(t_stack **a, t_stack **b, t_commands *commands)
{
	do_it(a, b, commands);
	if (check_sort(*a, *b))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}
