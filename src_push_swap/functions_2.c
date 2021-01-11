/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:08:00 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:08:23 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack		*end;

	end = *a;
	while (end->next != *a)
		end = end->next;
	end->next = (*a)->next;
	(*a)->next = *b;
	(*b) = *a;
	if (*a == end)
		*a = NULL;
	else
		*a = end->next;
	if ((*b)->next == NULL)
		(*b)->next = *b;
	else
	{
		end = *b;
		while (1)
		{
			end = end->next;
			if (end->next == (*b)->next)
				break ;
		}
		end->next = *b;
	}
}

void	ra(t_stack **a)
{
	*a = (*a)->next;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
}
