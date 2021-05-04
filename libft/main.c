/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:22 by humanfou          #+#    #+#             */
/*   Updated: 2021/05/04 14:27:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	int	nbr;

	if (ac > 1)
	{
		nbr = ft_atoi(av[1]);
		ft_putstr(ft_itoa(nbr));
		return (0);
	}
}