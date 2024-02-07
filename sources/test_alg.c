/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:58 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:58:01 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	t_stack	*min_node;
	int		min_val;
	int		i;
	int		pos;

	if (!a)
		return (0);
	i = 1;
	pos = 1;
	min_node = a;
	min_val = min_node->val;
	while (a->next)
	{
		a = a->next;
		i++;
		if (a->val < min_val)
		{
			min_node = a;
			min_val = a->val;
			pos = i;
		}
		
	}
	return (pos);
}

void	up_and_push(t_stack **a, t_stack **b, t_technical *t, int pos)
{
	while (pos-- - 1)
		rotate(a, t, A);
	push(a, b, t, B);
}

void	down_and_push(t_stack **a, t_stack **b, t_technical *t, int pos)
{
	while (pos++ < t->a_num + 1)
		r_rotate(a, t, A);
	push(a, b, t, B);
}

void	alg1(t_stack **a, t_stack **b, t_technical *t)
{
	int		pos; // mb long int in case of a lot args // also mb choose stop amount of args and dance around it
	int		i;

	i = -1;
	while (++i < t->a_num + t->b_num)
	{
		pos = find_min(*a);
		if (pos > (t->a_num / 2 + 1))
			down_and_push(a, b, t, pos);
		else
			up_and_push(a, b, t, pos);
	}
	i = -1;
	while (++i < t->a_num + t->b_num)
		push(a, b, t, A);
}