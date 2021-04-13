/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:33:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 12:33:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static int	is_duplicate_number(int nbr, char **split)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (split[++i])
	{
		if (nbr == ft_atoi(split[i]))
			count += 1;
		if (count > 1)
			return (1);
	}
	return (0);
}

static int	is_duplicate_list(int ac, char **av)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (++i < ac)
		if (*av[i] != '-')
			count++;
	if (count > 1)
		return (1);
	return (0);
}

static int	is_valid_options(int ac, char **av)
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

int			is_valid_args(int argc, char **argv)
{
	if (argc < 2 || argc > 5)
		return (0);
	if (!is_valid_options(argc, argv))
		exit_prog(EXIT_FAILURE, "Invalid option", NULL);
	if (!is_valid_digits(argc, argv))
		exit_prog(EXIT_FAILURE, "Invalid digits", NULL);
	return (1);
}
