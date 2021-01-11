/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:15:49 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:19:20 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	true_elements1(t_stack *a)
{
	t_stack		*dop;
	int			num;
	int			prev_index;

	num = 1;
	dop = a->next;
	prev_index = a->index;
	while (1)
	{
		if (dop->index - prev_index == 1)
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

void	number_true_elements1(t_stack *a)
{
	t_stack	*dop;

	dop = a;
	while (1)
	{
		true_elements1(dop);
		dop = dop->next;
		if (dop == a)
			break ;
	}
}

void	do_markup(t_stack *a)
{
	t_stack	*dop;
	int		prev_index;

	dop = a->next;
	a->correct_pos = true;
	prev_index = a->index;
	while (1)
	{
		if (dop->index - prev_index == 1)
		{
			dop->correct_pos = true;
			prev_index = dop->index;
		}
		else
		{
			if (a->next != a)
				dop->correct_pos = false;
		}
		dop = dop->next;
		if (dop == a)
			return ;
	}
}

t_stack	*markup(t_stack *a)
{
	t_stack		*dop;
	int			max;
	t_stack		*head;
	int			index;

	index = 1000000;
	dop = a;
	max = 0;
	while (1)
	{
		if ((dop->head_val > max) ||
		(dop->head_val == max && dop->index < index))
		{
			index = dop->index;
			head = dop;
			max = dop->head_val;
		}
		dop = dop->next;
		if (dop == a)
			break ;
	}
	do_markup(head);
	return (head);
}
