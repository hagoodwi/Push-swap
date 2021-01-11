/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:52:28 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 19:52:33 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		len_commands(t_commands *commands)
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

int		len_stack(t_stack *a)
{
	t_stack		*dop;
	int			len;

	len = 0;
	dop = a;
	if (a == NULL)
		return (0);
	while (1)
	{
		len++;
		dop = dop->next;
		if (dop == a)
			break ;
	}
	return (len);
}
