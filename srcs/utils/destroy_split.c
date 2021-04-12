/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:32:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/12 22:34:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	destroy_split(char **split)
{
	int		i;

	if (split != NULL)
	{
		i = -1;
		while (split[++i])
		{
			free(split[i]);
			split[i] = NULL;
		}
		free(split);
		split = NULL;
	}
}
