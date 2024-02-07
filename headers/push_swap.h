/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:50:03 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:50:13 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 1
# define B 0
# define UP 1
# define DOWN 0
# define DEFAULT -1
# define SORTED -2

# define SA "sa\n"
# define SB	"sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# include "../libft/headers/libft.h"

typedef struct s_stack
{
	int				val;
	int				expected_pos;
	int				curr_tag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_as_alg
{
	int				wanted_el;
	int				global_tag;
}					t_as_alg;

typedef struct s_inst
{
	char			*instruction;
	struct s_inst	*next;
	struct s_inst	*prev;
}					t_inst;

typedef struct s_split
{
	int				below_mid;
	int				rotations;
	int				next_mid;
}					t_split;

typedef struct s_technical
{
	int				a_num;
	int				b_num;
	int				*sorted_arr;
	struct s_as_alg	as_alg;
	struct s_inst	*inst;
	struct s_inst	*inst_ch;
	struct s_split	split;
}					t_technical;

t_stack	*create_node(int val);
void	addnode_back(t_stack **lst, t_stack *new);
t_inst	*create_inst_node(char *val);
void	addinstnode_back(t_inst **lst, t_inst *new);
int		error(void);
int		check_argv(char *str);
void	check_doubles(int *arr, int size, int sorted);
int		is_sorted(t_stack *a, int *arr);
void	swap(t_stack **a, t_technical *t, int stack);
void	push(t_stack **a, t_stack **b, t_technical *t, int stack);
void	rotate(t_stack **a, t_technical *t, int stack);
void	r_rotate(t_stack **a, t_technical *t, int stack);
void	radix_algorithm(t_stack **a, t_stack **b, t_technical *t);
void	asipes_algorithm(t_stack **a, t_stack **b, t_technical *t);
void	sort_3_b(t_stack **a, t_stack **b, t_technical *t);
void	sort_2_b(t_stack **a, t_stack **b, t_technical *t);
void	sort_3(t_stack **s, t_technical *t, int stack);
void	sort_4(t_stack **a, t_stack **b, t_technical *t, int num);
void	sort_5(t_stack **a, t_stack **b, t_technical *t);
void	inst_compress(t_inst *lst);
void	print_instructions(t_inst *inst);
void	clean(t_stack **a, t_stack **b, t_technical *t);
void	heap_sort(int *arr, int arr_size);
void	fill_stack_and_arr(t_stack **a, t_technical *t, int argc, char **argv);
void	init(t_stack **a, t_stack **b, t_technical *t);
void	assign_expected_positions(t_stack *a, t_technical *t);
int		split_a(t_stack **a, t_stack **b, t_technical *t, int mid);

#endif