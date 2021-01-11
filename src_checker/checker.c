/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:05:55 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:08:48 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		**str;
	t_commands	*commands;

	av++;
	str = av;
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		str = ft_strsplit(av[0], ' ');
	if (init(&a, str) || reader(&commands))
	{
		if (ac == 2)
			ft_arfree(&str);
		do_exit(&a, &b, &commands);
	}
	if (a != NULL)
		checker_commands(&a, &b, commands);
	clear(&a, &b, &commands);
	if (ac == 2)
		ft_arfree(&str);
	return (0);
}
