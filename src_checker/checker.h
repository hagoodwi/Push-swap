/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:08:17 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:07:54 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_CHECKER_H
# define PUSH_SWAP_CHECKER_CHECKER_H
# include "libft.h"

typedef struct			s_stack
{
	int					value;
	struct s_stack		*next;
}						t_stack;
typedef struct			s_commands
{
	char				*command;
	struct s_commands	*next;
}						t_commands;
int						init(t_stack **a, char **av);
int						reader(t_commands **commands);
void					checker_commands(t_stack **a,
	t_stack **b, t_commands *commands);
int						len_stack(t_stack *a);
void					sa_sb(t_stack **a);
void					ss(t_stack **a, t_stack **b);
void					rra(t_stack **a);
void					rrr(t_stack **a, t_stack **b);
void					pb(t_stack **a, t_stack **b);
void					ra(t_stack **a);
void					rr(t_stack **a, t_stack **b);
void					do_exit(t_stack **a, t_stack **b,
	t_commands **commands);
void					stack_free(t_stack **a);
void					commands_free(t_commands **commands);
void					clear(t_stack **a, t_stack **b, t_commands **commands);
#endif
