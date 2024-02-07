/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:32 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:55:34 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*check_instruction(char *inst)
{
	if (!ft_strcmp(inst, "pa"))
		return (PA);
	if (!ft_strcmp(inst, "pb"))
		return (PB);
	if (!ft_strcmp(inst, "sa"))
		return (SA);
	if (!ft_strcmp(inst, "sb"))
		return (SB);
	if (!ft_strcmp(inst, "ss"))
		return (SS);
	if (!ft_strcmp(inst, "ra"))
		return (RA);
	if (!ft_strcmp(inst, "rb"))
		return (RB);
	if (!ft_strcmp(inst, "rr"))
		return (RR);
	if (!ft_strcmp(inst, "rra"))
		return (RRA);
	if (!ft_strcmp(inst, "rrb"))
		return (RRB);
	if (!ft_strcmp(inst, "rrr"))
		return (RRR);
	exit(error());
}

static void	scan_instructions(t_technical *t)
{
	int		gnl_ret;
	char	*buf;

	gnl_ret = get_next_line(0, &buf);
	while (gnl_ret)
	{
		if (gnl_ret == -1)
			exit(error());
		addinstnode_back(&(t->inst_ch),
			create_inst_node(check_instruction(buf)));
		free(buf);
		gnl_ret = get_next_line(0, &buf);
	}
	free(buf);
}

static void	double_ones(t_stack **a, t_stack **b, t_technical *t, t_inst *tmp)
{
	if (!ft_strcmp(tmp->instruction, RR))
	{
		rotate(a, t, A);
		rotate(b, t, B);
	}
	if (!ft_strcmp(tmp->instruction, RRR))
	{
		r_rotate(a, t, A);
		r_rotate(b, t, B);
	}
	if (!ft_strcmp(tmp->instruction, SS))
	{
		swap(a, t, A);
		swap(b, t, B);
	}
}

static void	do_instructions(t_stack **a, t_stack **b,
							t_technical *t, t_inst *tmp)
{
	while (tmp)
	{
		if (!ft_strcmp(tmp->instruction, PA))
			push(a, b, t, A);
		if (!ft_strcmp(tmp->instruction, PB))
			push(a, b, t, B);
		if (!ft_strcmp(tmp->instruction, SA))
			swap(a, t, A);
		if (!ft_strcmp(tmp->instruction, SB))
			swap(b, t, B);
		if (!ft_strcmp(tmp->instruction, RA))
			rotate(a, t, A);
		if (!ft_strcmp(tmp->instruction, RB))
			rotate(b, t, B);
		if (!ft_strcmp(tmp->instruction, RRA))
			r_rotate(a, t, A);
		if (!ft_strcmp(tmp->instruction, RRB))
			r_rotate(b, t, B);
		double_ones(a, b, t, tmp);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_technical	t;

	init(&a, &b, &t);
	if (argc > 1)
	{
		fill_stack_and_arr(&a, &t, argc, argv);
		heap_sort(t.sorted_arr, t.a_num);
		check_doubles(t.sorted_arr, t.a_num - 1, 0);
		assign_expected_positions(a, &t);
		scan_instructions(&t);
		do_instructions(&a, &b, &t, t.inst_ch);
		if (is_sorted(a, t.sorted_arr) && !b)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	clean(&a, &b, &t);
	return (0);
}	
