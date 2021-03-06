/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:24:35 by jhamon            #+#    #+#             */
/*   Updated: 2018/06/06 17:30:56 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_tab(void **ap[])
{
    int i;

    i = 0;
    if (ap)
    {
        while (ap[i])
    	{
	    	free(*ap[i]);
	    	*ap[i++] = NULL;
    	}
        free(*ap);
        *ap = NULL;
    }
}