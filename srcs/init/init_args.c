/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:35:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 12:36:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_args	*init_args(t_args *args, int argc, char **argv)
{
	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	args->ac = argc - 1;
	args->av = argv;
	return (args);
}
