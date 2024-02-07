/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:41 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:45 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_utils(t_stack **s, t_technical *t, int stack, int *a)
{
	if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		r_rotate(s, t, stack);
		swap(s, t, stack);
	}
	if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		swap(s, t, stack);
	if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		r_rotate(s, t, stack);
	if (a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		rotate(s, t, stack);
	if (a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		rotate(s, t, stack);
		swap(s, t, stack);
	}
}

void	sort_3(t_stack **s, t_technical *t, int stack)
{
	t_stack	*tmp;
	int		a[3];
	int		i;

	tmp = *s;
	i = 0;
	while (tmp)
	{
		a[i++] = tmp->expected_pos;
		tmp = tmp->next;
	}
	sort_3_utils(s, t, stack, a);
}

static void	sort_4_utils(t_stack **a, t_stack **b, t_technical *t, int pos)
{
	if (pos == 2)
	{
		swap(a, t, A);
		push(a, b, t, B);
		sort_3(a, t, A);
		push(a, b, t, A);
	}
	if (pos == 3)
	{
		rotate(a, t, A);
		rotate(a, t, A);
		push(a, b, t, B);
		sort_3(a, t, A);
		push(a, b, t, A);
	}
	if (pos == 4)
	{
		r_rotate(a, t, A);
		push(a, b, t, B);
		sort_3(a, t, A);
		push(a, b, t, A);
	}
}

void	sort_4(t_stack **a, t_stack **b, t_technical *t, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 1;
	while (tmp->expected_pos != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 1)
	{
		push(a, b, t, B);
		sort_3(a, t, A);
		push(a, b, t, A);
	}
	sort_4_utils(a, b, t, i);
}

void	sort_5(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*tmp;
	int		i;
	int		dir;

	tmp = *a;
	i = 1;
	while (tmp->expected_pos != 1)
	{
		tmp = tmp->next;
		i++;
	}
	dir = DOWN;
	if (i < 4)
		dir = UP;
	while ((*a)->expected_pos != 1)
		if (dir == UP)
			rotate(a, t, A);
	else if (dir == DOWN)
		r_rotate(a, t, A);
	push(a, b, t, B);
	sort_4(a, b, t, 2);
	push(a, b, t, A);
}
