/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:56:36 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:56:38 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_down(int *arr, int root, int bottom)
{
	int		max_child;
	int		done;
	int		temp;

	done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			max_child = root * 2;
		else if (arr[root * 2] > arr[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		if (arr[root] < arr[max_child])
		{
			temp = arr[root];
			arr[root] = arr[max_child];
			arr[max_child] = temp;
			root = max_child;
		}
		else
			done = 1;
	}
}

void	heap_sort(int *arr, int arr_size)
{
	int		i;
	int		temp;

	i = arr_size / 2;
	while (i >= 0)
	{
		shift_down(arr, i, arr_size - 1);
		i--;
	}
	i = arr_size - 1;
	while (i >= 1)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		shift_down(arr, 0, i - 1);
		i--;
	}
}
