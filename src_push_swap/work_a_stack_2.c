/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_a_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:29:42 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:31:44 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revision_a(t_stack **a, t_commands **commands)
{
	t_stack	*min;
	int		r;
	int		rr;

	min = min_in_stack(*a);
	r = r_rotate(*a, min);
	rr = rr_rotate(*a, min);
	if (r < rr)
		while (r--)
		{
			ra(a);
			add_command(commands, "ra");
		}
	else
		while (rr--)
		{
			rra(a);
			add_command(commands, "rra");
		}
}

void	work_a_stack2(t_data *data)
{
	t_stack	*head;

	number_true_elements2(data->a);
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
