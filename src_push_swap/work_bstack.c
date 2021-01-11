/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_bstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:31:59 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:33:33 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*find_a(t_stack *a, int value)
{
	t_stack	*dop1;
	t_stack	*dop2;

	dop1 = a;
	dop2 = a->next;
	while (1)
	{
		if (value > dop1->value && value < dop2->value)
			return (dop2);
		dop1 = dop1->next;
		dop2 = dop2->next;
		if (dop2 == a->next)
			break ;
	}
	dop1 = min_in_stack(a);
	return (dop1);
}

t_shift		*choose_element(t_data *data)
{
	t_stack	*dop;
	t_stack	*f_a;
	t_shift	*shift;

	if (!(shift = create_shift()))
		return (NULL);
	dop = data->b;
	while (1)
	{
		f_a = find_a(data->a, dop->value);
		calc_rotate(data, f_a, dop, shift);
		dop = dop->next;
		if (dop == data->b)
			break ;
	}
	return (shift);
}

void		work_b_stack(t_data *data)
{
	t_shift	*shift;

	while (data->b != NULL)
	{
		if (!(shift = choose_element(data)))
			do_exit(&data);
		do_rotate(data, shift);
		pb(&data->b, &data->a);
		if (add_command(&data->commands1, "pa"))
			do_exit(&data);
		free(shift);
	}
}
