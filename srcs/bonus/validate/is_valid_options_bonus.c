/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:06:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 23:07:07 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_bonus.h"

int	is_valid_options(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] == '-')
		{
			j = 0;
			while (*(av[i] + (++j)) != '\0')
			{
				if (!(str = ft_strchr("vic", *(av[i] + j))))
					return (0);
				if (ft_strchr(str + 1, *(av[i] + j)))
					return (0);
			}
		}
	}
	return (1);
}
