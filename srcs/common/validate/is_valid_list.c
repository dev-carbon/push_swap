/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:21:48 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/14 02:28:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static int	is_valid_list_chars(char **list)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		while (list[i][++j] != '\0')
		{
			c = list[i][j];
			if (j == 0 && (c == '-' || c == '+'))
				j++;
			if (!ft_isdigit(list[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	is_valid_options(char **split)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	while (split[++i])
	{
		if (*split[i] == '-')
		{
			j = 0;
			while (*(split[i] + (++j)) != '\0')
			{
				str = ft_strchr("vic", *(split[i] + j));
				if (!str)
					return (0);
				if (ft_strchr(str + 1, *(split[i] + j)))
					return (0);
			}
		}
	}
	return (1);
}

static char	**is_duplicate_list(int ac, char **av)
{
	int		i;
	int		count;
	char	**list;
	char	**digits;

	i = 0;
	count = 0;
	digits = NULL;
	while (++i < ac)
	{
		list = ft_split(av[i], 32);
		digits = ft_split(av[i], 32);
		if (is_valid_list_chars(list))
			count++;
		else if (!is_valid_options(list))
		{
			destroy_split(digits);
			destroy_split(list);
			exit_prog(EXIT_FAILURE, "Invalid list character.\n", NULL);
		}
		if (count > 1)
			destroy_split(digits);
		destroy_split(list);
	}
	return (digits);
}

void	check_duplicated_integer(char **list, int nbr, int start)
{
	while (list[++start] != NULL)
	{
		if (nbr == ft_atoi(list[start]))
		{
			destroy_split(list);
			exit_prog(EXIT_FAILURE, "Duplicated integer.\n", NULL);
		}
	}
}

int	is_valid_list(int ac, char **av)
{
	int		i;
	int		nbr;
	char	**digits;

	digits = is_duplicate_list(ac, av);
	if (!digits)
		exit_prog(EXIT_FAILURE, "Duplicated list.\n", NULL);
	i = -1;
	while (digits[++i])
	{
		nbr = ft_atoi(digits[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			destroy_split(digits);
			exit_prog(EXIT_FAILURE, "Invalid integer.\n", NULL);
		}
		check_duplicated_integer(digits, nbr, i);
	}
	destroy_split(digits);
	return (1);
}
