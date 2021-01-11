/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:08:54 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:10:51 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	defualt(int *min_cur, int *i, int *len, t_stack *a)
{
	*min_cur = -2147483648;
	*len = len_stack(a);
	*i = 0;
}

void	indexation(t_stack *a)
{
	int		min_cur;
	int		min_next;
	int		i;
	t_stack	*dop;
	int		len;

	defualt(&min_cur, &i, &len, a);
	while (i < len)
	{
		min_next = 2147483647;
		dop = a;
		while (1)
		{
			if (dop->value > min_cur)
				dop->index = i;
			if (dop->value > min_cur && dop->value < min_next)
				min_next = dop->value;
			dop = dop->next;
			if (dop == a)
				break ;
		}
		i++;
		min_cur = min_next;
	}
}

int		len_stack(t_stack *a)
{
	t_stack	*dop;
	int		len;

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
