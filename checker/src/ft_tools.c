/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:45:29 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 16:53:55 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_get_value(t_container *c, t_swap *s, int len)
{
	t_swap	*a;
	t_swap	*b;
	int		i;
	int		j;

	j = (len % 2) - 1;
	a = s;
	while (a)
	{
		i = 0;
		c->value_mid = a->nb;
		b = s;
		while (b)
		{
			if (c->value_mid > b->nb)
				i++;
			else if (c->value_mid < b->nb)
				i--;
			b = b->next;
		}
		if (i == j)
			return ;
		a = a->next;
	}
}

int				ft_check_is_sorted(t_container *c, int i)
{
	t_swap	*cur;

	if (!c->a)
		return (0);
	cur = c->a;
	while (cur->next)
	{
		if (cur->nb < cur->next->nb)
			cur = cur->next;
		else
			return (0);
	}
	if (i == 1)
		return (1);
	if (!c->b)
		return (1);
	return (0);
}

void			ft_get_max(t_container *c)
{
	t_swap *a;
	t_swap *b;

	a = c->a;
	c->max_a = c->a->nb;
	while (a)
	{
		if (c->max_a < a->nb)
			c->max_a = a->nb;
		a = a->next;
	}
	b = c->b;
	c->max_b = c->b->nb;
	while (b)
	{
		if (c->max_b < b->nb)
			c->max_b = b->nb;
		b = b->next;
	}
}

int				ft_get_current(t_container *c)
{
	int		cur;
	t_swap	*tmp;

	cur = c->len_a;
	tmp = c->a;
	while (tmp)
	{
		if (tmp->index == cur)
			return (tmp->nb);
		tmp = tmp->next;
	}
	tmp = c->b;
	while (tmp)
	{
		if (tmp->index == cur)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}
