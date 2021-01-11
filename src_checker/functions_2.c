/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:26:40 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 19:26:43 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*end;

	if (*a == NULL)
		return ;
	end = *a;
	while (end->next != *a)
		end = end->next;
	end->next = (*a)->next;
	(*a)->next = *b;
	(*b) = *a;
	*a = *a == end ? NULL : end->next;
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
	int	len;

	len = len_stack(*a);
	if (len == 0 || len == 1)
		return ;
	*a = (*a)->next;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
}
