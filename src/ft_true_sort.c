/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:49:54 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:23:46 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stock_value(t_container *c, int value)
{
	t_value *new;

	new = ft_memalloc(sizeof(t_value));
	new->stock_value = value;
	if (c->stock_value)
	{
		new->next = c->stock_value;
		c->stock_value = new;
	}
	else
	{
		new->next = NULL;
		new->first = new;
		c->stock_value = new;
	}
}

int			ft_check_min(t_swap *s)
{
	t_swap	*a;
	int		iter;
	int		min;
	int		i;

	i = 0;
	iter = 0;
	a = s;
	min = a->nb;
	while (a)
	{
		if (min > a->nb)
		{
			min = a->nb;
			iter = i;
		}
		a = a->next;
		i++;
	}
	return (iter + 1);
}

void		ft_sort(t_container *c)
{
	int i;

	while (ft_check_is_sorted(c, 1) == 0)
	{
		i = ft_check_min(c->a);
		if (i == 1)
			c->len_a <= 3 ? ft_reverse_rotate_a(c) : ft_push_b(c);
		else if (i == c->len_a)
			ft_reverse_rotate_a(c);
		else if (i == 2)
			ft_swap_a(c);
		else if (i > c->len_a / 2)
			ft_reverse_rotate_a(c);
		else
			ft_rotate_a(c);
	}
	while (c->len_b)
		ft_push_a(c);
}
