/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:03:20 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 15:15:58 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHEU printf("%50%check\n");
# define CH(X) printf("%50c-- check %d --\n", ' ', X);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_swap
{
	int				nb;
	int				index;
	struct s_swap	*next;
	struct s_swap	*prev;
}				t_swap;

typedef struct s_value
{
	int				stock_value;
	struct s_value	*next;
	struct s_value	*first;
}				t_value;

typedef struct	s_container
{
	struct s_swap	*a;
	struct s_swap	*b;
	struct s_swap	*last_a;
	struct s_swap	*last_b;
	struct s_value	*stock_value;;
	int				len;
	int				len_mod;
	int				len_a;
	int				len_b;
	int				max_a;
	int				max_b;
	int				value_mid;
	int				check_print;
	int				i;
	struct s_swap	*cur;
}				t_container;

void			ft_destructuration(char *str, t_container *c);
void			ft_error(char *str);
void			ft_check_nb(char *str, t_container *c);
t_swap			*ft_fill_struct(char *str, t_container *c);
void			ft_sort(t_container *c);
void			ft_get_value(t_container *c, t_swap *s, int len);
void			ft_print_list(t_container *c);
int				ft_check_is_sorted(t_container *c, int i);
void			ft_init_container(t_container *c);
void			ft_apply_op(char *str, t_container *c);

void			ft_reverse_rotate_a(t_container *c);
void			ft_reverse_rotate_b(t_container *c);
void			ft_reverse(t_container *c);
void			ft_rotate_a(t_container *c);
void			ft_rotate_b(t_container *c);
void			ft_rotate(t_container *c);
void			ft_push_a(t_container *c);
void			ft_push_b(t_container *c);
void			ft_swap_a(t_container *c);
void			ft_swap_b(t_container *c);
void			ft_swap(t_container *c);

#endif
