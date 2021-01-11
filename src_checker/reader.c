/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:37:30 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 19:39:36 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_com(char *str)
{
	if (!(!ft_strcmp(str, "ra") ||
		!ft_strcmp(str, "rb") ||
		!ft_strcmp(str, "rr") ||
		!ft_strcmp(str, "pa") ||
		!ft_strcmp(str, "pb") ||
		!ft_strcmp(str, "rra") ||
		!ft_strcmp(str, "rrb") ||
		!ft_strcmp(str, "rrr") ||
		!ft_strcmp(str, "ss") ||
		!ft_strcmp(str, "sb") ||
		!ft_strcmp(str, "sa")))
		return (1);
	return (0);
}

int		new_lst(t_commands **commands, char *buff)
{
	t_commands		*new;
	t_commands		*dop;

	if (check_com(buff))
	{
		free(buff);
		return (1);
	}
	new = malloc(sizeof(t_commands));
	if (*commands)
	{
		dop = *commands;
		while (dop->next)
			dop = dop->next;
		dop->next = new;
		new->command = buff;
		new->next = NULL;
		return (0);
	}
	new->command = buff;
	new->next = NULL;
	*commands = new;
	return (0);
}

int		reader(t_commands **commands)
{
	char	*buff;
	int		i;

	i = 0;
	*commands = NULL;
	while ((i = get_next_line(0, &buff)))
	{
		if (i == -1)
			return (1);
		if (new_lst(commands, buff))
			return (1);
	}
	return (0);
}
