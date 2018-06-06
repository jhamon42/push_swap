/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:50:03 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 17:19:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_list(t_container *c)
{
	t_swap		*a;
	t_swap		*b;

	a = c->a;
	b = c->b;
	ft_printf("%4cstack A   |   stack B\n", ' ', ' ');
	while (a && b)
	{
		ft_printf("|%12d | %-12d|\n", a->nb, b->nb);
		a = a->next;
		b = b->next;
	}
	while (a)
	{
		ft_printf("|%12d | %-12c|\n", a->nb, ' ');
		a = a->next;
	}
	while (b)
	{
		ft_printf("|%12c | %-12d|\n", ' ', b->nb);
		b = b->next;
	}
}

void		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void		ft_init_container(t_container *c)
{
	ft_bzero(c, sizeof(t_container));
	c->check_print = 1;
}

int			main(int ac, char **av)
{
	char			*str;
	t_container		container;
	t_container		*c;
	int				i;

	i = 1;
	c = &container;
	ft_init_container(c);
	str = NULL;
	if (ac < 2)
		ft_error("Pas assez d'aguments");
	while (i < ac)
		ft_destructuration(av[i++], c);
	i = 0;
	while (get_next_line(0, &str) > 0)
	{
		ft_apply_op(str, c);
		ft_strdel(&str);
	}
	if (ft_check_is_sorted(c, 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("nb de coups = %d\n", i);
	return (0);
}
