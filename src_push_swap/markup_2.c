/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:19:51 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:20:42 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	true_elements2(t_stack *a)
{
	t_stack	*dop;
	int		num;
	int		prev_index;

	num = 1;
	dop = a->next;
	prev_index = a->index;
	while (1)
	{
		if (dop->index > prev_index)
		{
			num++;
			prev_index = dop->index;
		}
		dop = dop->next;
		if (dop == a)
			break ;
	}
	a->head_val = num;
}

void	number_true_elements2(t_stack *a)
{
	t_stack	*dop;

	dop = a;
	while (1)
	{
		true_elements2(dop);
		dop = dop->next;
		if (dop == a)
			break ;
	}
}
