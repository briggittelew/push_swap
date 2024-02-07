/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:58:09 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:58:11 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **a, t_stack **b, t_technical *t)
{	
	*a = NULL;
	*b = NULL;
	t->as_alg.global_tag = 0;
	t->as_alg.wanted_el = 1;
	t->sorted_arr = NULL;
	t->inst = NULL;
	t->inst_ch = NULL;
}

void	print_instructions(t_inst *inst)
{
	while (inst)
	{
		ft_putstr(inst->instruction);
		inst = inst->next;
	}
}
