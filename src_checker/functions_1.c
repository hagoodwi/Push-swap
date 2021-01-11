/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:24:13 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 19:24:16 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_sb(t_stack **a)
{
	int		len;
	t_stack	*dop;
	t_stack	*end;

	len = len_stack(*a);
	if (len == 0 || len == 1)
		return ;
	end = *a;
	dop = (*a)->next;
	while (end->next != *a)
		end = end->next;
	(*a)->next = dop->next;
	dop->next = *a;
	end->next = dop;
	*a = dop;
}

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	rra(t_stack **a)
{
	int		len;
	t_stack	*dop;

	len = len_stack(*a);
	if (len == 0 || len == 1)
		return ;
	dop = *a;
	while (dop->next != *a)
		dop = dop->next;
	*a = dop;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rra(b);
}
