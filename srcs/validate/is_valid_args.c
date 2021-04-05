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

#include "push_swap.h"

static int	is_valid_chars(char *line)
{
	int		i;

	i = (*line == '-' || *line == '+') ? 0 : -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
}

static int	is_duplicate(int nbr, int argc, char **argv)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		if (nbr == ft_atoi(argv[i]))
			count += 1;
		if (count > 1)
			return (1);
	}
	return (0);
}

int			is_valid_args(int argc, char **argv)
{
	int		i;
	int		nbr;

	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!is_valid_chars(argv[i]))
			exit_prog(EXIT_FAILURE);
		nbr = ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			exit_prog(EXIT_FAILURE);
		if (is_duplicate(nbr, argc, argv))
			exit_prog(EXIT_FAILURE);
	}
	return (1);
}
