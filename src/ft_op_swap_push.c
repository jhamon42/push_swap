/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:45:18 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:22:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap_a(t_container *c)
{
	t_swap		*ptr1;
	t_swap		*ptr2;

	ptr1 = NULL;
	if (c->a && c->a->next)
	{
		if (c->a->next->next)
		{
			ptr1 = c->a->next->next;
			ptr1->prev = c->a;
		}
		ptr2 = c->a->next;
		c->a->prev = ptr2;
		ptr2->prev = NULL;
		ptr2->next = c->a;
		c->a->next = ptr1;
		c->a = ptr2;
		if (!c->a->next->next)
			c->last_a = c->a->next;
	}
	if (c->check_print)
		write(1, "sa\n", 3);
}

void		ft_swap_b(t_container *c)
{
	t_swap		*ptr1;
	t_swap		*ptr2;

	ptr1 = NULL;
	if (c->b && c->b->next)
	{
		if (c->b->next->next)
		{
			ptr1 = c->b->next->next;
			ptr1->prev = c->b;
		}
		ptr2 = c->b->next;
		c->b->prev = ptr2;
		ptr2->prev = NULL;
		ptr2->next = c->b;
		c->b->next = ptr1;
		c->b = ptr2;
		if (!c->b->next->next)
			c->last_b = c->b->next;
	}
	if (c->check_print)
		write(1, "sb\n", 3);
}

void		ft_push_a(t_container *c)
{
	t_swap*ptr1;

	if (!c->b)
		return ;
	ptr1 = c->b;
	c->b = c->b->next;
	if (!c->a)
	{
		c->a = ptr1;
		c->a->next = NULL;
		c->a->prev = NULL;
		c->last_a = ptr1;
	}
	else
	{
		c->a->prev = ptr1;
		ptr1->next = c->a;
		c->a = ptr1;
	}
	if (!c->b)
		c->last_b = NULL;
	c->len_a++;
	c->len_b--;
	write(1, "pa\n", 3);
}

void		ft_push_b(t_container *c)
{
	t_swap		*ptr1;

	if (!c->a)
		return ;
	ptr1 = c->a;
	c->a = c->a->next;
	if (!c->b)
	{
		c->b = ptr1;
		c->b->next = NULL;
		c->b->prev = NULL;
		c->last_b = ptr1;
	}
	else
	{
		c->b->prev = ptr1;
		ptr1->next = c->b;
		c->b = ptr1;
	}
	if (!c->a)
		c->last_a = NULL;
	c->len_a--;
	c->len_b++;
	write(1, "pb\n", 3);
}
