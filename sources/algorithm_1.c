/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:03 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:55:06 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_minval_pos(t_stack *a, t_technical *t)
{
	int		pos;

	pos = 1;
	while (a->expected_pos != t->alg_1.next)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

void	algorithm_1(t_stack **a, t_stack **b, t_technical *t)
{
	int		direction;
	t_stack	*next_node;


	t->alg_1.next = 1;
	while (t->alg_1.next <= t->a_num + t->b_num)
	{
		if (find_minval_pos(*a, t) > t->a_num / 2 + 1)
			direction = DOWN;
		else
			direction = UP;
		while ((*a)->expected_pos != t->alg_1.next)
		{
			next_node = (*a)->next;
			if (next_node->expected_pos < (*a)->expected_pos)
				swap(a, t, A);
			if (direction == DOWN && (*a)->expected_pos != t->alg_1.next)
				r_rotate(a, t, A);
			else if (direction == UP && (*a)->expected_pos != t->alg_1.next)
				rotate(a, t, A);
		}
		push(a, b, t, B);
		t->alg_1.next++;
	}
	t->alg_1.next--;
	while (t->alg_1.next)
	{
		push(a, b, t, A);
		t->alg_1.next--;
	}
}