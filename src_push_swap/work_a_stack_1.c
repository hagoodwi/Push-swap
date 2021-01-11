/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_a_stack_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:27:40 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:29:23 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_false(t_stack *a)
{
	t_stack	*dop;

	dop = a;
	while (1)
	{
		if (!dop->correct_pos)
			return (1);
		dop = dop->next;
		if (dop == a)
			break ;
	}
	return (0);
}

int		sa_is_need(t_stack *a, t_stack *head)
{
	int		not_sa;
	int		sa;

	not_sa = head->head_val;
	sa_sb(&a);
	number_true_elements1(head);
	sa = head->head_val;
	sa_sb(&a);
	true_elements1(head);
	if (sa > not_sa)
		return (1);
	return (0);
}

void	work_a_stack1(t_data *data)
{
	t_stack	*head;

	number_true_elements1(data->a);
	head = markup(data->a);
	while (is_false(data->a))
	{
		if (sa_is_need(data->a, head))
		{
			sa_sb(&data->a);
			do_markup(head);
			add_command(&data->commands1, "sa");
		}
		else if (data->a->correct_pos == false)
		{
			pb(&data->a, &data->b);
			add_command(&data->commands1, "pb");
		}
		else
		{
			ra(&data->a);
			add_command(&data->commands1, "ra");
		}
	}
}
