/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:49 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:55:53 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_utils(t_technical *t)
{
	t_inst	*to_free;

	while (t->inst)
	{
		to_free = t->inst;
		t->inst = t->inst->next;
		free(to_free);
	}
	while (t->inst_ch)
	{
		to_free = t->inst_ch;
		t->inst_ch = t->inst_ch->next;
		free(to_free);
	}
}

void	clean(t_stack **a, t_stack **b, t_technical *t)
{
	t_stack	*to_free;

	if (t->sorted_arr)
		free(t->sorted_arr);
	while (*a)
	{
		to_free = *a;
		*a = (*a)->next;
		free(to_free);
	}
	while (*b)
	{
		to_free = *b;
		*b = (*b)->next;
		free(to_free);
	}
	clean_utils(t);
}

int	error(void)
{
	ft_putstr("Error\n");
	return (-1);
}
