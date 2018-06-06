/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:50:11 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 16:23:57 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_container		container;
	t_container		*c;
	int				i;

	i = 1;
	c = &container;
	ft_bzero((void*)c, sizeof(container));
	c->check_print = 1;
	if (ac < 2)
		ft_error("pas assez d'argument");
	while (i < ac)
		ft_destructuration(av[i++], c);
	c->len_a = c->len;
	if (c->a)
		ft_sort(c);
	return (0);
}
