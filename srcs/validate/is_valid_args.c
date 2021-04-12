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
	int		status;
	int		nbr;
	char	**split;

	if (argc != 2)
		return (0);
	split = ft_split(argv[1], ' ');
	status = 1;
	i = -1;
	while (split[++i])
	{
		if (!is_valid_chars(split[i]))
			status = 0;
		nbr = ft_atoi(split[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || is_duplicate(nbr, split))
			status = 0;
	}
	destroy_split(split);
	if (!status)
		exit_prog(EXIT_FAILURE, NULL);
	return (1);
}
