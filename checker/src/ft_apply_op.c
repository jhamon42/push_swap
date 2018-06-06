/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:44:54 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:13:04 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_apply_op(char *str, t_container *c)
{
	if (ft_strequ(str, "pa"))
		ft_push_a(c);
	else if (ft_strequ(str, "pb"))
		ft_push_b(c);
	else if (ft_strequ(str, "sa"))
		ft_swap_a(c);
	else if (ft_strequ(str, "sb"))
		ft_swap_b(c);
	else if (ft_strequ(str, "ss"))
		ft_swap(c);
	else if (ft_strequ(str, "ra"))
		ft_rotate_a(c);
	else if (ft_strequ(str, "rb"))
		ft_rotate_b(c);
	else if (ft_strequ(str, "rr"))
		ft_rotate(c);
	else if (ft_strequ(str, "rra"))
		ft_reverse_rotate_a(c);
	else if (ft_strequ(str, "rrb"))
		ft_reverse_rotate_b(c);
	else if (ft_strequ(str, "rrr"))
		ft_reverse(c);
	else
		ft_error("Cmd unknow\n");
}
