/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:15:36 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:20:35 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_container *c)
{
	c->check_print = 0;
	ft_swap_a(c);
	ft_swap_b(c);
	write(1, "ss\n", 3);
    c->check_print = 1;
}

void		ft_rotate(t_container *c)
{
	c->check_print = 0;
	ft_rotate_a(c);
	ft_rotate_b(c);
	write(1, "rr\n", 3);
    c->check_print = 1;
}

void		ft_reverse(t_container *c)
{
	c->check_print = 0;
	ft_reverse_rotate_a(c);
	ft_reverse_rotate_b(c);
	write(1, "rrr\n", 4);
    c->check_print = 1;
}
