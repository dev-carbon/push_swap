/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:37:18 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 13:41:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	exit_prog(int status)
{
	if (status == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDOUT_FILENO);
	if (status == EXIT_SUCCESS)
		ft_putstr_fd("Bye!\n", STDOUT_FILENO);
	exit(status);
	return (0);
}
