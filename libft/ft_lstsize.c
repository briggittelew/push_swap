/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:27:15 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 12:27:18 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*tmp;

	if (!lst)
		return (0);
	n = 1;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}
