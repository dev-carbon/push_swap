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

	if ((*line == '-' || *line == '+') && ft_strlen(line) == 1)
		return (0);
	i = (*line == '-' || *line == '+') ? 0 : -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
}

static int	is_duplicate(int nbr, char **split)
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

int			is_valid_args(int argc, char **argv)
{
	int		i;
	int		nbr;
	int		split_len;
	char	**split;

	if (argc < 2 || argc > 2)
		return (0);
	i = -1;
	split = ft_split(argv[1], ' ');
	split_len = ft_split_len(split);
	while (split[++i])
	{
		if (!is_valid_chars(split[i]))
			exit_prog(EXIT_FAILURE, NULL);
		nbr = ft_atoi(split[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			exit_prog(EXIT_FAILURE, NULL);
		if (is_duplicate(nbr, split))
			exit_prog(EXIT_FAILURE, NULL);
	}
	return (1);
}
