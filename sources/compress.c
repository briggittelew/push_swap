/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:42 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:55:43 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	change_two_on_one(t_inst **lst, t_inst **next, char *instruction)
{
	t_inst	*lst_to_free;
	t_inst	*next_to_free;
	t_inst	*tmp;

	if (!(*lst)->prev || !(*next)->next)
		return (0);
	lst_to_free = *lst;
	next_to_free = *next;
	*lst = (*lst)->prev;
	*next = (*next)->next;
	(*lst)->next = create_inst_node(instruction);
	tmp = *lst;
	*lst = (*lst)->next;
	(*next)->prev = *lst;
	(*lst)->next = *next;
	(*lst)->prev = tmp;
	free(lst_to_free);
	free(next_to_free);
	*lst = (*lst)->prev;
	return (1);
}

static int	remove_two(t_inst **lst, t_inst **next)
{
	t_inst	*lst_to_free;
	t_inst	*next_to_free;

	if (!(*lst)->prev || !(*next)->next)
		return (0);
	lst_to_free = *lst;
	next_to_free = *next;
	*lst = (*lst)->prev;
	*next = (*next)->next;
	(*lst)->next = *next;
	(*next)->prev = *lst;
	free(lst_to_free);
	free(next_to_free);
	return (1);
}

static int	compress(t_inst **lst, t_inst **next)
{
	if ((!ft_strcmp((*lst)->instruction, RA)
			&& !ft_strcmp((*next)->instruction, RB))
		|| (!ft_strcmp((*lst)->instruction, RB)
			&& !ft_strcmp((*next)->instruction, RA)))
		return (change_two_on_one(lst, next, RR));
	if ((!ft_strcmp((*lst)->instruction, RRA)
			&& !ft_strcmp((*next)->instruction, RRB))
		|| (!ft_strcmp((*lst)->instruction, RRB)
			&& !ft_strcmp((*next)->instruction, RRA)))
		return (change_two_on_one(lst, next, RRR));
	if ((!ft_strcmp((*lst)->instruction, SA)
			&& !ft_strcmp((*next)->instruction, SB))
		|| (!ft_strcmp((*lst)->instruction, SA)
			&& !ft_strcmp((*next)->instruction, SA)))
		return (change_two_on_one(lst, next, SS));
	if ((!ft_strcmp((*lst)->instruction, PB)
			&& !ft_strcmp((*next)->instruction, PA))
		|| (!ft_strcmp((*lst)->instruction, PA)
			&& !ft_strcmp((*next)->instruction, PB)))
		return (remove_two(lst, next));
	return (0);
}

void	inst_compress(t_inst *lst)
{
	t_inst	*next;
	int		flag;

	while (lst->next)
	{
		next = lst->next;
		flag = compress(&lst, &next);
		if (!flag)
			lst = lst->next;
	}
}
