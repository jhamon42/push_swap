/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:45:10 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:16:25 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_reverse_rotate_a(t_container *c)
{
	t_swap		*ptr1;

	if (c->a && c->a->next)
	{
		ptr1 = c->last_a;
		c->a->prev = ptr1;
		c->last_a = ptr1->prev;
		c->last_a->next = NULL;
		ptr1->next = c->a;
		c->a->prev = ptr1;
		c->a = ptr1;
		c->a->prev = NULL;
	}
	if (c->check_print)
		write(1, "rra\n", 4);
	else
		c->check_print = 1;
}

void		ft_reverse_rotate_b(t_container *c)
{
	t_swap		*ptr1;

	if (c->b && c->b->next)
	{
		ptr1 = c->last_b;
		c->b->prev = ptr1;
		c->last_b = ptr1->prev;
		c->last_b->next = NULL;
		ptr1->next = c->b;
		c->b->prev = ptr1;
		c->b = ptr1;
		c->b->prev = NULL;
	}
	if (c->check_print)
		write(1, "rrb\n", 4);
	else
		c->check_print = 1;
}

void		ft_rotate_a(t_container *c)
{
	t_swap		*ptr1;

	if (c->a && c->a->next)
	{
		ptr1 = c->a;
		c->a = c->a->next;
		c->a->prev = NULL;
		ptr1->next = NULL;
		c->last_a->next = ptr1;
		ptr1->prev = c->last_a;
		c->last_a = ptr1;
	}
	if (c->check_print)
		write(1, "ra\n", 3);
	else
		c->check_print = 1;
}

void		ft_rotate_b(t_container *c)
{
	t_swap		*ptr1;

	if (c->b && c->b->next)
	{
		ptr1 = c->b;
		c->b = c->b->next;
		c->b->prev = NULL;
		ptr1->next = NULL;
		c->last_b->next = ptr1;
		ptr1->prev = c->last_b;
		c->last_b = ptr1;
	}
	if (c->check_print)
		write(1, "rb\n", 3);
	else
		c->check_print = 1;
}
