/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:14:56 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/06 20:46:04 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef enum			e_direction
{
	R,
	RR
}						t_direction;

typedef struct			s_stack
{
	bool				correct_pos;
	int					value;
	int					head_val;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_commands
{
	char				*command;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_data
{

	t_stack				*a;
	t_stack				*a1;
	t_stack				*a2;
	t_stack				*b;
	t_commands			*commands1;
	t_commands			*commands2;
}						t_data;

typedef struct			s_shift
{
	t_stack				*a_elem;
	t_stack				*b_elem;
	t_direction			a_dir;
	t_direction			b_dir;
	int					a_kol;
	int					b_kol;
	bool				is_set;
}						t_shift;

t_data					*initialization(int ac, char **av);
void					indexation(t_stack *a);
void					work_a_stack1(t_data *data);
void					work_a_stack2(t_data *data);
void					true_elements1(t_stack *a);
void					true_elements2(t_stack *a);
void					number_true_elements1(t_stack *a);
void					number_true_elements2(t_stack *a);
t_stack					*markup(t_stack *a);
void					do_markup(t_stack *a);
int						is_false(t_stack *a);
int						sa_is_need(t_stack *a, t_stack *head);
int						add_command(t_commands **commands, char *str);
int						len_stack(t_stack *a);
void					work_b_stack(t_data *data);
void					calc_rotate(t_data *data,
	t_stack *f_a, t_stack *f_b, t_shift *shift);
void					do_rotate(t_data *data, t_shift *shift);
void					revision_a(t_stack **a, t_commands **commands);
void					do_exit(t_data **data);
void					data_free(t_data **data);
int						len_commands(t_commands *commands);
int						check(char **args);
int						check_duplicate(t_stack *a, int value);
void					sa_sb(t_stack **a);
void					pb(t_stack **a, t_stack **b);
void					ra(t_stack **a);
t_stack					*find_a(t_stack *a, int value);
int						r_rotate(t_stack *head, t_stack *elem);
int						rr_rotate(t_stack *head, t_stack *elem);
t_shift					*create_shift();
void					rr(t_stack **a, t_stack **b);
void					rra(t_stack **a);
void					rrr(t_stack **a, t_stack **b);
t_stack					*min_in_stack(t_stack *a);
t_shift					*create_shift();
int						max(int a, int b);
int						min(int a, int b);
int						mod(int a);
#endif
