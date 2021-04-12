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

static int	is_valid_options(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (++i < ac && *av[i] == '-')
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
	return (1);
}

int			is_valid_args(int argc, char **argv)
{
	int		i;
	int		nbr;
	int		split_len;
	char	**split;

	if (argc < 2 || argc > 5)
		return (0);
	if (!is_valid_options(argc, argv))
		exit_prog(EXIT_FAILURE, NULL);
	i = 0;
	while (++i < argc && *(argv[i]) == '-')
		;
	split = ft_split(argv[i], ' ');
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
