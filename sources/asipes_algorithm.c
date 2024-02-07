/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asipes_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:54:39 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:54:41 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	align_a(t_stack **a, t_stack **b, t_technical *t, int k)
{
	int		dir;

	if (k > t->as_alg.wanted_el - 1)
	{
		k = t->as_alg.wanted_el - 1;
		dir = UP;
	}
	else
		dir = DOWN;
	while (k--)
	{
		if (dir == UP)
		{
			rotate(a, t, A);
			if ((*b)->expected_pos != t->as_alg.wanted_el)
				rotate(b, t, B);
		}
		else if (dir == DOWN)
		{
			r_rotate(a, t, A);
			if (*b && (*b)->expected_pos != t->as_alg.wanted_el)
				r_rotate(b, t, B);
		}
	}
}

static void	push_or_rotate(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	if ((*b)->expected_pos == t->as_alg.wanted_el)
	{
		t->as_alg.wanted_el++;
		(*b)->curr_tag = SORTED;
		push(a, b, t, A);
		rotate(a, t, A);
	}
	else if ((*b)->expected_pos <= mid)
		rotate(b, t, B);
	else
	{
		(*b)->curr_tag = t->as_alg.global_tag;
		push(a, b, t, A);
	}
}

static void	split_b(t_stack **a, t_stack **b, t_technical *t, int max)
{
	int		mid;
	int		k;

	while (*b)
	{
		mid = (max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		max = mid;
		t->as_alg.global_tag++;
		k = t->b_num;
		while (k--)
			push_or_rotate(a, b, t, mid);
		if (t->b_num == 3)
			sort_3_b(a, b, t);
		if (t->b_num == 2)
			sort_2_b(a, b, t);
	}
}

static void	move_tagged(t_stack **a, t_stack **b, t_technical *t, int tag)
{
	while ((*a)->curr_tag == tag)
	{
		if ((*a)->expected_pos == t->as_alg.wanted_el)
		{
			(*a)->curr_tag = SORTED;
			rotate(a, t, A);
			t->as_alg.wanted_el++;
		}
		else
			push(a, b, t, B);
	}
}

void	asipes_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		max;
	int		mid;
	int		rotations;

	mid = 0;
	max = t->a_num;
	while (mid < max)
	{
		mid = (max - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
		rotations = split_a(a, b, t, mid);
		align_a(a, b, t, rotations);
		split_b(a, b, t, mid);
		while ((*a)->curr_tag != DEFAULT && (*a)->curr_tag != SORTED)
		{
			move_tagged(a, b, t, (*a)->curr_tag);
			split_b(a, b, t, mid);
		}
	}
}
