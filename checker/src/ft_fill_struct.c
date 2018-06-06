/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:45:03 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 18:28:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_nb(char *str, t_container *c)
{
	size_t		len;
	int			i;
	intmax_t	nb;
	t_swap		*tmp;

	tmp = c->a;
	len = ft_strlen(str);
	if (!(i = str[0] == '-' ? 1 : 0))
		i = str[0] == '+' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if ((int)len != i)
		ft_error("Not a number\n");
	nb = ft_atoi_ptf(str);
	if (nb < -2147483648 || nb > 2147483647)
		ft_error("Out of range\n");
	while (tmp)
	{
		if (tmp->nb == (int)nb)
			ft_error("Same number\n");
		tmp = tmp->next;
	}
}

t_swap		*ft_fill_struct(char *str, t_container *c)
{
	t_swap	*new;
	t_swap	*tmp;

	c->len++;
	new = ft_memalloc(sizeof(t_swap));
	new->nb = ft_atoi(str);
	new->next = NULL;
	new->prev = NULL;
	if (!c->a)
		c->a = new;
	else
	{
		tmp = c->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		c->last_a = new;
	}
	return (new);
}

void		ft_free_trou(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);

}

void		ft_destructuration(char *str, t_container *c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (ft_strchr(str, ' '))
	{
		tab = ft_strsplit(str, ' ');
		while (tab[i])
		{
			ft_check_nb(tab[i], c);
			ft_fill_struct(tab[i], c);
			i++;
		}
		ft_free_trou(tab);
	}
	else
	{
		ft_check_nb(str, c);
		ft_fill_struct(str, c);
	}
	while (1)
		;
}
