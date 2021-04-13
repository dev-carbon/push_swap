/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:21:48 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 22:23:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static int	is_valid_list(char **list)
{
	int		i;
	int		j;

	i = -1;
	while (list[++i] != NULL)
	{
		j = -1;
		while (list[i][++j] != '\0')
			if (!ft_isdigit(list[i][j]))
				return (0);
	}
	return (1);
}

static char	**is_duplicate_list(int ac, char **av)
{
	int		i;

	i = 0;
	count = 0;
	while (++i < ac)
	{
		list = ft_split(av[i], 32);
		if (is_valid_list(list))
			count++;
		if (count > 1)
			return (NULL);
	}
	return (list);
}

// static int	is_invalid_digit(char **av)
// {
// 	int		i;
// 	int		nbr;
// 	int		count;
// 	char	*digits;

// 	count = 0;
// 	i = -1;
// 	while (av[++i])
// 	{
// 		digits = ft_split(av[1]);
// 		if (is_valid_list(digits))
// 		{
// 			nbr == ft_atoi(split[i]):
// 			count += 1;
// 		}
// 		if (count > 1)
// 			return (1);
// 	}
// 	return (0);
// }

// static int	is_duplicate_digit(char **av)
// {
// 	int		i;
// 	int		nbr;
// 	int		count;
// 	char	**digits;

// 	count = 0;
// 	i = -1;
// 	while (av[++i])
// 	{
// 		digits = ft_split(av[i], 32);
// 		if (is_valid_list(digits))
// 		{
// 			while ()
// 		if (nbr == ft_atoi(split[i]))
// 			count += 1;
// 		if (count > 1)
// 			return (1);
// 	}
// 	return (0);
// }

int			is_valid_digits(int ac, char **av)
{
	int		i;
	char	*digits;

	if (!(digits = is_duplicate_list(ac, av)))
		exit_prog(EXIT_FAILURE, "Duplicated list.\n", NULL);
	i = 0;
	// while (av[++i] != NULL)
	// {
		
	// }
	
	// digits = 
	// if (is_duplicate_digit(av))
	// 	exit_prog(EXIT_FAILURE, "Duplicated number.\n", NULL);
	// if (is_invalid_digit(av))
	// 	exit_prog(EXIT_FAILURE, "Invalid number.\n", NULL);
	return (1);
}
