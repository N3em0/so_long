/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:29:55 by egache            #+#    #+#             */
/*   Updated: 2024/12/18 12:16:36 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int nbr)
{
	int		i;
	char	*str;
	int		count;

	count = 0;
	i = 0;
	str = ft_uitoa(nbr);
	while (str && str[i])
		count += ft_putchar(str[i++]);
	free(str);
	return (count);
}
