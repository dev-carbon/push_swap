/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:33:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/14 03:45:23 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_bonus.h"

int	is_valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc > 5)
		exit_prog(EXIT_FAILURE, "Too many argument.\n", NULL);
	if (!is_valid_options(argc, argv))
		exit_prog(EXIT_FAILURE, "Invalid option.\n", NULL);
	if (!is_valid_list(argc, argv))
		exit_prog(EXIT_FAILURE, "Invalid arguments.\n", NULL);
	return (1);
}
