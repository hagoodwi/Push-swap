/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:23:38 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:24:49 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		r_rotate(t_stack *head, t_stack *elem)
{
	t_stack	*dop;
	int		i;

	i = 0;
	dop = head;
	while (dop != elem)
	{
		dop = dop->next;
		i++;
	}
	return (i);
}

int		rr_rotate(t_stack *head, t_stack *elem)
{
	t_stack	*dop;
	int		i;
	int		len;

	i = 0;
	dop = head;
	len = len_stack(head);
	while (dop != elem)
	{
		dop = dop->next;
		i++;
	}
	if (i == 0)
		return (0);
	return (len - i);
}
