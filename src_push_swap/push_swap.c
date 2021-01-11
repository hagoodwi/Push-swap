/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:21:10 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 21:23:13 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_data *data)
{
	t_commands	*com;

	if (data->commands1 == NULL)
		return ;
	if (len_commands(data->commands1) > len_commands(data->commands2))
		com = data->commands2;
	else
		com = data->commands1;
	while (com != NULL)
	{
		ft_putstr(com->command);
		ft_putstr("\n");
		com = com->next;
	}
}

void	algoritm(t_data *data)
{
	data->a = data->a1;
	indexation(data->a);
	work_a_stack1(data);
	work_b_stack(data);
	revision_a(&data->a, &data->commands1);
	data->a1 = data->a;
	data->commands2 = data->commands1;
	data->commands1 = NULL;
	data->a = data->a2;
	indexation(data->a);
	work_a_stack2(data);
	work_b_stack(data);
	revision_a(&data->a, &data->commands1);
	data->a2 = data->a;
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (0);
	data = initialization(ac, av);
	if (!data->a1 && !data->a2)
	{
		data_free(&data);
		return (0);
	}
	algoritm(data);
	display(data);
	data_free(&data);
	return (0);
}
