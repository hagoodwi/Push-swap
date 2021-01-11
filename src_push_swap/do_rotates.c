/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:53:03 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:37:05 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_r_r_rotate(t_data *data, t_shift *shift)
{
	int	ind;
	int	ob;

	ind = max(shift->a_kol, shift->b_kol) - min(shift->a_kol, shift->b_kol);
	ob = min(shift->a_kol, shift->b_kol);
	while (ob--)
	{
		rr(&data->a, &data->b);
		add_command(&data->commands1, "rr");
	}
	if (shift->a_kol > shift->b_kol)
		while (ind--)
		{
			ra(&data->a);
			add_command(&data->commands1, "ra");
		}
	else
		while (ind--)
		{
			ra(&data->b);
			add_command(&data->commands1, "rb");
		}
}

void	do_r_rr_rotate(t_data *data, t_shift *shift)
{
	while ((shift->a_kol)--)
	{
		ra(&data->a);
		add_command(&data->commands1, "ra");
	}
	while ((shift->b_kol)--)
	{
		rra(&data->b);
		add_command(&data->commands1, "rrb");
	}
}

void	do_rr_rr_rotate(t_data *data, t_shift *shift)
{
	int	ind;
	int	ob;

	ind = max(shift->a_kol, shift->b_kol) - min(shift->a_kol, shift->b_kol);
	ob = min(shift->a_kol, shift->b_kol);
	while (ob--)
	{
		rrr(&data->a, &data->b);
		add_command(&data->commands1, "rrr");
	}
	if (shift->a_kol > shift->b_kol)
		while (ind--)
		{
			rra(&data->a);
			add_command(&data->commands1, "rra");
		}
	else
		while (ind--)
		{
			rra(&data->b);
			add_command(&data->commands1, "rrb");
		}
}

void	do_rr_r_rotate(t_data *data, t_shift *shift)
{
	while ((shift->a_kol)--)
	{
		rra(&data->a);
		add_command(&data->commands1, "rra");
	}
	while ((shift->b_kol)--)
	{
		ra(&data->b);
		add_command(&data->commands1, "rb");
	}
}

void	do_rotate(t_data *data, t_shift *shift)
{
	if (shift->a_dir == R && shift->b_dir == R)
		do_r_r_rotate(data, shift);
	if (shift->a_dir == R && shift->b_dir == RR)
		do_r_rr_rotate(data, shift);
	if (shift->a_dir == RR && shift->b_dir == RR)
		do_rr_rr_rotate(data, shift);
	if (shift->a_dir == RR && shift->b_dir == R)
		do_rr_r_rotate(data, shift);
}
