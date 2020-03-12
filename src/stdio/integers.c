/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:51:56 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:51:58 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/integers.h"
#include "libft.h"

#include <stdlib.h>

int		get_number(char **str)
{
	int		nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr *= 10;
		nbr += (**str - 48);
		if (nbr < 0)
			return (0);
		(*str)++;
	}
	return (nbr);
}

char	*nbr_grouping(t_string *conv, char sep, unsigned int size)
{
	char	*new;
	size_t	i;
	size_t	j;
	int		nsep;

	i = 0;
	while (conv->str[i] != '.' && conv->str[i] != '\0')
		++i;
	nsep = ((i / (float)size) > (i / size)) ? i / size : i / size - 1;
	if ((new = ft_strnew(conv->len + nsep)) == NULL)
		return (NULL);
	ft_strcpy(new + i + nsep, conv->str + i);
	j = 0;
	while (--i > 0)
	{
		new[i + nsep] = conv->str[i];
		if (++j == size)
		{
			j = 0;
			new[i + --nsep] = sep;
		}
	}
	new[i] = conv->str[i];
	return (new);
}
