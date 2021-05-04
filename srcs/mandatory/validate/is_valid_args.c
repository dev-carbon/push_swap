/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:33:51 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 23:05:18 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	is_valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc > 2)
		exit_prog(EXIT_FAILURE, "Too many arguments.\n", NULL);
	if (!is_valid_list(argc, argv))
		exit_prog(EXIT_FAILURE, "Invalid arguments.\n", NULL);
	return (1);
}
