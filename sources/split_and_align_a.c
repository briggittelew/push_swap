/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_align_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:51 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:53 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	found(t_stack **a, t_technical *t)
{
	t->as_alg.wanted_el++;
	(*a)->curr_tag = SORTED;
	rotate(a, t, A);
}

static void	less_then_mid(t_stack **a, t_stack **b,
						t_technical *t, int *below_mid)
{
	(*below_mid)--;
	push(a, b, t, B);
}

static void	split_init(int *rotated, int k, int *below_mid, int *rotations)
{
	*rotated = 0;
	*below_mid = (k + 1) / 2;
	*rotations = 0;
}

int	split_a(t_stack **a, t_stack **b, t_technical *t, int mid)
{
	int		rotations;
	int		k;
	int		rotated;
	int		next_mid;
	int		below_mid;

	k = (t->a_num + t->b_num) - t->as_alg.wanted_el + 1;
	split_init(&rotated, k, &below_mid, &rotations);
	while (k-- && below_mid)
	{
		if (((*a)->expected_pos == t->as_alg.wanted_el) && !rotated)
			found(a, t);
		else if ((*a)->expected_pos > mid)
		{
			next_mid = (mid - t->as_alg.wanted_el) / 2 + t->as_alg.wanted_el;
			rotated = ++rotations;
			rotate(a, t, A);
			if (*b && (*b)->expected_pos < next_mid
				&& (*b)->expected_pos != t->as_alg.wanted_el)
				rotate(b, t, B);
		}
		else
			less_then_mid(a, b, t, &below_mid);
	}
	return (rotations);
}
