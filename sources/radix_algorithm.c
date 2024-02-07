/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:26 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:27 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digits(int max_number) //carfull with max_num == 0 or -1 or 1
{
	int	res;

	if (!max_number)
		return (0);
	res = 0;
	while (max_number)
	{
		max_number /= 2;
		res++;
	}
	return (res);
}

static void	push_or_rotate(t_stack **a, t_stack **b, t_technical *t, int i)
{
	int		j;

	j = -1;
	while (++j < t->a_num + t->b_num)
	{
		if (((*a)->expected_pos >> i)&1)
			rotate(a, t, A);
		else
			push(a, b, t, B);
	}
}

void	radix_algorithm(t_stack **a, t_stack **b, t_technical *t)
{
	int		amount_of_digits;
	int		i;

	amount_of_digits = count_digits(t->a_num);
	i = -1;
	while (++i < amount_of_digits)
	{
		push_or_rotate(a, b, t, i);
		while (*b)
			push(a, b, t, A);
	}
}