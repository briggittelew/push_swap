/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:56:28 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:56:30 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_and_arr(t_stack **a, t_technical *t, int argc, char **argv)
{
	int		i;
	int		checked_val;

	i = 1;
	t->sorted_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!t->sorted_arr)
		exit(error());
	*a = create_node(check_argv(argv[i]));
	t->sorted_arr[i - 1] = check_argv(argv[i]);
	while (++i < argc)
	{
		checked_val = check_argv(argv[i]);
		addnode_back(a, create_node(checked_val));
		t->sorted_arr[i - 1] = checked_val;
	}
	t->a_num = i - 1;
	t->b_num = 0;
}

void	assign_expected_positions(t_stack *a, t_technical *t)
{
	int		i;

	while (a)
	{
		i = 0;
		while ((a)->val != t->sorted_arr[i])
			i++;
		(a)->expected_pos = i + 1;
		a = (a)->next;
	}
}
