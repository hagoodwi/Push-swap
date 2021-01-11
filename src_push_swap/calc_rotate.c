/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:47:03 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:52:07 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_r_rotate(t_data *data, t_stack *f_a, t_stack *f_b, t_shift *shift)
{
	int		a_rot;
	int		b_rot;

	a_rot = rr_rotate(data->a, f_a);
	b_rot = r_rotate(data->b, f_b);
	if ((a_rot + b_rot) < (shift->a_kol + shift->b_kol) || !shift->is_set)
	{
		shift->is_set = true;
		shift->a_kol = a_rot;
		shift->b_kol = b_rot;
		shift->a_dir = RR;
		shift->b_dir = R;
		shift->a_elem = f_a;
		shift->b_elem = f_b;
	}
}

void	r_rr_rotate(t_data *data, t_stack *f_a, t_stack *f_b, t_shift *shift)
{
	int		a_rot;
	int		b_rot;

	a_rot = r_rotate(data->a, f_a);
	b_rot = rr_rotate(data->b, f_b);
	if ((a_rot + b_rot) < (shift->a_kol + shift->b_kol) || !shift->is_set)
	{
		shift->is_set = true;
		shift->a_kol = a_rot;
		shift->b_kol = b_rot;
		shift->a_dir = R;
		shift->b_dir = RR;
		shift->a_elem = f_a;
		shift->b_elem = f_b;
	}
}

void	rr_rr_rotate(t_data *data, t_stack *f_a, t_stack *f_b, t_shift *shift)
{
	int		a_rot;
	int		b_rot;

	a_rot = rr_rotate(data->a, f_a);
	b_rot = rr_rotate(data->b, f_b);
	if (max(a_rot, b_rot) < (shift->a_kol + shift->b_kol) || !shift->is_set)
	{
		shift->is_set = true;
		shift->a_kol = a_rot;
		shift->b_kol = b_rot;
		shift->a_dir = RR;
		shift->b_dir = RR;
		shift->a_elem = f_a;
		shift->b_elem = f_b;
	}
}

void	r_r_rotate(t_data *data, t_stack *f_a, t_stack *f_b, t_shift *shift)
{
	int		a_rot;
	int		b_rot;

	a_rot = r_rotate(data->a, f_a);
	b_rot = r_rotate(data->b, f_b);
	if (max(a_rot, b_rot) < (shift->a_kol + shift->b_kol) || !shift->is_set)
	{
		shift->is_set = true;
		shift->a_kol = a_rot;
		shift->b_kol = b_rot;
		shift->a_dir = R;
		shift->b_dir = R;
		shift->a_elem = f_a;
		shift->b_elem = f_b;
	}
}

void	calc_rotate(t_data *data, t_stack *f_a, t_stack *f_b, t_shift *shift)
{
	r_r_rotate(data, f_a, f_b, shift);
	rr_r_rotate(data, f_a, f_b, shift);
	r_rr_rotate(data, f_a, f_b, shift);
	rr_rr_rotate(data, f_a, f_b, shift);
}
