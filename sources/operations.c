/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:19 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:20 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_instructions(t_technical *t, char *instruction)
{
	addinstnode_back(&(t->inst), create_inst_node(instruction));
}

void	rotate(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A)
		write_instructions(t, RA);
	else if (stack == B)
		write_instructions(t, RB);
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
}

void	r_rotate(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (stack == A)
		write_instructions(t, RRA);
	else if (stack == B)
		write_instructions(t, RRB);
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	head = *a;
	while (tmp->next)
	{
		*a = tmp->next;
		if (!(*a)->next)
		{
			tmp->next = NULL;
			(*a)->next = head;
		}
		else
			tmp = tmp->next;
	}
}

void	push(t_stack **a, t_stack **b, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		t->b_num--;
		t->a_num++;
		write_instructions(t, PA);
	}
	else if (stack == B && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		t->a_num--;
		t->b_num++;
		write_instructions(t, PB);
	}
}

void	swap(t_stack **a, t_technical *t, int stack)
{
	t_stack	*tmp;

	if (stack == A)
		write_instructions(t, SA);
	else if (stack == B)
		write_instructions(t, SB);
	if (t->a_num < 2)
		return ;
	tmp = *a;
	tmp = tmp->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}
