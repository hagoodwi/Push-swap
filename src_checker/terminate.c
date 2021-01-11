/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:00:50 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:02:51 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_exit(t_stack **a, t_stack **b, t_commands **commands)
{
	stack_free(a);
	stack_free(b);
	commands_free(commands);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	clear(t_stack **a, t_stack **b, t_commands **commands)
{
	stack_free(a);
	stack_free(b);
	commands_free(commands);
}

void	stack_free(t_stack **a)
{
	t_stack	*dop;
	t_stack	*end;

	if (*a == NULL)
		return ;
	end = *a;
	while (end->next != *a)
		end = end->next;
	while (1)
	{
		dop = (*a);
		*a = (*a)->next;
		if (dop == end)
		{
			free(dop);
			break ;
		}
		free(dop);
	}
	*a = NULL;
}

void	commands_free(t_commands **commands)
{
	t_commands	*dop;

	if (*commands == NULL)
		return ;
	while (*commands)
	{
		dop = *commands;
		*commands = (*commands)->next;
		free(dop->command);
		free(dop);
	}
}
